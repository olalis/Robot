#include "choosemode.h"
#include "ui_choosemode.h"

ChooseMode::ChooseMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseMode)
{
    ui->setupUi(this);
    autonomousemode = new AutonomousMode(this);
    manualmode = new ManualMode(this);
}

ChooseMode::~ChooseMode()
{
    delete ui;
}

void ChooseMode::on_pushButtonManualMode_clicked()
{
    this->hide();
    manualmode->show();
}


void ChooseMode::on_pushButtonAutonomousMode_clicked()
{
    this->hide();
    autonomousemode->show();
}


void ChooseMode::on_pushButtonComeBack_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();

}


void ChooseMode::on_pushButtonClose_clicked()
{
    this->close();
}

