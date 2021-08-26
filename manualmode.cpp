#include "manualmode.h"
#include "ui_manualmode.h"

ManualMode::ManualMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManualMode)
{
    ui->setupUi(this);
}

ManualMode::~ManualMode()
{
    delete ui;
}

void ManualMode::on_pushButtonComeBack_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void ManualMode::on_pushButtonClose_clicked()
{
    this->close();
}

