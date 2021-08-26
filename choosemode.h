#ifndef CHOOSEMODE_H
#define CHOOSEMODE_H

#include <QMainWindow>
#include <autonomousmode.h>
#include <manualmode.h>

namespace Ui {
class ChooseMode;
}

class ChooseMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseMode(QWidget *parent = nullptr);
    ~ChooseMode();

private slots:
    void on_pushButtonManualMode_clicked();

    void on_pushButtonAutonomousMode_clicked();

    void on_pushButtonComeBack_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::ChooseMode *ui;
    ManualMode *manualmode;
    AutonomousMode *autonomousemode;
};

#endif // CHOOSEMODE_H
