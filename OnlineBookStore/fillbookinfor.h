#ifndef FILLBOOKINFOR_H
#define FILLBOOKINFOR_H

#include <QDialog>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<iostream>
#include<QRegExpValidator>
namespace Ui {
class FillBookInfor;
}

class FillBookInfor : public QDialog
{
    Q_OBJECT

public:
    explicit FillBookInfor(QWidget *parent = nullptr);
    ~FillBookInfor();
    void setDb(QSqlDatabase db);
    void setInfor();
     QString isbn;

private slots:
    void on_pushButton_clicked();

private:
    Ui::FillBookInfor *ui;
    QSqlDatabase db;


};

#endif // FILLBOOKINFOR_H
