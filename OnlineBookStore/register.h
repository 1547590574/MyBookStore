 #ifndef REGISTER_H
#define REGISTER_H
#include<QMessageBox>
#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include"iostream"
namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_pushButton_clicked();
    void receiveregister();

private:
    Ui::Register *ui;
    void zhuche();
};

#endif // REGISTER_H
