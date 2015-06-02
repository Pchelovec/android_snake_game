#include "mywidget.h"
MyWidget::MyWidget()
{
    table=new game();
    table->set_size(this->height(),this->width());
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(repaint()));
    timer->start(1000/25);//25 cadrs per second
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    //create a QPainter and pass a pointer to the device.
    //A paint device can be a QWidget, a QPixmap or a QImage
    QPainter painter(this);
    table->game_paint(painter);//paint current screen
}
void MyWidget::mousePressEvent ( QMouseEvent * event )
{
    qDebug()<<"press"<<endl;
    qDebug()<<event->pos()<<endl;
    QPoint *temp=new QPoint;
    temp->setX(event->pos().x());
    temp->setY(event->pos().y());
    table->set_mouse_press(temp);
}

void MyWidget::mouseReleaseEvent ( QMouseEvent * event )
{
    qDebug()<<"unpress"<<endl;
    qDebug()<<event->pos()<<endl;
    QPoint *temp=new QPoint;
    temp->setX(event->pos().x());
    temp->setY(event->pos().y());
    table->set_mouse_unpress(temp);
}
void MyWidget::resizeEvent(QResizeEvent *event)
{
    table->set_size(this->height(),this->width());
    qDebug()<<"window size_change to"<<this->height()<<this->width()<<endl;
    emit repaint();
}
