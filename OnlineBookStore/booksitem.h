#ifndef BOOKSITEM_H
#define BOOKSITEM_H

#include <QWidget>

namespace Ui {
class BooksItem;
}

class BooksItem : public QWidget
{
    Q_OBJECT

public:
    explicit BooksItem(QWidget *parent = nullptr);
    QString bookname,author,price,discount,kind_of,details;
    BooksItem(QString name,QString author,QString price ,QString discount,QString kind_of,QString details);
    ~BooksItem();
    void initUI();

private:
    Ui::BooksItem *ui;
};

#endif // BOOKSITEM_H
