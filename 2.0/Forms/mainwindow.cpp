#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QDate>
#include "Date_and_Time.h"
#include <QString>
#include "setdateandtime.h"
#include "addelement.h"
#include "settime.h"

int radio_link = 1;
int radio_data = 1;


int temp1;
double temp2;
std::string temp3;
Date_and_Time DT,DT2,temp4;


template<typename T>
Interface<T> *I;

/**
      *This constructor created the main window
      */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Radio_List->click();
    ui->Radio_Int->click();
    set_date();
}

MainWindow::~MainWindow()
{
    delete ui;
}
/**
   *Function to set new date in window
   */
void MainWindow::set_date()
{
    std::string tempTime = std::to_string(DT.T.get_hour()) + ":" + std::to_string(DT.T.get_minute()) + ":" + std::to_string(DT.T.get_second());
    std::string tempDate = std::to_string(DT.D.get_day()) + "." + std::to_string(DT.D.get_month()) + "." + std::to_string(DT.D.get_year());

    ui->Date->setText(QString::fromStdString(tempTime + " " + tempDate));
    ui->Weekday->setText(QString::fromStdString(DT.D.weekday()));
    ui->Num_of_week->setNum(DT.D.num_of_week_at_year());
}
/**
   *Set yet date when the button is clicked
   */
void MainWindow::on_Date_Yet_clicked()
{
    DT.yet_time_and_date();
    set_date();
}
extern List<double> L1;
extern Array<double> L2;
extern Vector<double> L3;
/**
   *Set random date when the button is clicked
   */
void MainWindow::on_Date_Random_clicked()
{
    DT.random();
    set_date();
}
/**
   *Set new date when the button is clicked
   */
void MainWindow::on_Date_New_clicked()
{
    SetDateAndTime *SDT = new SetDateAndTime(this);
    SDT->show();
    connect(SDT,&SetDateAndTime::signalDate,this,&MainWindow::get_new);
}
/**
   *Function to get new date from signals
   */
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
/**
   *Open window to set second time when the button is clicked
   */
void MainWindow::on_Date_Plus_clicked()
{
    SetTime *ST = new SetTime(this);
    ST->show();
    connect(ST,&SetTime::signalTime,this,&MainWindow::get_plus);
}
/**
   *Function to get new date from signals
   */
void MainWindow::get_plus(QTime temp)
{
    DIFF diff;
    diff.hours = temp.hour();
    diff.minutes = temp.minute();
    diff.seconds = temp.second();
    DT.plus_to_time(diff);
    set_date();
}
/**
   *Open window to set second time when the button is clicked
   */
void MainWindow::on_Date_Minus_clicked()
{
    SetTime *ST = new SetTime(this);
    ST->show();
    connect(ST,&SetTime::signalTime,this,&MainWindow::get_minus);
}
/**
   *Function to get new date from signals
   */
void MainWindow::get_minus(QTime temp)
{
    DIFF diff;
    diff.hours = temp.hour();
    diff.minutes = temp.minute();
    diff.seconds = temp.second();
    DT.minus_to_time(diff);
    set_date();
}
/**
   *Function to add elements to List
   */
template<typename T>
void MainWindow::add_list(Interface<T> *temp)
{
    ui->List->clear();
    for(int i=0;i<I<T>->GetSize();i++)
        ui->List->addItem(QString::fromStdString(temp->get_element(i)));
    ui->List->setCurrentRow(0);
}



template<typename T>
void set_random(Interface<T> *temp)
{
    temp->remove();
    temp->random();
}

/**
   *Set random list when the button is clicked
   */
void MainWindow::on_List_Random_clicked()
{
    if (radio_data == 1)
    {
        set_random(I<int>);
        add_list(I<int>);
    }
    else if (radio_data == 2)
    {
        set_random(I<double>);
        add_list(I<double>);
    }
    else if (radio_data == 3)
    {
        set_random(I<std::string>);
        add_list(I<std::string>);
    }
    else if (radio_data == 4)
    {
        set_random(I<Date_and_Time>);
        add_list(I<Date_and_Time>);
    }
    ui->List->setCurrentRow(0);
}

