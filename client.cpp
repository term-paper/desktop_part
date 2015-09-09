#include "client.h"
#include "ui_client.h"
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QDateTime>
#include "class_with_info.h"
client::client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
}

client::~client()
{
    delete ui;

}

void client::on_pushButton_clicked()
{
    socket=new QTcpSocket();
    socket->connectToHost("localhost",80);

    connect(socket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(socket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this,         SLOT(slotError(QAbstractSocket::SocketError)));
    connect (socket,SIGNAL(disconnected()),SLOT(onDisconnected()));

    if(socket->waitForConnected())
    {
        send_to_server();
    }
    else
    {
        qDebug()<<"connecting error";
    }
}

void client::slotConnected()
{
    qDebug()<<"я клиент и я подключился";
}

void client::slotReadyRead()
{
    qDebug()<<"я клиент и я получил данные из сокета"<<socket->readAll();
}

void client::slotError(QAbstractSocket::SocketError)
{

}

void client::onDisconnected()
{
    qDebug()<<"я клиент и я отключился";
}

void client::send_to_server()
{
    class_with_info info;
    info.set_info(317,45.3);
    info.print();

    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::ReadWrite);
    //out.setVersion(QDataStream::Qt_5_4);

    //out<<"HTTP/ 1.1 200 OK \r\n\r\n";


    info.Serialize(&out);//!
    //qDebug()<<arrBlock.toHex();
    //out.device()->seek(0);//!
    //out << quint16(arrBlock.size() - sizeof(quint16));//!

    socket->write(arrBlock);
    //socket->write("сообщение для сервера");
    socket->disconnectFromHost();
    //socket->waitForDisconnected();

}
