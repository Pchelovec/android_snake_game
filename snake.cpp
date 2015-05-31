#include "snake.h"
#include <QDebug>
#include <math.h>
#include <Qt>
#include "my_map.h"
snake::snake(QObject *parent) : QObject(parent)
{
    speed=1;
    length=3;
    move_to=4;//right
    for (int i=0;i<3;i++)
    {
        QPoint temp;
        temp.setX(i);
        temp.setY(1);
        sh.push_back(temp);
        qDebug()<<temp;
    }
    qDebug()<<"snake is ready"<<sh.size()<<endl;
}

snake::~snake()
{

}
void snake::new_move_to(QPoint *temp)
{
    qDebug()<<*temp<<endl;
    int new_move;
    if (abs(temp->x()-temp->y())>10)
    {
    if (abs(temp->x())>abs(temp->y()))
    {//left or right
        if (temp->x()<0)
        {//right
            new_move=RIGHT;
            qDebug()<<"user want right"<<endl;
            if (move_to!=LEFT) move_to=new_move;
        }
        else
        {//left
            new_move=LEFT;
            qDebug()<<"user want left"<<endl;
            if (move_to!=RIGHT) move_to=new_move;
        }
    }
    else
    {//up or doun
        if (temp->y()<0)
        {//doun
            new_move=DOUN;
            qDebug()<<"user want doun"<<endl;
            if (move_to!=UP) move_to=new_move;
        }
        else
        {//up
            new_move=UP;
            qDebug()<<"user want up"<<endl;
            if (move_to!=DOUN) move_to=new_move;
        }
    }
    }
    else qDebug()<<"small distance";
    qDebug()<<move_to;
}
void snake::paint_snake(QPainter * paint, int x,int y)
{
    paint->setPen(*(new QColor(255,0,0,255)));
    //paint->setPen(Qt::red);
    qDebug()<<"shake painted"<<endl;
    for (int i=0;i<sh.size();i++)
    {
        //qDebug()<<sh[i]<<"\t x="<<x<<"y="<<y<<"\t"<<sh[i].x()*x<<" "<<sh[i].y()*y<<" "<<sh[i].x()+x<<" "<<sh[i].y()+y;
        paint->setPen(QPen(Qt::black, 1, Qt::DashDotLine, Qt::RoundCap));
        paint->setBrush(QBrush(Qt::green, Qt::Dense5Pattern));
        paint->drawEllipse((sh[i].x()*x+ my_map::x_extra()/2),(sh[i].y()*y+my_map::y_extra()/2),(sh[i].x()+x-1),(sh[i].y()+y-1));
        //paint->drawRect((sh[i].x()*x),(sh[i].y()*y),(sh[i].x()*x+x),(sh[i].y()*y+y));
    }
}
QVector <QPoint> * snake::snake_koord()
{
    return &sh;
}
