#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>
#include <secondwindow.h>


QT_BEGIN_NAMESPACE
namespace Ui { class FirstWindow; }
QT_END_NAMESPACE

class FirstWindow : public QMainWindow
{
    Q_OBJECT

public:
    FirstWindow(QWidget *parent = nullptr);
    ~FirstWindow();

private slots:

    void on_pushButtonStart_clicked();

private:
    Ui::FirstWindow *ui;
    SecondWindow *secoundWindow;

};
#endif // FIRSTWINDOW_H
