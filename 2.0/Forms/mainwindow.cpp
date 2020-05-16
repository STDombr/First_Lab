#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QDate>
#include "Date_and_Time.h"
#include <QString>
#include "setdateandtime.h"
#include "addelement.h"
#include "settime.h"

int radio = 1;
Date_and_Time DT,DT2;
extern List<int> ListInt;
extern List<double> ListDouble;
extern List<std::string> ListString;
extern List<Date_and_Time> ListDate;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Radio_Int->click();
    set_date();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_date()
{
    std::string tempTime = std::to_string(DT.T.get_hour()) + ":" + std::to_string(DT.T.get_minute()) + ":" + std::to_string(DT.T.get_second());
    std::string tempDate = std::to_string(DT.D.get_day()) + "." + std::to_string(DT.D.get_month()) + "." + std::to_string(DT.D.get_year());

    ui->Date->setText(QString::fromStdString(tempTime + " " + tempDate));
    ui->Weekday->setText(QString::fromStdString(DT.D.weekday()));
    ui->Num_of_week->setNum(DT.D.num_of_week_at_year());
}

void MainWindow::on_Date_Yet_clicked()
{
    DT.yet_time_and_date();
    set_date();
}

void MainWindow::on_Date_Random_clicked()
{
    DT.random();
    set_date();
}

void MainWindow::on_Date_New_clicked()
{
    SetDateAndTime *SDT = new SetDateAndTime(this);
    SDT->show();
    connect(SDT,&SetDateAndTime::signalDate,this,&MainWindow::get_new);
}

void MainWindow::get_new(QDateTime temp)
{
    DT2.D.set_year(temp.date().year());
    DT2.D.set_day(temp.date().day());
    DT2.D.set_month(temp.date().month());
    DT2.T.set_hour(temp.time().hour());
    DT2.T.set_minute(temp.time().minute());
    DT2.T.set_second(temp.time().second());
    DT = DT2;
    set_date();
}

void MainWindow::on_Date_Plus_clicked()
{
    SetTime *ST = new SetTime(this);
    ST->show();
    connect(ST,&SetTime::signalTime,this,&MainWindow::get_plus);
}

void MainWindow::get_plus(QTime temp)
{
    DIFF diff;
    diff.hours = temp.hour();
    diff.minutes = temp.minute();
    diff.seconds = temp.second();
    DT.plus_to_time(diff);
    set_date();
}

void MainWindow::on_Date_Minus_clicked()
{
    SetTime *ST = new SetTime(this);
    ST->show();
    connect(ST,&SetTime::signalTime,this,&MainWindow::get_minus);
}

void MainWindow::get_minus(QTime temp)
{
    DIFF diff;
    diff.hours = temp.hour();
    diff.minutes = temp.minute();
    diff.seconds = temp.second();
    DT.minus_to_time(diff);
    set_date();
}

void MainWindow::add_list()
{
    if (radio==1)
    {
        ui->List->clear();
        for(int i=0;i<ListInt.GetSize();i++)
            ui->List->addItem(QString::fromStdString(std::to_string(ListInt.get_element(i))));
    }
    else if (radio==2)
    {
        ui->List->clear();
        for(int i=0;i<ListDouble.GetSize();i++)
            ui->List->addItem(QString::fromStdString(std::to_string(ListDouble.get_element(i))));
    }
    else if (radio==3)
    {
        ui->List->clear();
        for(int i=0;i<ListString.GetSize();i++)
            ui->List->addItem(QString::fromStdString(ListString.get_element(i)));
    }
    else
    {
        ui->List->clear();
        std::string tempTime;
        std::string tempDate;
        Date_and_Time temp;
        for(int i=0;i<ListDate.GetSize();i++)
        {
            temp = ListDate.get_element(i);
            tempTime = std::to_string(temp.T.get_hour()) + ":" + std::to_string(temp.T.get_minute()) + ":" + std::to_string(temp.T.get_second());
            tempDate = std::to_string(temp.D.get_day()) + "." + std::to_string(temp.D.get_month()) + "." + std::to_string(temp.D.get_year());
            ui->List->addItem(QString::fromStdString(tempTime + " " + tempDate));
        }
    }

    ui->List->setCurrentRow(0);
}

