#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QAbstractSocket>
#include <QTcpSocket>
namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = 0);
    ~client();
    void send_to_server();

private slots:
    void on_pushButton_clicked();
    void slotConnected();
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError);
    void onDisconnected();
private:
    Ui::client *ui;
    QTcpSocket *socket;
};

#endif // CLIENT_H
