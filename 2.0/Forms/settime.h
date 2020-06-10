#ifndef SETTIME_H
#define SETTIME_H

#include <QMainWindow>

namespace Ui {
class SetTime;
}
/**
  *The SetTime is the form which you can set time
  */
class SetTime : public QMainWindow
{
    Q_OBJECT

public:
    /**
          *This constructor created window to set time
          */
    explicit SetTime(QWidget *parent = nullptr);
    ~SetTime();

private slots:
    /**
       *Set Time when the button is clicked
       */
    void on_set_clicked();

signals:
    void signalTime(QTime temp);

private:
    Ui::SetTime *ui;
};

#endif // SETTIME_H
