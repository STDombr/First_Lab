#include "addelement.h"
#include "ui_addelement.h"
#include <QMessageBox>
#include <sstream>
#include <iostream>

extern int radio;

AddElement::AddElement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddElement)
{
    ui->setupUi(this);
}

AddElement::~AddElement()
{
    delete ui;
}

void AddElement::on_set_clicked()
{
    std::string temp = ui->lineEdit->text().toStdString();
    if (radio==1)
    {
        if (is_int(temp))
        {

            emit signalElement(ui->lineEdit->text());
            this->close();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Invalid data!");
            msgBox.exec();
        }
    }
    else if (radio==2)
    {
        if (is_double(temp))
        {
            emit signalElement(ui->lineEdit->text());
            this->close();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Invalid data!");
            msgBox.exec();
        }
    }
    else if (radio==3)
    {
        if (temp == "")
        {
            QMessageBox msgBox;
            msgBox.setText("Invalid data!");
            msgBox.exec();
        }
        else
        {
            emit signalElement(ui->lineEdit->text());
            this->close();
        }
    }
}

bool is_int(std::string temp)
{
    if (temp == "")
        return 0;
    int len = temp.size();
    for (int i=0;i<len;i++)
        if (!isdigit(temp[i]))
            return 0;
    return 1;
}

bool is_double(std::string in)
{
    std::istringstream iss(in);
    double f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}
