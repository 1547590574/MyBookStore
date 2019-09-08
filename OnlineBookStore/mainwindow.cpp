#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPixmap pixmap(":/bg3.jpeg");

    QPalette palette=this->palette();

    palette.setBrush(QPalette::Background, QBrush(pixmap));

    this->setPalette(palette);
    ui->setupUi(this);
    ui->pushButton_5->setShortcut(Qt::Key_Return);
    database=getConn();
    display();


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receivelogin(QString str,QString str1){
    name=str;
    account=str1;
    std:: cout<<account.toStdString()<<std::endl;
    ui->pushButton_6->setText(name);
    this->show();

}

void MainWindow::on_pushButton_5_clicked()
{
    QSqlDatabase db=getConn();
    db.open();
    ui->pushButton_6->setText(name);
    if(ui->lineEdit->text()!=nullptr&&!ui->tab->isHidden()){

        model->clear();
        setTableView();
        if(db.open()){
            QSqlQuery query(db);
            query.exec("select * from book ");
            int i=0;
            while (query.next()) {
                for(int t=0;t<7;t++){
                    if(ui->lineEdit->text()==query.value(t).toString()){
                        model->setItem(i,0,new QStandardItem(query.value(1).toString()));//
                        model->setItem(i,1,new QStandardItem(query.value(2).toString()));//
                        model->setItem(i,2,new QStandardItem(query.value(3).toString()));//
                        model->setItem(i,3,new QStandardItem(query.value(4).toString()));//
                        model->setItem(i,4,new QStandardItem(query.value(5).toString()));//
                        double p=query.value(5).toString().toDouble()*query.value(3).toString().toDouble();//
                        model->setItem(i,5,new QStandardItem(QString::number(p,10,2)));//
                         model->setItem(i,6,new QStandardItem(query.value(6).toString()));//
                        i++;
                    }
                }
            }
        }
       std:: cout<<"1111"<<std::endl;


    }else if(ui->lineEdit->text()!=nullptr&&!ui->tab_2->isHidden()) {

        model1->clear();
         setTableView();
        if(db.open()){
            QSqlQuery query(db);
            query.exec("select * from book ");
            int i=0;
            while (query.next()) {
                for(int t=0;t<7;t++){
                    if(ui->lineEdit->text()==query.value(t).toString()){
                        model1->setItem(i,0,new QStandardItem(query.value(1).toString()));//
                        model1->setItem(i,1,new QStandardItem(query.value(2).toString()));//
                        model1->setItem(i,2,new QStandardItem(query.value(3).toString()));//
                        model1->setItem(i,3,new QStandardItem(query.value(4).toString()));//
                        model1->setItem(i,4,new QStandardItem(query.value(5).toString()));//
                        double p=query.value(5).toString().toDouble()*query.value(3).toString().toDouble();//
                        model1->setItem(i,5,new QStandardItem(QString::number(p,10,2)));//
                         model1->setItem(i,6,new QStandardItem(query.value(6).toString()));//
                        i++;
                    }
                }
            }
        }
        std::cout<<"22222"<<std::endl;


}else {
    display();
}

      db.close();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}
