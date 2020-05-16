#ifndef SETTIME_H
#define SETTIME_H

#include <QMainWindow>

namespace Ui {
class SetTime;
}

class SetTime : public QMainWindow
{
    Q_OBJECT

public:
    explicit SetTime(QWidget *parent = nullptr);
    ~SetTime();

private slots:
    void on_set_clicked();

signals:
    void signalTime(QTime temp);

private:
    Ui::SetTime *ui;
};

#endif // SETTIME_H
