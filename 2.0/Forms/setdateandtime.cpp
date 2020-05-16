#include "setdateandtime.h"
#include "ui_setdateandtime.h"

SetDateAndTime::SetDateAndTime(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetDateAndTime)
{
    ui->setupUi(this);
}

SetDateAndTime::~SetDateAndTime()
{
    delete ui;
}

void SetDateAndTime::on_set_clicked()
{
    emit signalDate(ui->dateTimeEdit->dateTime());
    this->close();
}
