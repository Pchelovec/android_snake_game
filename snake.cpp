#include "snake.h"
#include <QDebug>
#include <math.h>
#include <Qt>
#include "my_map.h"
#include "game.h"
#include <QTime>
snake::snake(QObject *parent) : QObject(parent)
{
    start_pos();
    qDebug()<<"snake is ready"<<sh.size()<<endl;
    change_move=true;
    Snake.convertFromImage(QImage(":/res/Snake_.png"));
}

snake::~snake()
{
}
void snake::new_move_to(QPoint *temp)
{
    if (!change_move)
    {
    change_move=true;
    qDebug()<<*temp<<endl;
    int new_move;
    if (abs(temp->x()-temp->y())>6)
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
}

void snake::on_snake_move()
{
    timer->stop();
    change_move=false;
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
        game::up_hard();
        new_fruit();
    }
    //is correct head pos
    if (my_map::is_interference(head.x(),head.y())) {qDebug()<<"game_end";exit(1);}
    eat_myself();
    timer->start(1000/pow(game::get_hard(),0.25));
}
void snake::start_move()
{
    timer=new QTimer;
    connect (timer,SIGNAL(timeout()),this, SLOT(on_snake_move()));
    timer->start(1000/pow(game::get_hard(),0.25));
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
    while (is_snake_pos(x,y) || (my_map::is_interference(x,y)));
    //qDebug()<<"FROIT POS="<<x<<" "<<y;
    fruit.setX(x);
    fruit.setY(y);
}

bool snake::is_snake_pos(int x,int y)
{
    for (int i=0;i<sh.size();i++)
    {
        if ((sh.at(i).x()==x) &&(sh.at(i).y()==y))
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
        //qDebug()<<total_level_count<<" "<<my_map::get_current_level();
        if (total_level_count>my_map::get_current_level())
            return true;
        else return false;
    }
    else return false;
}
void snake::start_pos()
{
    //int size=sh.size();//old size of snake
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
QPoint* snake::get_sh(int i)
{
    QPoint result;
    result=sh[i];
    return &result;
}
int snake::size_snake()
{
    return sh.size();
}
void snake::eat_myself()
{
    QPoint head;
    head=sh[0];
    for (int i=3;i<sh.size();i++)
    {
        if ((head.x()==sh.at(i).x()&&(head.y()==sh.at(i).y())))
        {
            for (int j=i;j<=sh.size();j++)
            {
                sh.pop_back();
            }
            break;
        }
    }
}
void snake::paint_snake(QPainter * paint, int x,int y,int x2,int y2)
{
//    paint->setPen(*(new QColor(255,0,0,255)));
//    //qDebug()<<"snake painted"<<endl;
//    for (int i=0;i<sh.size();i++)
//    {
//        //qDebug()<<sh[i]<<"\t x="<<x<<"y="<<y<<"\t"<<sh[i].x()*x<<" "<<sh[i].y()*y<<" "<<sh[i].x()+x<<" "<<sh[i].y()+y;
//        paint->setPen(QPen(Qt::black, 1, Qt::DashDotLine, Qt::RoundCap));
//        paint->setBrush(QBrush(Qt::green, Qt::Dense5Pattern));
//        paint->drawEllipse((sh[i].x()*x+ my_map::x_extra()/2),(sh[i].y()*y+my_map::y_extra()/2),(x2),(y2));
//        //paint->drawRect((sh[i].x()*x),(sh[i].y()*y),(sh[i].x()*x+x),(sh[i].y()*y+y));
//    }

    qDebug()<<"snake good painted"<<endl;
    paint->setPen(QPen(Qt::black, 1, Qt::DashDotLine, Qt::RoundCap));
    paint->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    for (int i=0;i<sh.size();i++)
    {
        paint->drawEllipse(sh.at(i).x()*x+ my_map::x_extra()/2,sh.at(i).y()*y+ my_map::y_extra()/2,x,y);
        paint->drawPixmap(sh.at(i).x()*x+ my_map::x_extra()/2,sh.at(i).y()*y+ my_map::y_extra()/2,x,y,Snake);
    }
}