/**
   *Set Int in radio when the button is clicked
   */
void MainWindow::on_Radio_Int_clicked()
{
    ui->List->clear();
    if (radio_link == 1)
    {
        List<int> *temp = new List<int>;
        I<int> = temp;
    }
    else if (radio_link == 2)
    {
        Array<int> *temp = new Array<int>;
        I<int> = temp;
    }
    else if (radio_link == 3)
    {
        Vector<int> *temp = new Vector<int>;
        I<int> = temp;
    }
    radio_data = 1;
}
/**
   *Set Double in radio when the button is clicked
   */
void MainWindow::on_Radio_Double_clicked()
{
    ui->List->clear();
    if (radio_link == 1)
    {
        L1.remove();
        I<double> = &L1;
    }
    else if (radio_link == 2)
    {
        L2.remove();
        I<double> = &L2;
    }
    else if (radio_link == 3)
    {
        L3.remove();
        I<double> = &L3;
    }
    radio_data = 2;
}
/**
   *Set String in radio when the button is clicked
   */
void MainWindow::on_Radio_String_clicked()
{
    ui->List->clear();
    if (radio_link == 1)
    {
        List<std::string> *temp = new List<std::string>;
        I<std::string> = temp;
    }
    else if (radio_link == 2)
    {
        Array<std::string> *temp = new Array<std::string>;
        I<std::string> = temp;
    }
    else if (radio_link == 3)
    {
        Vector<std::string> *temp = new Vector<std::string>;
        I<std::string> = temp;
    }
    radio_data = 3;
}
/**
   *Set Date and Time in radio when the button is clicked
   */
void MainWindow::on_Radio_Date_clicked()
{
    ui->List->clear();
    if (radio_link == 1)
    {
        List<Date_and_Time> *temp = new List<Date_and_Time>;
        I<Date_and_Time> = temp;
    }
    else if (radio_link == 2)
    {
        Array<Date_and_Time> *temp = new Array<Date_and_Time>;
        I<Date_and_Time> = temp;
    }
    else if (radio_link == 3)
    {
        Vector<Date_and_Time> *temp = new Vector<Date_and_Time>;
        I<Date_and_Time> = temp;
    }
    radio_data = 4;
}

/**
   *Delete all elements when the button is clicked
   */
void MainWindow::on_List_Delete_clicked()
{
    ui->List->clear();
    if (radio_data == 1)
        I<int>->remove();
    else if (radio_data == 2)
        I<double>->remove();
    else if (radio_data == 3)
        I<std::string>->remove();
    else if (radio_data == 4)
        I<Date_and_Time>->remove();
}

/**
   *Delete first element when the button is clicked
   */
void MainWindow::on_List_Pop_Head_clicked()
{
    delete ui->List->takeItem(0);
    if (radio_data == 1)
        I<int>->popHead();
    else if (radio_data == 2)
        I<double>->popHead();
    else if (radio_data == 3)
        I<std::string>->popHead();
    else if (radio_data == 4)
        I<Date_and_Time>->popHead();
}

template<typename T>
void MainWindow::pop_tail(Interface<T> *temp)
{
    delete ui->List->takeItem(I<T>->GetSize()-1);
    temp->popTail();
}

/**
   *Delete last element when the button is clicked
   */
void MainWindow::on_List_Pop_Tail_clicked()
{
    if (radio_data == 1)
        pop_tail(I<int>);
    else if (radio_data == 2)
        pop_tail(I<double>);
    else if (radio_data == 3)
        pop_tail(I<std::string>);
    else if (radio_data == 4)
        pop_tail(I<Date_and_Time>);
}

template<typename T>
void sort(Interface<T> *temp)
{
    temp->heapsort();
}

/**
   *Sort elements on List when the button is clicked
   */
