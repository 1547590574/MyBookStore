#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"QFrame"
#include <QHBoxLayout>
class QLineEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QVBoxLayout getPlayout(QVBoxLayout layout);

private slots:
    void search();

private:
    QLineEdit *m_pSearchLineEdit;
    QVBoxLayout layout;
};

#endif // WIDGET_H
