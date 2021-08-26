#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>

#include <choosemode.h>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

    void addToLogs(QString message);
    QBluetoothSocket *socket;
    void sendMessageToDevice(QString message);

private slots:
    void on_pushButtonSearch_clicked();
    void captureDeviceProperties(const QBluetoothDeviceInfo &device);
    void searchingFinished();

    void on_pushButtonConnect_clicked();

    void on_pushButtonDisconnect_clicked();

    void connectionEstablished();
    void connectionInterrupted();
    void socketReadyToRead();

    void on_pushButtonClose_clicked();

    void on_pushButton_clicked();

private:
    Ui::SecondWindow *ui; 
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
//    void addToLogs(QString message);
//    QBluetoothSocket *socket;
//    void sendMessageToDevice(QString message);

    ChooseMode *choosemode;
};

#endif // SECONDWINDOW_H
