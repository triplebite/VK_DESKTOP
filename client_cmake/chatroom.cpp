#include "chatroom.h"
#include "ui_chatroom.h"
#include <QLabel>

Chatroom::Chatroom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chatroom)
{
    ui->setupUi(this);
}

Chatroom::~Chatroom()
{
    delete ui;
}

void Chatroom::sendToServer(QString message)
{
    if (message != ""){
        data.clear();
        QDataStream out(&data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_4);
        out << login << message;
        socket->write(data);
        ui->lineEdit->clear();
    }
}

void Chatroom::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if (in.status() == QDataStream::Ok){
        QString message;
        QString login;
        in >> login >> message;
        qDebug() << login << message;

        ui->textBrowser->append("");
        ui->textBrowser->append(QTime::currentTime().toString());
        QString allMessage = "<b><font color=\"red\">" + login + "</font></b>" + ": " + message;
        ui->textBrowser->append(allMessage);
    }
    else{
        qDebug("DataStream error on server");
    }
}


void Chatroom::slotSetSocket(QTcpSocket *_socket)
{
    socket = _socket;
    connect(socket, &QTcpSocket::readyRead, this, &Chatroom::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
}

void Chatroom::slotSetLogin(QString _login)
{
    login = _login;
    qDebug() << login;
}

void Chatroom::on_pushButton_clicked()
{
    if (ui->lineEdit->text() != "")
        sendToServer(ui->lineEdit->text());
}

void Chatroom::on_lineEdit_returnPressed()
{
    if (ui->lineEdit->text() != "")
        sendToServer(ui->lineEdit->text());
}

