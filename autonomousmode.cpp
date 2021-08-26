#include "autonomousmode.h"
#include "ui_autonomousmode.h"

AutonomousMode::AutonomousMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AutonomousMode)
{
    ui->setupUi(this);
}

AutonomousMode::~AutonomousMode()
{
    delete ui;
}

void AutonomousMode::on_pushButtonComeBack_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void AutonomousMode::on_pushButtonClose_clicked()
{
    this->close();
}

