#ifndef CLICKEDLABEL_H
#define CLICKEDLABEL_H
#include <QLabel>
#include <QWidget>

class ClickedLabel:public QLabel
{
    Q_OBJECT
   signals:
       void Clicked(ClickedLabel* clicked);
   public:
       ClickedLabel(QWidget *parent=nullptr): QLabel(parent),m_str("")
       {
           setText(m_str);
       }
       ~ClickedLabel() {}
   protected:
       void mouseReleaseEvent( QMouseEvent* );
   private:
       QString m_str;
};

#endif // CLICKEDLABEL_H
