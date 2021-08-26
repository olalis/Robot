#ifndef MANUALMODE_H
#define MANUALMODE_H

#include <QMainWindow>

namespace Ui {
class ManualMode;
}

class ManualMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManualMode(QWidget *parent = nullptr);
    ~ManualMode();

private slots:
    void on_pushButtonComeBack_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::ManualMode *ui;
};

#endif // MANUALMODE_H
