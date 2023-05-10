#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <QDebug>
#include <QVector>

#define ERROR       0
#define SUCCESS     1
#define NOT_AUTHO   2

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server();
    QTcpSocket *socket;

private:
    QVector <QTcpSocket*> sockets;
    QByteArray data;
    QSqlDatabase db;
    QString login = "";
    QSqlQuery *query;
    void sendToClient(QString message, QString login);
    void sendAuthorizationResult(int result);
    int loginPassChecker(QString login, QString pass);

private slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotAuthorization();
    void slotReadyRead();
};

#endif // SERVER_H
