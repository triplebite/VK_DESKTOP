#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chatroom.h"
#include <QTcpSocket>
#include <QMessageBox>

#define ERROR       0
#define SUCCESS     1
#define NOT_AUTHO   2

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray data;
    Chatroom chatRoom;
    QString login = "";
    void sendToServer(QString login, QString pass);

public slots:
    void slotReadyRead();

signals:
    void sendSocket(QTcpSocket *socket);
    void sendLogin(QString login);
};
#endif // MAINWINDOW_H
