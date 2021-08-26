#include "firstwindow.h"
#include "ui_firstwindow.h"

FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
    secoundWindow = new SecondWindow();
}

FirstWindow::~FirstWindow()
{
    delete ui;
}


void FirstWindow::on_pushButtonStart_clicked()
{
    secoundWindow -> show();
    this -> close();
}

