 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLineEdit>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<iostream>
#include<QStandardItemModel>
#include<QListView>
#include<booksitem.h>
#include<QListWidget>
#include<personinfor.h>
#include<QAbstractItemView>
#include<orderisok.h>
#include<historyorder.h>
#include<QRegExpValidator>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void receivelogin(QString str,QString str1);

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();


    
signals:
    void showPersonalInfor(QString str);

private:
    Ui::MainWindow *ui;
    void display();
    QString account;
    QSqlDatabase getConn();
    QStandardItemModel *model=new QStandardItemModel();
    QStandardItemModel *model1=new QStandardItemModel();
    void setTableView();
    OrderIsOk order;
    QSqlDatabase database;
    QString name;
    HistoryOrder history;
    void refresh();
     PersonInfor pi;

};

#endif // MAINWINDOW_H
