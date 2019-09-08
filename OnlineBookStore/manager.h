#ifndef MANAGER_H
#define MANAGER_H

#include <QMainWindow>
#include<QStandardItemModel>
#include<QSqlDatabase>
#include<QSqlQuery>
#include"fillbookinfor.h"
#include<iostream>
#include<QInputDialog>
#include<QFile>
#include<QTextStream>
#include<QTextStream>
#include<QTime>
#include<QTableView>
#include<QScrollBar>
namespace Ui {
class Manager;
}

class Manager : public QMainWindow
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void receiveManager();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Manager *ui;
    QString GK;
     QStandardItemModel *model=new QStandardItemModel();
      QStandardItemModel *model1=new QStandardItemModel();
     void saveGK();
     void setTableView();
     void setTableData();
     void getCon();
     QSqlDatabase db;
     FillBookInfor bf;
     QInputDialog dia;
     void writeDiary(QString str);
     QDateTime dt;
     QTime time;
     QDate date;
       QScrollBar *bar=new QScrollBar();
};

#endif // MANAGER_H
