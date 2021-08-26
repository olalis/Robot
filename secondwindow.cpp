#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QDateTime>

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    this->discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(this->discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(captureDeviceProperties(QBluetoothDeviceInfo)));
    connect(this->discoveryAgent, SIGNAL(finished()),this, SLOT(searchingFinished()));

    // dezaktywowanie przycisków
    ui->pushButtonConnect->setEnabled(false);
    ui->pushButtonDisconnect->setEnabled(false);

    this->socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);
    connect(this->socket, SIGNAL(connected()),this, SLOT(connectionEstablished()));
    connect(this->socket, SIGNAL(disconnected()),this, SLOT(connectionInterrupted()));
    connect(this->socket, SIGNAL(readyRead()),this, SLOT(socketReadyToRead()));

    choosemode = new ChooseMode(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButtonSearch_clicked()
{
    ui->comboBoxDevices->clear();
    ui->pushButtonSearch->setEnabled(false);
    ui->pushButtonConnect->setEnabled(true);
    this->discoveryAgent->start(); // rozpoczęcie wyszukiwania
    this->addToLogs("Rozpoczęto wyszukiwanie urządzeń.");
}

void SecondWindow::captureDeviceProperties(const QBluetoothDeviceInfo &device)
{
    ui->comboBoxDevices->addItem(device.name() + " " + device.address().toString());
    this->addToLogs("Znaleziono urządzenie o nazwie: " + device.name() + " i adresie: " + device.address().toString());
}

void SecondWindow::searchingFinished()
{
    ui->pushButtonSearch->setEnabled(true);
    this->addToLogs("Wyszukiwanie zakończone.");

}

void SecondWindow::addToLogs(QString message)
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    ui->textEdit->append(currentDateTime + "\t" + message);
}

void SecondWindow::sendMessageToDevice(QString message)
{
    if(this->socket->isOpen() && this->socket->isWritable()) {
        this->addToLogs("Wysyłam informacje do urządzenia " + message);
        this->socket->write(message.toStdString().c_str());
      } else {
        this->addToLogs("Nie mogę wysłać wiadomości. Połączenie nie zostało ustanowione!");
    }
}


void SecondWindow::on_pushButtonConnect_clicked()
{
    this->addToLogs("Iniciuję próbę połączenia...");
    QString comboBoxQString = ui->comboBoxDevices->currentText();
    QStringList portList = comboBoxQString.split(" ");
    QString deviceAddres = portList.last();

    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    this->socket->connectToService(QBluetoothAddress(deviceAddres),QBluetoothUuid(serviceUuid),QIODevice::ReadWrite);
    this->addToLogs("Rozpoczęto łączenie z urządzeniem o nazwie: " + portList.first() + " i adresie: " + deviceAddres);

}


void SecondWindow::on_pushButtonDisconnect_clicked()
{
    this->addToLogs("Zamykam połączenie.");
    this->socket->disconnectFromService();
}

void SecondWindow::connectionEstablished() {
    this->addToLogs("Połączenie ustanowione.");
    ui->pushButtonConnect->setEnabled(false);
    ui->pushButtonDisconnect->setEnabled(true);

}

void SecondWindow::connectionInterrupted() {
    this->addToLogs("Połączenie przerwane.");
}

void SecondWindow::socketReadyToRead() {
    while(this->socket->canReadLine()) {
        QString line = this->socket->readLine();
        //qDebug() << line;

        QString terminator = "\r";
        int pos = line.lastIndexOf(terminator);
        //qDebug() << line.left(pos);

        this->addToLogs(line.left(pos));
      }
}

void SecondWindow::on_pushButtonClose_clicked()
{
    if (ui->pushButtonDisconnect->isEnabled()){
        this->addToLogs("Zamykam połączenie.");
        this->socket->disconnectFromService();
    }
    this->close();
}


void SecondWindow::on_pushButton_clicked()
{
    this->hide();
    choosemode->show();
}

