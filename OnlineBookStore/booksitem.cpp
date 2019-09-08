#include "booksitem.h"
#include "ui_booksitem.h"

BooksItem::BooksItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BooksItem)
{
    ui->setupUi(this);
}
BooksItem::BooksItem(QString bookname,QString author,QString price ,QString discount,QString kind_of,QString details){
   bookname=this->bookname;
   author=this->author;
   price=this->price;
   discount=this->discount;
   kind_of=this->kind_of;
   details=this->details;
}
void BooksItem::initUI(){
    ui->label_2->setText(bookname);
    ui->label_3->setText(author);
    ui->label_4->setText("￥"+price);
    ui->label_5->setText(details);

}
BooksItem::~BooksItem()
{
    delete ui;
}
