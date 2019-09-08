#include "login.h"
#include"mainwindow.h"
#include"widget.h"
#include"register.h"
#include"personinfor.h"
#include"manager.h"
#include <QApplication>
#include"QObject"
void insetData(){

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.show();
    Manager m;
   //m.show();
   // w.show();

   Register r;
   login l;
  // login ll;
  l.show();
  //ll.show();
    QObject::connect(&l,SIGNAL(showmain(QString,QString)),&w,SLOT(receivelogin(QString,QString)));
    QObject::connect(&l,SIGNAL(showregister()),&r,SLOT(receiveregister()));
    QObject::connect(&l,SIGNAL(showmanager()),&m,SLOT(receiveManager()));
  //r.show();
     return a.exec();
}
