#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<iostream>
#include<QMessageBox>
#include<QMouseEvent>
#include<register.h>
#include<QRegExpValidator>
#include<manager.h>
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    bool verification(QString un,QString pd);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void showmain(QString str,QString str1);
    void showregister();
    void showmanager();

private:
    Ui::login *ui;
    QString name;
    QString username;
    QString password;
    int signal=-1;
    QSqlDatabase getconnect();
    Register r;
     Manager m;


};

#endif // LOGIN_H
