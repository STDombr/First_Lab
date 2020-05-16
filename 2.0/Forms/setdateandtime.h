#ifndef SETDATEANDTIME_H
#define SETDATEANDTIME_H

#include <QMainWindow>

namespace Ui {
class SetDateAndTime;
}
/**
  *The SetDateAndTime is the form which you can set new date and time
  */
class SetDateAndTime : public QMainWindow
{
    Q_OBJECT

public:
    /**
          *This constructor created window to set date
          */
    explicit SetDateAndTime(QWidget *parent = nullptr);
    ~SetDateAndTime();

private slots:
    /**
       *Set Date and Time when the button is clicked
       */
    void on_set_clicked();

signals:
    void signalDate(QDateTime temp);

private:
    Ui::SetDateAndTime *ui;
};

#endif // SETDATEANDTIME_H
