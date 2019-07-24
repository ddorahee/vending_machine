#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    if(money<=0){
        setfalse();
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::setfalse(){
    ui->PBCOFFE->setEnabled(false);
    ui->PBTEA->setEnabled(false);
    ui->PBCOLA->setEnabled(false);
}

void Widget::changeMoney(int n)
{
    money += n;

    ui->lcdNumber->display(money);

    if(money <100){
        ui->PBCOFFE->setEnabled(false);
    }
    if(money <150){
        ui->PBTEA->setEnabled(false);
    }
    if(money <200){
        ui->PBCOLA->setEnabled(false);
    }
    if(money >100){
        ui->PBCOFFE->setEnabled(true);
    }
    if(money >150){
        ui->PBTEA->setEnabled(true);
    }
    if(money >200){
        ui->PBCOLA->setEnabled(true);
    }
}

void Widget::on_PB10_clicked()
{
    changeMoney(10);
}

void Widget::on_PB50_clicked()
{
    changeMoney(50);
}

void Widget::on_PB100_clicked()
{
    changeMoney(100);
}

void Widget::on_PB500_clicked()
{
    changeMoney(500);
}

void Widget::on_PBCOFFE_clicked()
{
    changeMoney(-100);
}

void Widget::on_PBTEA_clicked()
{
    changeMoney(-150);
}

void Widget::on_PBCOLA_clicked()
{
    changeMoney(-200);
}

void Widget::on_PBRESET_clicked()
{
    oback = money / 500;
    back = money % 500 / 100;
    osib = money % 500 % 100 / 50;
    sib = money % 500 % 100 % 50 /10;

    QMessageBox msg;
    QString m1 = ("RESET !!!");
    QString m2 = QStringLiteral("500won=%1\n100won=%2\n50won=%3\n10won=%4\n").arg(oback).arg(back).arg(osib).arg(sib);
    msg.information(nullptr,m1,m2);
    ui->lcdNumber->display(0);
    setfalse();
    money = 0;
}