QSqlDatabase MainWindow::getConn(){
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
void MainWindow::setTableView(){

        model->setColumnCount(8);
        model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("书名"));
        model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("作者"));
        model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("原价"));
        model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("出版社"));
        model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("折扣"));
        model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("现价"));
        model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("数量"));
         model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("isbn号"));
        ui->tableView->setModel(model);
        ui->tableView->verticalHeader()->hide();
         ui->tableView->horizontalHeader()->setStretchLastSection(true);
        ui->tableView->setStyleSheet("selection-background-color:lightblue;");
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        model1->setColumnCount(7);

        model1->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("书名"));
        model1->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("作者"));
        model1->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("原价"));
        model1->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("出版社"));
        model1->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("折扣"));
        model1->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("现价"));
        model1->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("数量"));
        model1->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("isbn号"));
        ui->tableView_2->setModel(model1);
        ui->tableView_2->verticalHeader()->hide();
        ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
        ui->tableView_2->setStyleSheet("selection-background-color:lightblue;");
        ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);



}
void MainWindow::display(){
    ui->pushButton_6->setText(name);
    setTableView();
    QSqlDatabase db=getConn();
    db.open();
    int i=0,t=0;
    if(db.open()){
       QSqlQuery query(db);
       query.exec("select * from book ");
       while (query.next()) {
           model->setItem(i,0,new QStandardItem(query.value(1).toString()));//
           model->setItem(i,1,new QStandardItem(query.value(2).toString()));//
           model->setItem(i,2,new QStandardItem(query.value(3).toString()));//
           model->setItem(i,3,new QStandardItem(query.value(4).toString()));//
           model->setItem(i,4,new QStandardItem(query.value(5).toString()));//
           double p=query.value(5).toString().toDouble()*query.value(3).toString().toDouble();//
           model->setItem(i,5,new QStandardItem(QString::number(p,10,2)));//
           if(query.value(6).toInt()<=0){
                model->setItem(i,6,new QStandardItem(QString::fromLocal8Bit("预售")));
           }else {
                      model->setItem(i,6,new QStandardItem(query.value(6).toString()));
            }

           model->setItem(i,7,new QStandardItem(query.value(0).toString()));//
           if(query.value(5).toString()!="1"){
               model1->setItem(t,0,new QStandardItem(query.value(1).toString()));//
               model1->setItem(t,1,new QStandardItem(query.value(2).toString()));//
               model1->setItem(t,2,new QStandardItem(query.value(3).toString()));//
               model1->setItem(t,3,new QStandardItem(query.value(4).toString()));//
               model1->setItem(t,4,new QStandardItem(query.value(5).toString()));//
               double p=query.value(5).toString().toDouble()*query.value(3).toString().toDouble();//
               model1->setItem(t,5,new QStandardItem(QString::number(p,10,2)));//
               if(query.value(6).toInt()<=0){
                    model1->setItem(i,6,new QStandardItem(QString::fromLocal8Bit("预售")));
               }else {
                          model1->setItem(i,6,new QStandardItem(query.value(6).toString()));
                }

               model->setItem(i,7,new QStandardItem(query.value(0).toString()));//
               t++;

           }
        i++;
       }



    }else {
        std::cout<<"1111"<<std::endl;
}
db.close();
refresh();


}
void MainWindow::refresh(){
    QSqlDatabase db=getConn();
    db.open();
    if(db.open()){
       QSqlQuery query(db);
       query.exec("select * from admin ");
       while (query.next()) {
        ui->textEdit->setText(query.value(2).toString());

       }



    }else {

}
db.close();
}
void MainWindow::on_pushButton_6_clicked()
{
     QObject::connect(this,SIGNAL(showPersonalInfor(QString)),&pi,SLOT(receivePersonalInfor(QString)));
    emit showPersonalInfor(account);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    if(index.isValid()){
        QString data=index.data().toString();

    }
}

void MainWindow::on_pushButton_7_clicked()
{

    QString str1,str2,str3,str4,str5,str6;
    str1=name;

   QSqlDatabase db=getConn();
    if(db.open()){
    QSqlQuery query(db);
    query.prepare("select * from details where username=?");
    query.addBindValue(account);

    query.exec();
    if(query.next()){

        str2=query.value(1).toString();
        str3=query.value(2).toString();
        std:: cout<<"11111"<<std::endl;
    }
      }

    int row=ui->tableView->currentIndex().row();
    QAbstractItemModel *model=ui->tableView->model();
    str4=model->data(model->index(row,0)).toString();
    str5=model->data(model->index(row,1)).toString();
    str6=model->data(model->index(row,5)).toString();
    order.setInfor(str4,str5,str6,str1,str2,str3);
    //std:: cout<<str1.toStdString()+"\t"+str2.toStdString()+"\t"+str4.toStdString()<<std::endl;
    order.account=account;
    order.isbn=model->data(model->index(row,7)).toString();
    order.exec();

}

void MainWindow::on_pushButton_8_clicked()
{
    history.db=database;
    history.initUI(account);
    history.exec();
}
