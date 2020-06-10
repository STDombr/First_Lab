#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include "List.h"
#include "Array.h"
#include "Vector.h"
#include "Interface.h"

namespace Ui {
class MainWindow;
}

/**
  *The MainWindow is the main form from which you can choose the main functions
  */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
          *This constructor created the main window
          */
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    /**
       *Function to set new date in window
       */
    void set_date();
    /**
       *Function to get new date from signals
       */
    void get_new(QDateTime temp);
    /**
       *Function to get new date from signals
       */
    void get_plus(QTime temp);
    /**
       *Function to get new date from signals
       */
    void get_minus(QTime temp);

    template<typename T>
    void pop_tail(Interface<T> *temp);
    /**
       *Function to add elements to List
       */
    template<typename T>
    void add_list(Interface<T> *temp);
    /**
       *Function to add new element
       */
    void connect_element(QString temp);
    /**
       *Function to add new date
       */
    void connect_date(QDateTime temp);
private slots:
    /**
       *Set yet date when the button is clicked
       */
    void on_Date_Yet_clicked();
    /**
       *Set random date when the button is clicked
       */
    void on_Date_Random_clicked();
    /**
       *Set new date when the button is clicked
       */
    void on_Date_New_clicked();
    /**
       *Open window to set second time when the button is clicked
       */
    void on_Date_Minus_clicked();
    /**
       *Open window to set second time when the button is clicked
       */
    void on_Date_Plus_clicked();
    /**
       *Set random list when the button is clicked
       */
    void on_List_Random_clicked();
    /**
       *Set Int in radio when the button is clicked
       */
    void on_Radio_Int_clicked();
    /**
       *Set Double in radio when the button is clicked
       */
    void on_Radio_Double_clicked();
    /**
       *Set String in radio when the button is clicked
       */
    void on_Radio_String_clicked();
    /**
       *Set Date and Time in radio when the button is clicked
       */
    void on_Radio_Date_clicked();
    /**
       *Delete first element when the button is clicked
       */
    void on_List_Pop_Head_clicked();
    /**
       *Delete last element when the button is clicked
       */
    void on_List_Pop_Tail_clicked();
    /**
       *Delete all elements when the button is clicked
       */
    void on_List_Delete_clicked();
    /**
       *Sort elements on List when the button is clicked
       */
    void on_List_Sort_clicked();
    /**
       *Open window to set new element when the button is clicked
       */
    void on_List_Add_clicked();
    void on_Radio_List_clicked();
    void on_Radio_Array_clicked();
    void on_Radio_Vector_clicked();
};

#endif // MAINWINDOW_H
