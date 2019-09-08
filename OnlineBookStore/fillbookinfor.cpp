#include "fillbookinfor.h"
#include "ui_fillbookinfor.h"

FillBookInfor::FillBookInfor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FillBookInfor)
{
    QPixmap pixmap(":/mbg2.jpg");

    QPalette palette=this->palette();

    palette.setBrush(QPalette::Background, QBrush(pixmap));

    this->setPalette(palette);
    ui->setupUi(this);
    ui->lineEdit_4->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
     ui->lineEdit_6->setValidator(new QRegExpValidator(QRegExp("^0\.\d*[1-9]\d*$")));
      ui->lineEdit_7->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
}

FillBookInfor::~FillBookInfor()
{
    delete ui;
}

void FillBookInfor::setDb(QSqlDatabase db){
   this->db=db;
}

void FillBookInfor:: setInfor(){
    db.open();
    if(db.open()){
        QSqlQuery query(db);
        query.prepare("insert into book values(?,?,?,?,?,?,?)");
        query.addBindValue(ui->lineEdit->text());
        query.addBindValue(ui->lineEdit_2->text());
        query.addBindValue(ui->lineEdit_3->text());
        query.addBindValue(ui->lineEdit_4->text());
        query.addBindValue(ui->lineEdit_5->text());
        query.addBindValue(ui->lineEdit_6->text());
        query.addBindValue(ui->lineEdit_7->text());
        query.exec();
          std:: cout<<"33333"<<std::endl;

    }
    db.close();
    isbn=ui->lineEdit->text();


}

void FillBookInfor::on_pushButton_clicked()
{
    setInfor();
    this->close();
}
