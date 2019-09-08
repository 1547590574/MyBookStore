#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Manager)
{
    QPixmap pixmap(":/mbg2.jpg");

    QPalette palette=this->palette();

    palette.setBrush(QPalette::Background, QBrush(pixmap));

    this->setPalette(palette);

    ui->setupUi(this);


    //ui->tableView_2->setVerticalScrollBar(bar);
     getCon();
    setTableView();
    setTableData();

}

Manager::~Manager()
{
    delete ui;
}

void Manager::setTableView(){
model->setColumnCount(8);
model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("书名"));
model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("作者"));
model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("原价"));
model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("原出版社"));
model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("折扣"));
model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("现价"));
model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("数量"));
model->setHeaderData(7,Qt::Horizontal,QString::fromLocal8Bit("isbn"));
ui->tableView->setModel(model);
ui->tableView->horizontalHeader()->setStretchLastSection(true);
ui->tableView->verticalHeader()->hide();
ui->tableView->setStyleSheet("selection-background-color:lightblue;");
ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

model1->setColumnCount(5);
model1->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("用户编号"));
model1->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("isbn"));
model1->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("时间"));
model1->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("数量"));
model1->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("订单状态"));
ui->tableView_2->setModel(model1);
ui->tableView_2->setColumnWidth(2,250);
ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
ui->tableView_2->verticalHeader()->hide();
ui->tableView_2->setStyleSheet("selection-background-color:lightblue;");
ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);




}
void Manager::receiveManager(){
    this->show();
}
void Manager::setTableData(){
    int i=0,t=0;
    if(db.open()){
       QSqlQuery query(db);
       query.exec("select * from book ");
       while (query.next()) {
           model->setItem(i,0,new QStandardItem(query.value(1).toString()));//é
           model->setItem(i,1,new QStandardItem(query.value(2).toString()));//
           model->setItem(i,2,new QStandardItem(query.value(3).toString()));//
           model->setItem(i,3,new QStandardItem(query.value(4).toString()));//°
           model->setItem(i,4,new QStandardItem(query.value(5).toString()));//
           double p=query.value(5).toString().toDouble()*query.value(3).toString().toDouble();//
           model->setItem(i,5,new QStandardItem(QString::number(p,10,2)));//
            model->setItem(i,6,new QStandardItem(query.value(6).toString()));//
            model->setItem(i,7,new QStandardItem(query.value(0).toString()));
        i++;
       }
       query.exec("select * from bookorder");
       while (query.next()) {
           model1->setItem(t,0,new QStandardItem(query.value(0).toString()));//§
           model1->setItem(t,1,new QStandardItem(query.value(1).toString()));//é
           model1->setItem(t,2,new QStandardItem(query.value(2).toString()));//”±
           model1->setItem(t,3,new QStandardItem(query.value(3).toString()));//”
           if(query.value(4).toString()=="1"){
                model1->setItem(t,4,new QStandardItem(QString::fromLocal8Bit("已付款")));//”
           }else if(query.value(4).toString()=="0"){
                model1->setItem(t,4,new QStandardItem(QString::fromLocal8Bit("已发货")));//”
           }else if(query.value(4).toString()=="2") {
                 model1->setItem(t,4,new QStandardItem(QString::fromLocal8Bit("用户退货")));//”
           }else if (query.value(4).toString()=="3") {
                model1->setItem(t,4,new QStandardItem(QString::fromLocal8Bit("已退货")));
    }

        t++;
       }

}
     db.close();
}
void Manager::getCon(){
    db = QSqlDatabase::addDatabase("QMYSQL","mysql147");
    if (QSqlDatabase::contains("mysql147")) {
        db = QSqlDatabase::database("mysql147");
    } else {
        db = QSqlDatabase::addDatabase("QMYSQL", "mysql147");

    }
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("mysql");
}

void Manager::on_pushButton_2_clicked()
{
    int row=ui->tableView->currentIndex().row();
    QString isbn=model->data(model->index(row,7)).toString();
    getCon();
    db.open();
    if(db.open()){
        QSqlQuery query(db);
        query.prepare("delete from book where ibsn=?");
        query.addBindValue(isbn);
        query.exec();
        std::cout<<isbn.toStdString()+"1111"<<std::endl;
    }
    QString str=QString::fromLocal8Bit("í±é")+model->data(model->index(row,1)).toString()+"·";
    writeDiary(str);
    db.close();
    std::cout<<isbn.toStdString()<<std::endl;
     model->clear();
     setTableView();
     setTableData();
}

void Manager::writeDiary(QString str){

    QFile file("diary.txt");
    if (file.open(QIODevice::ReadWrite | QIODevice::Append|QIODevice::Text ))
    {
     QTextStream stream(&file);
     dt.setTime(time.currentTime());
     dt.setDate(date.currentDate());
     stream <<dt.toString("yyyy:MM:dd:hh:mm:ss")+"\t"+str+"\n";
    }
    file.close();

}
void Manager::on_pushButton_clicked()
{
    bf.setDb(db);
    bf.exec();
    if(bf.isbn!=nullptr){
        QString str=QString::fromLocal8Bit("上架书籍isbn号:")+bf.isbn;
        writeDiary(str);
    }



}

