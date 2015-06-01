#include "snake.h"
#include <QDebug>
#include <math.h>
#include <Qt>
#include "my_map.h"
#include "graf_viev_modicicate.h"
#include <QTime>
snake::snake(QObject *parent) : QObject(parent)
{
    length=3;
    start_pos();
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
    //qDebug()<<"snake painted"<<endl;
    for (int i=0;i<sh.size();i++)
    {
        //qDebug()<<sh[i]<<"\t x="<<x<<"y="<<y<<"\t"<<sh[i].x()*x<<" "<<sh[i].y()*y<<" "<<sh[i].x()+x<<" "<<sh[i].y()+y;
        paint->setPen(QPen(Qt::black, 1, Qt::DashDotLine, Qt::RoundCap));
        paint->setBrush(QBrush(Qt::green, Qt::Dense5Pattern));
        paint->drawEllipse((sh[i].x()*x+ my_map::x_extra()/2),(sh[i].y()*y+my_map::y_extra()/2),(x),(y));
        //paint->drawRect((sh[i].x()*x),(sh[i].y()*y),(sh[i].x()*x+x),(sh[i].y()*y+y));
    }
}
QVector <QPoint> * snake::snake_koord()
{
    return &sh;
}
void snake::on_snake_move(void )
{
    timer->stop();

    bool hangry=!is_froit_eated();

    QPoint head;
    head=sh[0];


    QPoint xv;
    xv=sh[sh.size()-1];//запомнить хвост, если съели фрукт добавить

    sh.pop_back();//удалить хвост
    switch (move_to) {
    case UP:
    {
        head.setY(head.y()-1);
        break;
    }
    case DOUN:
    {
        head.setY(head.y()+1);
        break;
    }
    case LEFT:
    {
        head.setX(head.x()-1);
        break;
    }
    case RIGHT:
    {
        head.setX(head.x()+1);
        break;
    }
    }
    sh.push_front(head);

    if (!hangry)
    {//рост
        sh.push_back(xv);
        graf_viev_modicicate::up_hard();
        new_fruit();
    }
    //is correct head pos

    timer->start(800/pow(graf_viev_modicicate::get_hard(),0.5));
    //connect (timer,SIGNAL(timeout()),this, SLOT(on_snake_move()));
}
void snake::start_move()
{
    timer=new QTimer;
    connect (timer,SIGNAL(timeout()),this, SLOT(on_snake_move()));
    timer->start(800/pow(graf_viev_modicicate::get_hard(),0.5));
}
void snake::paint_froit(QPainter * paint,int x,int y)
{
    //qDebug()<<fruit.x()<<" "<<fruit.y();
    paint->setPen(QPen(Qt::red, 1, Qt::DashDotLine, Qt::RoundCap));
    paint->setBrush(QBrush(Qt::red, Qt::Dense2Pattern));
    paint->drawEllipse((fruit.x()*x+ my_map::x_extra()/2),(fruit.y()*y+my_map::y_extra()/2),(x),(y));

    //new_fruit();
}
void snake::new_fruit()
{
    int x,y;

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    do
    {
        x=qrand()% (my_map::get_count_box_h());
        y=qrand()% (my_map::get_count_box_w());
    }
    while (is_snake_pos(x,y));
    //qDebug()<<"FROIT POS="<<x<<" "<<y;
    fruit.setX(x);
    fruit.setY(y);
}

bool snake::is_snake_pos(int x,int y)
{
    for (int i=0;i<sh.size();i++)
    {
        if ((sh[i].x()==x) &&(sh[i].y()==y))
        {
            return true;
        }
    }
    return false;
}

bool snake::is_froit_eated()
{
    if ( (fruit.x()==sh[0].x()) && (fruit.y()==sh[0].y()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool snake::complete_level()
{
    if (sh.size()==my_map::get_comlete_snake_leng())
    {
        qDebug()<<total_level_count<<" "<<my_map::get_current_level();
        if (total_level_count>my_map::get_current_level())
            return true;
        else return false;
    }
    else return false;
}
void snake::start_pos()
{
    int size=sh.size();//old size of snake
    move_to=4;//right
    sh.clear();
    for (int i=0;i<3;i++)
    {
        QPoint temp;
        temp.setX(i);
        temp.setY(1);
        sh.push_front(temp);
        qDebug()<<temp;
    }
    qDebug()<<"snake is ready"<<sh.size()<<endl;
}
