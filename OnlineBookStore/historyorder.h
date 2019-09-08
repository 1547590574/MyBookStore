#ifndef HISTORYORDER_H
#define HISTORYORDER_H

#include <QDialog>
#include<QStandardItemModel>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QTime>
#include<iostream>
namespace Ui {
class HistoryOrder;
}

class HistoryOrder : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryOrder(QWidget *parent = nullptr);
    ~HistoryOrder();
    void initUI(QString account);
    QSqlDatabase db;


private slots:
    void on_pushButton_clicked();

private:
    Ui::HistoryOrder *ui;
    QStandardItemModel *model=new QStandardItemModel();
    QDateTime dt;
    QTime time;
    QDate date;
    QString account;

};

#endif // HISTORYORDER_H
