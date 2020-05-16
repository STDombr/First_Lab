#ifndef ADDELEMENT_H
#define ADDELEMENT_H

#include <QMainWindow>

namespace Ui {
class AddElement;
}

class AddElement : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddElement(QWidget *parent = nullptr);
    ~AddElement();

private slots:
    void on_set_clicked();

private:
    Ui::AddElement *ui;

signals:
    void signalElement(QString temp);
};

bool is_int(std::string temp);
bool is_double(std::string in);

#endif // ADDELEMENT_H
