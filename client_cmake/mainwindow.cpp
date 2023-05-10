#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    connect(this, SIGNAL(sendSocket(QTcpSocket*)), &chatRoom, SLOT(slotSetSocket(QTcpSocket*)));
    connect(this, SIGNAL(sendLogin(QString)), &chatRoom, SLOT(slotSetLogin(QString)));
    socket->connectToHost("127.0.0.1", 2323);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    login = ui->lineEdit->text();
    sendToServer(login, ui->lineEdit_2->text());
}

void MainWindow::sendToServer(QString login, QString pass)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << login << pass;
    socket->write(data);
}

void MainWindow::slotReadyRead()
{
    socket =(QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if (in.status() == QDataStream::Ok){
        qDebug("read...");
        int result;
        in >> result;
        qDebug() << result << " from server";
        if (result == SUCCESS){
            emit sendSocket(socket);
            disconnect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
            this->hide();
            emit sendLogin(login);
            chatRoom.show();
        }
        else if (result == ERROR){
            QMessageBox msgBox(QMessageBox::Information, "Ошибка входа", "Неправильно введен логин или пароль.");
            msgBox.exec();
        }
        else{
            QMessageBox msgBox(QMessageBox::Information, "Регистрация", "Введенного логина не было в базе данных. Теперь он зарегестрирован с введенным паролем.");
            msgBox.exec();
        }
    }
    else{
        qDebug("DataStream error on client");
    }
}
