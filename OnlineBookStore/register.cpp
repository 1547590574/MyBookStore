#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    QPixmap pixmap(":/bg2.jpg");

    QPalette palette=this->palette();

    palette.setBrush(QPalette::Background, QBrush(pixmap));

    this->setPalette(palette);
    ui->setupUi(this);
    setTabOrder(ui->lineEdit,ui->lineEdit_2);
    setTabOrder(ui->lineEdit_2,ui->lineEdit_3);
    setTabOrder(ui->lineEdit_3,ui->lineEdit_4);
}

Register::~Register()
{
    delete ui;
}
void Register::receiveregister(){
    this->show();
}
void Register::zhuche(){
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
    db.open();

    QSqlQuery query(db);
    int count=0;
    query.exec("select * from customer");
    while(query.next()){
        if(query.value(0).toString().trimmed()==ui->lineEdit_2->text().trimmed())
            count++;
    }
    if(count==0){
        query.prepare("insert into customer values(:account,:password,:name)");
        query.bindValue(":account",ui->lineEdit_2->text());
        query.bindValue(":password",ui->lineEdit_3->text());
        query.bindValue(":name",ui->lineEdit->text());
        query.exec();
        query.prepare("insert into details values(?)");
        query.addBindValue(ui->lineEdit_2->text());
        query.exec();
    }else {
        QMessageBox::warning(nullptr, QStringLiteral("æØ∏Ê"), QStringLiteral("’À∫≈“—¥Ê‘⁄"), QMessageBox::Yes , QMessageBox::Yes);

    }


}
void Register::on_pushButton_clicked()
{
   zhuche();
}
