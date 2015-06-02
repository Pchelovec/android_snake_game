#include "view.h"
#include "my_map.h"
#include "game.h"
#include <QDebug>
view::view()
{
    pix_map = new QPixmap(game::size_screen().x(),game::size_screen().y());
    ready_map = new QPainter(pix_map);
}

view::~view()
{

}

void view::rect(QBrush br, QColor pen_color,int x,int y,int x2,int y2)
{
    ready_map->setPen(pen_color);
    ready_map->setBrush(br);
    ready_map->drawRect(x,y,x2,y2);
}

void view::on_size_change()
{
    delete pix_map,ready_map;
    pix_map = new QPixmap(game::size_screen().x(),game::size_screen().y());
    ready_map = new QPainter(pix_map);
}
QPixmap * view::get_pix_map()
{
    return pix_map;
}
void view::elipse(QPainter *paint,QBrush br, QColor pen_color,int x,int y,int x2,int y2)//apple
{
    paint->setPen(pen_color);
    paint->setBrush(br);
    paint->drawEllipse(x,y,x2,y2);
}
void view::paint_snake(snake *sh,QPainter*paint,int x,int y)
{
    qDebug()<<"snake painted"<<endl;
    for (int i=0;i<sh->size_snake();i++)
    {
        paint->setPen(QPen(Qt::black, 1, Qt::DashDotLine, Qt::RoundCap));
        paint->setBrush(QBrush(Qt::green, Qt::Dense5Pattern));
        paint->drawEllipse((sh->get_sh(i)->x()*x+ my_map::x_extra()/2),(sh->get_sh(i)->y()*y+my_map::y_extra()/2),(x),(y));
    }
}
