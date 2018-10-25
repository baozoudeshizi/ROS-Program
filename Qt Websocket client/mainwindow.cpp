#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QUrl url = QUrl("ws://192.168.134.123:9090");
    ui->label->setText(QStringLiteral("未连接!"));
    m_websocket.open(url);
    qDebug()<<m_websocket.errorString();
    connect(&m_websocket,SIGNAL(connected()),this,SLOT(onconnected()));
    connect(&m_websocket,SIGNAL(disconnected()),this,SLOT(ondisconnected()));
//    connect(&m_websocket,SIGNAL(disconnected()),this,SLOT(closeConnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString msg = ui->textEdit->document()->toPlainText();
    m_websocket.sendTextMessage(msg);
}

void MainWindow::onconnected()
{
    ui->label->setText(QStringLiteral("连接成功!"));
}

void MainWindow::ondisconnected()
{
    ui->label->setText(QStringLiteral("未连接!"));
}
