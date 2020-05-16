#include "settime.h"
#include "ui_settime.h"

/**
      *This constructor created window to set time
      */
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
/**
   *Set Time when the button is clicked
   */
void SetTime::on_set_clicked()
{
    emit signalTime(ui->timeEdit->time());
    this->close();
}
