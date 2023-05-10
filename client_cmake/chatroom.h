#ifndef CHATROOM_H
#define CHATROOM_H

#include <QWidget>
#include <QTcpSocket>
#include <QTime>

namespace Ui {
class Chatroom;
}

class Chatroom : public QWidget
{
    Q_OBJECT

public:
    explicit Chatroom(QWidget *parent = nullptr);
    ~Chatroom();

private:
    Ui::Chatroom *ui;
    QTcpSocket *socket;
    QByteArray data;
    QString login = "";
    void sendToServer(QString message);

public slots:
    void slotReadyRead();

private slots:
    void on_pushButton_clicked();
    void slotSetSocket(QTcpSocket *_socket);
    void slotSetLogin(QString _login);
    void on_lineEdit_returnPressed();
};

#endif // CHATROOM_H