void Manager::saveGK(){
    getCon();
    db.open();
    QSqlQuery query(db);
    query.prepare("update admin set GK=?");
    query.addBindValue(GK);
      std::cout<<GK.toStdString()<<std::endl;
    query.exec();
    db.close();
}
void Manager::on_pushButton_6_clicked()
{

    dia.setWindowTitle(QString::fromLocal8Bit("发布公告"));
    dia.setLabelText(QString::fromLocal8Bit("即将发布"));
    dia.setInputMode(QInputDialog::TextInput);
    if(dia.exec() == QInputDialog::Accepted)
    {
        GK=dia.textValue();
      QString str= QString::fromLocal8Bit("管理员发布公告：")+GK;
        writeDiary(str);
        saveGK();

    }

}

void Manager::on_pushButton_4_clicked()
{

}

void Manager::on_pushButton_5_clicked()
{
    getCon();
    db.open();
    QSqlQuery query(db);

    if(ui->lineEdit->text()!=nullptr&&ui->tab_4->isHidden()){
         std::cout<<"44444"<<std::endl;
            if(db.open()){
                model->clear();
                setTableView();
                query.prepare("select * from book");
                query.exec();
                int i=0;
                while (query.next()) {
                    std::cout<<"1111"<<std::endl;
                    for(int t=0;t<7;t++){
                        if(ui->lineEdit->text()==query.value(t).toString()){
                            model->setItem(i,0,new QStandardItem(query.value(1).toString()));//
                            model->setItem(i,1,new QStandardItem(query.value(2).toString()));//
                            model->setItem(i,2,new QStandardItem(query.value(3).toString()));//
                            model->setItem(i,3,new QStandardItem(query.value(4).toString()));//
                            model->setItem(i,4,new QStandardItem(query.value(5).toString()));//
                            double p=query.value(5).toString().toDouble()*query.value(3).toString().toDouble();//
                            model->setItem(i,5,new QStandardItem(QString::number(p,10,2)));//
                             model->setItem(i,6,new QStandardItem(query.value(6).toString()));
                              model->setItem(i,7,new QStandardItem(query.value(0).toString()));//
                            i++;
                              std::cout<<"sssss"<<std::endl;
                        }
                    }
                }
            }
    }else if (ui->lineEdit->text()!=nullptr&&ui->tab_3->isHidden()) {
            std::cout<<"3333"<<std::endl;
        model1->clear();
        setTableView();
        query.exec("select * from bookorder");
        int i=0;
        while (query.next()) {
            for(int t=0;t<5;t++){
                if(ui->lineEdit->text()==query.value(t).toString()){
                    model1->setItem(i,0,new QStandardItem(query.value(0).toString()));//§
                    model1->setItem(i,1,new QStandardItem(query.value(1).toString()));//é
                    model1->setItem(i,2,new QStandardItem(query.value(2).toString()));//”±
                    model1->setItem(i,3,new QStandardItem(query.value(3).toString()));//”
                    if(query.value(4).toString()=="1"){
                         model1->setItem(i,4,new QStandardItem(QString::fromLocal8Bit("已付款")));//”
                    }else if(query.value(4).toString()=="0"){
                         model1->setItem(i,4,new QStandardItem(QString::fromLocal8Bit("已发货")));//”
                    }else if(query.value(4).toString()=="2") {
                          model1->setItem(i,4,new QStandardItem(QString::fromLocal8Bit("用户退货")));//”
                    }else if (query.value(4).toString()=="3") {
                         model1->setItem(i,4,new QStandardItem(QString::fromLocal8Bit("已退货")));
                }

                        i++;
                }
            }
        }

    }else if(ui->lineEdit->text()==nullptr){
         setTableData();
             std::cout<<"22222"<<std::endl;
    }
    db.close();

}

void Manager::on_pushButton_7_clicked()
{
    getCon();
    db.open();
    int row=ui->tableView_2->currentIndex().row();
    if(db.open()){
        QSqlQuery query(db);
            query.prepare("update bookorder set situation=0 where username=? and ibsn=? and situation=1 and number=? ");
            query.addBindValue(model1->data(model1->index(row,0)).toString());
            query.addBindValue(model1->data(model1->index(row,1)).toString());
             query.addBindValue(model1->data(model1->index(row,3)).toString());
            query.exec();


    }
     setTableData();
    db.close();

}

void Manager::on_pushButton_8_clicked()
{

    getCon();
    db.open();
    int row=ui->tableView_2->currentIndex().row();
    if(db.open()){
        QSqlQuery query(db);
            query.prepare("update bookorder set situation=3 where username=? and ibsn=? and situation=2 and number=?");
            query.addBindValue(model1->data(model1->index(row,0)).toString());
            query.addBindValue(model1->data(model1->index(row,1)).toString());
            query.addBindValue(model1->data(model1->index(row,3)).toString());
            query.exec();
        setTableData();
    }
    db.close();
}

void Manager::on_pushButton_3_clicked()
{
    getCon();
    db.open();
    if(db.open()){
        QSqlQuery query(db);
        query.exec("delete from book");
        for (int i=0;i<model->rowCount();i++) {
            query.prepare("insert into book values(?,?,?,?,?,?,?)");
            query.addBindValue(model->data(model->index(i,7)).toString());
            query.addBindValue(model->data(model->index(i,0)).toString());
            query.addBindValue(model->data(model->index(i,1)).toString());
            query.addBindValue(model->data(model->index(i,2)).toDouble());
            query.addBindValue(model->data(model->index(i,3)).toString());
            query.addBindValue(model->data(model->index(i,4)).toDouble());
            query.addBindValue(model->data(model->index(i,6)).toString());
            query.exec();
            std::cout<<model->data(model->index(i,2)).toString().toStdString()<<std::endl;

        }

    }
    std::cout<<"11111"<<std::endl;
}
