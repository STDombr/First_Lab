#include "setdateandtime.h"
#include "ui_setdateandtime.h"

/**
      *This constructor created window to set date
      */
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
/**
   *Set Date and Time when the button is clicked
   */
void SetDateAndTime::on_set_clicked()
{
    emit signalDate(ui->dateTimeEdit->dateTime());
    this->close();
}
