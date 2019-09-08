#ifndef ORDERISOK_H
#define ORDERISOK_H

#include <QDialog>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QTime>
#include<iostream>
#include<QRegExpValidator>
namespace Ui {
class OrderIsOk;
}

class OrderIsOk : public QDialog
{
    Q_OBJECT

public:
    explicit OrderIsOk(QWidget *parent = nullptr);
    ~OrderIsOk();
    void setInfor(QString str1,QString str2,QString str3,QString str4,QString str5,QString str6);
    bool flag=false;
    QString getOrder(QString str);
    QString orderinfor;
    QString count;
    QString account,isbn;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();



private:
    Ui::OrderIsOk *ui;
    QDateTime dt;
    QTime time;
    QDate date;


};

#endif // ORDERISOK_H
