#include "server.h"

Server::Server()
{
    if (this->listen(QHostAddress::Any, 2323)) qDebug("Start");
    else qDebug("Error");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./DB.db");

    if (! db.open()) qDebug("db error");

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Users(login TEXT, password TEXT);");
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotAuthorization);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    sockets.push_back(socket);
    qDebug() << socketDescriptor << "client connected";
}


int Server::loginPassChecker(QString login, QString pass)
{

    query->prepare("SELECT password FROM Users WHERE login = :login");
    query->bindValue(":login", login);

    if (query->exec() && query->next()) {
        QString password = query->value(0).toString();
        qDebug() << password << login << pass << "in checker";
        if (pass == password) return SUCCESS;
        else return ERROR;
    }
    else
        return NOT_AUTHO;

    return -1;
}


void Server::slotAuthorization()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if (in.status() == QDataStream::Ok){
        qDebug("read... autho");
        QString pass;
        in >> login >> pass;
        qDebug() << login << pass;
        int res = loginPassChecker(login, pass);
        if (res == SUCCESS){
            qDebug() << "success autho" << login << pass;
            disconnect(socket, &QTcpSocket::readyRead, this, &Server::slotAuthorization);
            connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
            sendAuthorizationResult(res);
        }
        else if (res == ERROR){
            qDebug() << "error autho" << login << pass;
            sendAuthorizationResult(res);
        }
        else{
            qDebug() << "not_autho" << login << pass;
            sendAuthorizationResult(res);
            query->prepare("INSERT INTO Users (login, password) VALUES (:login, :password)");
            query->bindValue(":login", login);
            query->bindValue(":password", pass);
            query->exec();
        }
    }
    else{
        qDebug("DataStream error");
    }
}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if (in.status() == QDataStream::Ok){
        qDebug("read... ready");
        QString message;
        in >> login >> message;
        qDebug() << login << message;
        sendToClient(message, login);
    }
    else{
        qDebug("DataStream error");
    }
}

void Server::sendToClient(QString message, QString login)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << login << message;
    for (int i = 0; i < sockets.size(); i++)
        sockets[i]->write(data);
}

void Server::sendAuthorizationResult(int result)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << result;
    qDebug() << result;
    socket->write(data);
}
