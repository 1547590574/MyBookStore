#ifndef PERSONINFOR_H
#define PERSONINFOR_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QRegExpValidator>
namespace Ui {
class PersonInfor;
}

class PersonInfor : public QWidget
{
    Q_OBJECT

public:
    explicit PersonInfor(QWidget *parent = nullptr);
    ~PersonInfor();
private slots:
    void receivePersonalInfor(QString str);
    void on_pushButton_clicked();

private:
    Ui::PersonInfor *ui;
    QSqlDatabase getCon();
    void initUI();
    QString userid;
};

#endif // PERSONINFOR_H
