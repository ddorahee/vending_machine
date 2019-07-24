#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void changeMoney(int n);
    void setfalse();
    int sib {0};
    int osib {0};
    int back {0};
    int oback {0};
    int money {0};


private slots:
    void on_PB10_clicked();

    void on_PB50_clicked();

    void on_PB100_clicked();

    void on_PB500_clicked();

    void on_PBCOFFE_clicked();

    void on_PBTEA_clicked();

    void on_PBCOLA_clicked();

    void on_PBRESET_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
