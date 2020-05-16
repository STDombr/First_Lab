#ifndef SETDATEANDTIME_H
#define SETDATEANDTIME_H

#include <QMainWindow>

namespace Ui {
class SetDateAndTime;
}

class SetDateAndTime : public QMainWindow
{
    Q_OBJECT

public:
    explicit SetDateAndTime(QWidget *parent = nullptr);
    ~SetDateAndTime();

private slots:
    void on_set_clicked();

signals:
    void signalDate(QDateTime temp);

private:
    Ui::SetDateAndTime *ui;
};

#endif // SETDATEANDTIME_H
