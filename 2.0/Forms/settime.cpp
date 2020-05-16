#include "settime.h"
#include "ui_settime.h"

SetTime::SetTime(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetTime)
{
    ui->setupUi(this);
}

SetTime::~SetTime()
{
    delete ui;
}

void SetTime::on_set_clicked()
{
    emit signalTime(ui->timeEdit->time());
    this->close();
}
