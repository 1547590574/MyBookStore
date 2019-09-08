#include "login.h"
#include "ui_login.h"
#include<QMouseEvent>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    QPixmap pixmap(":/bg1.jpg");

    QPalette palette=this->palette();

    palette.setBrush(QPalette::Background, QBrush(pixmap));

    this->setPalette(palette);

    ui->setupUi(this);
    ui->account->setFocus();
    ui->password->setEchoMode(QLineEdit::Password);
    ui->rad1->setChecked(true);

}


login::~login()
{
    delete ui;
}


QSqlDatabase login::getconnect(){
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
bool login::verification(QString un , QString pd)
{
    bool flag=false;
    QSqlDatabase db=getconnect();
    db.open();
    if(db.open()){
        QSqlQuery query(db);
        if(ui->rad1->isChecked()){
             query.exec("select * from admin");
        }else if (ui->rad2->isChecked()) {
              query.exec("select * from customer");
        }

        while(query.next()){
            if(un.trimmed()==query.value(0).toString().trimmed()&&pd.trimmed()==query.value(1).toString().trimmed())
            {
                    name=query.value(2).toString();

                 flag=true;

            }
        }
    }else{
          QMessageBox::warning(nullptr, QStringLiteral("警告"), QStringLiteral("数据库连接失败"), QMessageBox::Yes , QMessageBox::Yes);

    }
    db.close();
    return flag;

}


void login::on_pushButton_clicked()
{
    if(verification(ui->account->text(),ui->password->text())&&ui->rad2->isChecked()){
        this->hide();
        emit showmain(name,ui->account->text().trimmed());
    }else if (verification(ui->account->text(),ui->password->text())&&ui->rad1->isChecked()) {
        this->hide();
        emit showmanager();
    }
    else {
        QMessageBox::warning(this, QStringLiteral("提示"), QStringLiteral("请您输入正确密码"), QMessageBox::Yes, QMessageBox::Yes);
    }


}

void login::on_pushButton_2_clicked()
{

   r.show();
}

