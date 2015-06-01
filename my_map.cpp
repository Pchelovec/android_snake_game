#include "my_map.h"
#include <QGraphicsPixmapItem>
#include "graf_viev_modicicate.h"
#include <QDebug>
int my_map::w_box=0;
int my_map::h_box=0;
int my_map::pix_dop_x=0;
int my_map::pix_dop_y=0;
int my_map::count_box_w=0;
int my_map::count_box_h=0;
int my_map::leng_for_complete_level=0;
int my_map::current_player_level=1;
my_map::my_map()
{
    pix_map = new QPixmap(graf_viev_modicicate::size_screen().x(),graf_viev_modicicate::size_screen().y());
    paint = new QPainter(pix_map);
    current_player_level=1;
}
void my_map::count_initial_size()
{
    QPoint temp;
    temp=graf_viev_modicicate::size_screen();

    h_box=(temp.x())/count_box_h;
    qDebug()<<"("<<temp.x()<<")/"<<count_box_h<<endl;
    w_box=(temp.y())/count_box_w;
    qDebug()<<"("<<temp.y()<<")/"<<count_box_w<<endl;

    qDebug()<<w_box<<" "<<h_box<<endl;
    pix_dop_x=temp.x()%count_box_h;
    pix_dop_y=temp.y()%count_box_w;
}
my_map::~my_map()
{

}

void my_map::level1()
{
    graf_viev_modicicate::hard_zero();
    leng_for_complete_level=5;
    count_box_h=15;//for current level
    count_box_w=20;
    count_initial_size();
    paint->setPen(*(new QColor(255,34,255,255)));

    for (int i=0;i<count_box_h+1;i++)
        for (int j=0;j<count_box_w+1;j++)
        {
            if ((i==count_box_h) || (j==count_box_w))
                paint->setBrush(QBrush(Qt::black, Qt::SolidPattern));
            else
                    paint->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
                paint->drawRect(pix_dop_x/2+i*h_box,pix_dop_y/2+j*w_box,pix_dop_x+(i+1)*h_box,pix_dop_y+(j+1)*w_box);
        }
}
void my_map::level2()
{
    graf_viev_modicicate::hard_zero();
    leng_for_complete_level=6;
    count_box_h=15;//for current level
    count_box_w=15;
    count_initial_size();
    paint->setPen(*(new QColor(255,34,255,255)));

    for (int i=0;i<count_box_h+1;i++)
        for (int j=0;j<count_box_w+1;j++)
        {
            if ((i==count_box_h) || (j==count_box_w))
                paint->setBrush(QBrush(Qt::black, Qt::SolidPattern));
            else
                    paint->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
                paint->drawRect(pix_dop_x/2+i*h_box,pix_dop_y/2+j*w_box,pix_dop_x+(i+1)*h_box,pix_dop_y+(j+1)*w_box);
        }
}
int my_map::box_w()
{
    return w_box;
}

int my_map::box_h()
{
    return h_box;
}
void my_map::set_count_box(QPoint * screen_size)
{

}
QPixmap* my_map::map()
{
    return pix_map;
}
void my_map::on_size_change()
{
    delete pix_map,paint;
    pix_map = new QPixmap(graf_viev_modicicate::size_screen().x(),graf_viev_modicicate::size_screen().y());
    paint = new QPainter(pix_map);
    //level1();
    write_current_level();
}
int my_map::x_extra()
{
    return pix_dop_x;
}
int my_map::y_extra()
{
    return pix_dop_y;
}
int my_map::get_count_box_h()
{
    return count_box_h;
}

int my_map::get_count_box_w()
{
    return count_box_w;
}
int my_map::get_comlete_snake_leng()
{
    return leng_for_complete_level;
}
void my_map::on_level_up()
{
    current_player_level++;
    write_current_level();
}
void my_map::write_current_level()
{
    graf_viev_modicicate::hard_zero();
    if (current_player_level<=total_level_count)
    {
        switch (current_player_level) {
        case 1:
        {
            level1();
            break;
        }
        case 2:
        {
            level2();
            break;
        }
        }
    }
    else
    {
        qDebug()<<"You win!";
    }
}

int my_map::get_current_level()
{
    return current_player_level;
}
