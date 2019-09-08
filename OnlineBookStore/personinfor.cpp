#include "personinfor.h"
#include "ui_personinfor.h"

PersonInfor::PersonInfor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonInfor)
{
    QPixmap pixmap(":/bg4.jpg");

    QPalette palette=this->palette();

    palette.setBrush(QPalette::Background, QBrush(pixmap));

    this->setPalette(palette);
    ui->setupUi(this);
    ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
}

PersonInfor::~PersonInfor()
{
    delete ui;
}
void PersonInfor::receivePersonalInfor(QString str){

    userid=str;
    initUI();
     this->show();
}

QSqlDatabase PersonInfor::getCon(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","mysql14");
    if (QSqlDatabase::contains("mysql14")) {
        db = QSqlDatabase::database("mysql14");
    } else {
        db = QSqlDatabase::addDatabase("QMYSQL", "mysql14");

    }
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("mysql");
    return db;
}

void PersonInfor::initUI(){
    QSqlDatabase db=getCon();
    db.open();
    if(db.open()){
        QSqlQuery query(db);
        query.prepare("select * from customer natural join details where username=?");
        query.addBindValue(userid);
        query.exec();
        while (query.next()) {
            ui->lineEdit->setText(query.value(2).toString());
            ui->lineEdit_2->setText(query.value(3).toString());
            ui->lineEdit_3->setText(query.value(4).toString());
            ui->textEdit->setText(query.value(5).toString());
        }
    }
    db.open();

}

void PersonInfor::on_pushButton_clicked()
{
    QSqlDatabase db=getCon();
    db.open();
    if(db.open()){
        QSqlQuery query(db);
        query.prepare("update details set telephone=?,adress=?,signature=? where username=?");
        query.addBindValue(ui->lineEdit_2->text().trimmed());
        query.addBindValue(ui->lineEdit_3->text().trimmed());
        query.addBindValue(ui->textEdit->toPlainText().trimmed());
        query.addBindValue(userid);
        query.exec();
        query.prepare("update customer set name=? where username=?");
        query.addBindValue(ui->lineEdit->text());
        query.addBindValue(userid);
        query.exec();
    }
    db.close();
    this->close();
}
