#include "historyorder.h"
#include "ui_historyorder.h"

HistoryOrder::HistoryOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoryOrder)
{
    QPixmap pixmap(":/mbg2.jpg");

    QPalette palette=this->palette();

    palette.setBrush(QPalette::Background, QBrush(pixmap));

    this->setPalette(palette);
    ui->setupUi(this);
}

HistoryOrder::~HistoryOrder()
{
    delete ui;
}

void HistoryOrder::initUI(QString account ){
    this->account=account;
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(2,250);
    model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("isbn��"));
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("����"));
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("ʱ��"));
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("����"));
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("����״̬"));

     ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","mysql144");
    if (QSqlDatabase::contains("mysql14")) {
        db = QSqlDatabase::database("mysql14");
    } else {
        db = QSqlDatabase::addDatabase("QMYSQL", "mysql144");

    }
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("mysql");
    db.open();
    if(db.open()){
         std::cout<<"2222"<<std::endl;
        QSqlQuery query(db);
        query.prepare("select * from  bookorder natural join book where username=? order by time ");
        query.addBindValue(account);
        query.exec();
        int t=0;
        while (query.next()) {
            model->setItem(t,0,new QStandardItem(query.value(0).toString()));//isbn��
            model->setItem(t,1,new QStandardItem(query.value(5).toString()));//����
            model->setItem(t,2,new QStandardItem(query.value(2).toString()));//�µ�ʱ��
            model->setItem(t,3,new QStandardItem(query.value(3).toString()));//�µ�����
            if(query.value(4).toString()=="1"){
                 model->setItem(t,4,new QStandardItem(QString::fromLocal8Bit("�Ѹ���")));//����״̬
            }else if(query.value(4).toString()=="0"){
                 model->setItem(t,4,new QStandardItem(QString::fromLocal8Bit("�̼��ѷ���")));//����״̬
            }else if(query.value(4).toString()=="2") {
                  model->setItem(t,4,new QStandardItem(QString::fromLocal8Bit("�����˻�")));//����״̬
            }else if (query.value(4).toString()=="3") {
                 model->setItem(t,4,new QStandardItem(QString::fromLocal8Bit("���˻�")));
            }else if((query.value(4).toString()=="4")){
                model->setItem(t,4,new QStandardItem(QString::fromLocal8Bit("�����")));
            }

         t++;
        }

    }
    db.close();

}

void HistoryOrder::on_pushButton_clicked()
{
     int row=ui->tableView->currentIndex().row();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","mysql144");
    if (QSqlDatabase::contains("mysql14")) {
        db = QSqlDatabase::database("mysql14");
    } else {
        db = QSqlDatabase::addDatabase("QMYSQL", "mysql144");

    }
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("mysql");
    db.open();
    if(db.open()){
        QSqlQuery query(db);
        query.prepare("update bookorder set situation =2 where username=? and ibsn =? and time=? and situation !=3 and situation !=2");
        query.addBindValue(account);
        query.addBindValue(model->data(model->index(row,0)).toString());
        query.addBindValue(model->data(model->index(row,2)).toString());
        query.exec();

    }
    initUI(account);
    db.close();

}

