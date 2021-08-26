#ifndef AUTONOMOUSMODE_H
#define AUTONOMOUSMODE_H

#include <QMainWindow>

namespace Ui {
class AutonomousMode;
}

class AutonomousMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit AutonomousMode(QWidget *parent = nullptr);
    ~AutonomousMode();

private slots:
    void on_pushButtonComeBack_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::AutonomousMode *ui;
};

#endif // AUTONOMOUSMODE_H
