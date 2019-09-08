#include "orderisok.h"
#include "ui_orderisok.h"

OrderIsOk::OrderIsOk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderIsOk)
{
    QPixmap pixmap(":/bg6.jpg");

    QPalette palette=this->palette();

    palette.setBrush(QPalette::Background, QBrush(pixmap));

    this->setPalette(palette);
    ui->setupUi(this);
     ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
}

OrderIsOk::~OrderIsOk()
{
    delete ui;
}

void  OrderIsOk::setInfor(QString str1,QString str2,QString str3,QString str4,QString str5,QString str6){
    ui->label_6->setText(str1);//书名
    ui->label_5->setText(str2);//作者名
    ui->label_7->setText(str3);//价格
    ui->lineEdit->setText(str4);//称呼
    ui->lineEdit_2->setText(str5);//联系电话
    ui->lineEdit_3->setText(str6);//收货地址
}

void OrderIsOk::on_pushButton_2_clicked()
{
    this->close();
}

void OrderIsOk::on_pushButton_clicked()
{

     count=ui->spinBox->text();
     dt.setTime(time.currentTime());
     dt.setDate(date.currentDate());
     //orderinfor=dt.toString("yyyy:MM:dd:hh:mm:ss")+"\t"+"购买了《"+ui->label_6->text()+"》";
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
    query.exec("update book set count=count-? where book_name=? and author=?");
    query.addBindValue(ui->spinBox->text().toInt());
    query.addBindValue(ui->label_6->text());
    query.addBindValue(ui->label_5->text());
    query.exec();
//    query.prepare("select * from bookorder where username=? and ibsn=?");
//    query.addBindValue(account);
//    query.addBindValue(isbn);
//    query.exec();
//    if(query.next()){
//    query.prepare("update bookorder set number=number+?,time=? where username=? and ibsn=?");
//    query.addBindValue(count);
//    query.addBindValue(dt);
//    query.addBindValue(account);
//    query.addBindValue(isbn);
//    query.exec();
//     std::cout<<"1111"<<std::endl;
//    }else {
        query.prepare("insert into bookorder values(?,?,?,?,?)");
        query.addBindValue(account);
        query.addBindValue(isbn);
        query.addBindValue(dt);
        query.addBindValue(count);
        query.addBindValue("1");
        query.exec();
        std::cout<<"2222"<<std::endl;

    db.close();

    this->close();
}


