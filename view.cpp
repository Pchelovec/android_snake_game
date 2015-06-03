#include "view.h"
#include "my_map.h"
#include "game.h"
#include <QDebug>
view::view()
{
    pix_map = new QPixmap(game::size_screen().x(),game::size_screen().y());
    ready_map = new QPainter(pix_map);
    set_apple_gress_pixmap();
}

view::~view()
{

}

//void view::rect(int x, int y, int x2, int y2)
//{
//    ready_map->setPen(pen_color);
//    ready_map->setBrush(br);
//    ready_map->drawRect(x,y,x2,y2);
//}
void view::rect_box(int x,int y,int x2,int y2)
{
    ready_map->drawPixmap(x,y,x2,y2, box);
}
void view::map_good(int x,int y,int x2,int y2)
{
    ready_map->drawPixmap(x,y,x2,y2, gress);
}
void view::on_size_change()
{
    delete pix_map,ready_map;
    pix_map = new QPixmap(game::size_screen().x(),game::size_screen().y());
    ready_map = new QPainter(pix_map);
    set_apple_gress_pixmap();
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
void view::paint_good_apple(QPainter *paint,int x,int y,int x2,int y2)
{
    paint->drawPixmap(x,y,x2,y2, apple);
}

void view::set_apple_gress_pixmap()
{
    apple.convertFromImage(QImage(":/res/apple.jpg"));
    gress.convertFromImage(QImage(":/res/grass.jpg"));
    box.convertFromImage(QImage(":/res/box.jpg"));
    Snake.convertFromImage(QImage(":/res/Snake.jpg"));
}
void view::paint_good_snake(snake *sh,QPainter*paint,int x,int y,int x2,int y2)
{
    Snake.convertFromImage(QImage(":/res/Snake.jpg"));
    qDebug()<<"snake good painted"<<endl;
    for (int i=0;i<sh->size_snake();i++)
    {
        paint->setPen(QPen(Qt::black, 1, Qt::DashDotLine, Qt::RoundCap));
        paint->setBrush(QBrush(Qt::green, Qt::SolidPattern));
        paint->drawEllipse(x,y,x2,y2);
        paint->drawPixmap(x,y,x2,y2,Snake);
    }
}