void MainWindow::on_List_Random_clicked()
{
    if (radio==1)
    {
        ListInt.remove();
        ListInt.random();
    }
    else if (radio==2)
    {
        ListDouble.remove();
        ListDouble.random();
    }
    else if (radio==3)
    {
        ListString.remove();
        ListString.random();
    }
    else if (radio==4)
    {
        ListDate.remove();
        ListDate.random();
    }

    add_list();
    ui->List->setCurrentRow(0);
}


void MainWindow::on_Radio_Int_clicked()
{
    on_List_Delete_clicked();
    radio = 1;
}

void MainWindow::on_Radio_Double_clicked()
{
    on_List_Delete_clicked();
    radio = 2;
}

void MainWindow::on_Radio_String_clicked()
{
    on_List_Delete_clicked();
    radio = 3;
}

void MainWindow::on_Radio_Date_clicked()
{
    on_List_Delete_clicked();
    radio = 4;
}

void MainWindow::on_List_Delete_clicked()
{
    ui->List->clear();
    if (radio==1)
            ListInt.remove();
    else if (radio==2)
            ListDouble.remove();
    else if (radio==3)
            ListString.remove();
    else if (radio==4)
            ListDate.remove();
}

void MainWindow::on_List_Pop_Head_clicked()
{
    delete ui->List->takeItem(0);
    if (radio==1)
            ListInt.popHead();
    else if (radio==2)
            ListDouble.popHead();
    else if (radio==3)
            ListString.popHead();
    else if (radio==4)
            ListDate.popHead();
}

void MainWindow::on_List_Pop_Tail_clicked()
{
    if (radio==1)
    {
        delete ui->List->takeItem(ListInt.GetSize()-1);
        ListInt.popTail();
    }
    else if (radio==2)
    {
        delete ui->List->takeItem(ListDouble.GetSize()-1);
        ListDouble.popTail();
    }
    else if (radio==3)
    {
        delete ui->List->takeItem(ListString.GetSize()-1);
        ListString.popTail();
    }
    else
    {
            delete ui->List->takeItem(ListDate.GetSize()-1);
            ListDate.popTail();
    }
}

void MainWindow::on_List_Sort_clicked()
{
    if (radio==1)
            ListInt.heapsort();
    else if (radio==2)
            ListDouble.heapsort();
    else if (radio==3)
            ListString.heapsort();
    else if (radio==4)
            ListDate.heapsort();
    add_list();
}

void MainWindow::on_List_Add_clicked()
{
    if (radio==4)
    {
        SetDateAndTime *SDT = new SetDateAndTime(this);
        SDT->show();
        connect(SDT,&SetDateAndTime::signalDate,this,&MainWindow::add_date);
    }
    else
    {
        AddElement *AE = new AddElement(this);
        AE->show();
        connect(AE,&AddElement::signalElement,this,&MainWindow::add_element);
    }
}

void MainWindow::add_element(QString temp)
{
    if (radio==1)
    {
        ListInt.add(temp.toInt());
        ui->List->addItem(temp);
    }
    else if (radio==2)
    {
        ListDouble.add(temp.toDouble());
        ui->List->addItem(temp);
    }
    else if (radio==3)
    {
        ListString.add(temp.toStdString());
        ui->List->addItem(temp);
    }
}

void MainWindow::add_date(QDateTime temp)
{
    Date_and_Time d;
    std::string tempTime, tempDate;
    d.D.set_year(temp.date().year());
    d.D.set_day(temp.date().day());
    d.D.set_month(temp.date().month());
    d.T.set_hour(temp.time().hour());
    d.T.set_minute(temp.time().minute());
    d.T.set_second(temp.time().second());
    ListDate.add(d);
    tempTime = std::to_string(d.T.get_hour()) + ":" + std::to_string(d.T.get_minute()) + ":" + std::to_string(d.T.get_second());
    tempDate = std::to_string(d.D.get_day()) + "." + std::to_string(d.D.get_month()) + "." + std::to_string(d.D.get_year());
    ui->List->addItem(QString::fromStdString(tempTime + " " + tempDate));
}