void MainWindow::on_List_Sort_clicked()
{
    if (radio_data == 1)
    {
        sort(I<int>);
        add_list(I<int>);
    }
    else if (radio_data == 2)
    {
        sort(I<double>);
        add_list(I<double>);
    }
    else if (radio_data == 3)
    {
        sort(I<std::string>);
        add_list(I<std::string>);
    }
    else if (radio_data == 4)
    {
        sort(I<Date_and_Time>);
        add_list(I<Date_and_Time>);
    }
}
/**
   *Open window to set new element when the button is clicked
   */
void MainWindow::on_List_Add_clicked()
{
    if (radio_data==4)
    {
        SetDateAndTime *SDT = new SetDateAndTime(this);
        SDT->show();
        connect(SDT,&SetDateAndTime::signalDate,this,&MainWindow::connect_date);
    }
    else
    {
        AddElement *AE = new AddElement(this);
        AE->show();
        connect(AE,&AddElement::signalElement,this,&MainWindow::connect_element);
    }
}

/**
   *Function to add new element
   */
void MainWindow::connect_element(QString temp)
{
    if (radio_data == 1)
        I<int>->add(temp.toInt());
    else if (radio_data == 2)
        I<double>->add(temp.toDouble());
    else if (radio_data == 3)
        I<std::string>->add(temp.toStdString());
    ui->List->addItem(temp);
}

/**
   *Function to add new date
   */
void MainWindow::connect_date(QDateTime temp)
{
    Date_and_Time d;
    std::string tempTime, tempDate;
    d.D.set_year(temp.date().year());
    d.D.set_day(temp.date().day());
    d.D.set_month(temp.date().month());
    d.T.set_hour(temp.time().hour());
    d.T.set_minute(temp.time().minute());
    d.T.set_second(temp.time().second());
    I<Date_and_Time>->add(d);
    tempTime = std::to_string(d.T.get_hour()) + ":" + std::to_string(d.T.get_minute()) + ":" + std::to_string(d.T.get_second());
    tempDate = std::to_string(d.D.get_day()) + "." + std::to_string(d.D.get_month()) + "." + std::to_string(d.D.get_year());
    ui->List->addItem(QString::fromStdString(tempTime + " " + tempDate));
}

void MainWindow::on_Radio_List_clicked()
{
    ui->List->clear();
    if (radio_data == 1)
    {
        List<int> *temp = new List<int>;
        I<int> = temp;
    }
    else if (radio_data == 2)
    {
        L1.remove();
        I<double> = &L1;
    }
    else if (radio_data == 3)
    {
        List<std::string> *temp = new List<std::string>;
        I<std::string> = temp;
    }
    else if (radio_data == 4)
    {
        List<Date_and_Time> *temp = new List<Date_and_Time>;
        I<Date_and_Time> = temp;
    }
    radio_link = 1;
}

void MainWindow::on_Radio_Array_clicked()
{
    ui->List->clear();
    if (radio_data == 1)
    {
        Array<int> *temp = new Array<int>;
        I<int> = temp;
    }
    else if (radio_data == 2)
    {
        L2.remove();
        I<double> = &L2;
    }
    else if (radio_data == 3)
    {
        Array<std::string> *temp = new Array<std::string>;
        I<std::string> = temp;
    }
    else if (radio_data == 4)
    {
        Array<Date_and_Time> *temp = new Array<Date_and_Time>;
        I<Date_and_Time> = temp;
    }
    radio_link = 2;
}

void MainWindow::on_Radio_Vector_clicked()
{
    ui->List->clear();
    if (radio_data == 1)
    {
        Vector<int> *temp = new Vector<int>;
        I<int> = temp;
    }
    else if (radio_data == 2)
    {
        L3.remove();
        I<double> = &L3;
    }
    else if (radio_data == 3)
    {
        Vector<std::string> *temp = new Vector<std::string>;
        I<std::string> = temp;
    }
    else if (radio_data == 4)
    {
        Vector<Date_and_Time> *temp = new Vector<Date_and_Time>;
        I<Date_and_Time> = temp;
    }
    radio_link = 1;
}
