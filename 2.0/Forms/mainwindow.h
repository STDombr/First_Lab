#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include "List.h"
#include "Interface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void set_date();
    void get_new(QDateTime temp);
    void get_plus(QTime temp);
    void get_minus(QTime temp);
    void add_list();
    void add_element(QString temp);
    void add_date(QDateTime temp);
private slots:
    void on_Date_Yet_clicked();
    void on_Date_Random_clicked();
    void on_Date_New_clicked();
    void on_Date_Minus_clicked();
    void on_Date_Plus_clicked();
    void on_List_Random_clicked();
    void on_Radio_Int_clicked();
    void on_Radio_Double_clicked();
    void on_Radio_String_clicked();
    void on_Radio_Date_clicked();
    void on_List_Pop_Head_clicked();
    void on_List_Pop_Tail_clicked();
    void on_List_Delete_clicked();
    void on_List_Sort_clicked();
    void on_List_Add_clicked();
};

#endif // MAINWINDOW_H
