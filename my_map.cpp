#include "my_map.h"
#include <QGraphicsPixmapItem>
#include "game.h"
#include <QDebug>
int my_map::w_box=0;
int my_map::h_box=0;
int my_map::pix_dop_x=0;
int my_map::pix_dop_y=0;
int my_map::count_box_w=0;
int my_map::count_box_h=0;
int my_map::leng_for_complete_level=0;
int my_map::current_player_level=1;
QVector <QPoint> * my_map::map_hindrance;
my_map::my_map()
{
//    pix_map = new QPixmap(game::size_screen().x(),game::size_screen().y());
//    paint = new QPainter(pix_map);
    current_player_level=1;
    map_hindrance=new QVector <QPoint>;
}
void my_map::count_initial_size()
{
    QPoint temp;
    temp=game::size_screen();

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

void my_map::level1(view * v)
{
    leng_for_complete_level=5;
    count_box_h=8;//for current level
    count_box_w=10;
    count_initial_size();
    //paint->setPen(*(new QColor(255,34,255,255)));

    for (int i=0;i<=count_box_h;i++)
        for (int j=0;j<=count_box_w;j++)
        {
            if ((i==count_box_h) || (j==count_box_w))
                //paint->setBrush(QBrush(Qt::black, Qt::SolidPattern));
                v->rect(QBrush(Qt::black, Qt::SolidPattern),*(new QColor(255,34,255,255)),pix_dop_x/2+i*h_box,pix_dop_y/2+j*w_box,pix_dop_x+(i+1)*h_box,pix_dop_y+(j+1)*w_box);
            else
                v->rect(QBrush(Qt::yellow, Qt::SolidPattern),*(new QColor(255,34,255,255)),pix_dop_x/2+i*h_box,pix_dop_y/2+j*w_box,pix_dop_x+(i+1)*h_box,pix_dop_y+(j+1)*w_box);
                //    paint->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
                //paint->drawRect(pix_dop_x/2+i*h_box,pix_dop_y/2+j*w_box,pix_dop_x+(i+1)*h_box,pix_dop_y+(j+1)*w_box);//paint elemet
        }
}
void my_map::level2(view * v)
{

    leng_for_complete_level=6;
    count_box_h=15;//for current level
    count_box_w=15;
    count_initial_size();
    //paint->setPen(*(new QColor(255,34,255,255)));

    for (int i=0;i<count_box_h+1;i++)
        for (int j=0;j<count_box_w+1;j++)
        {
            if ((i==count_box_h) || (j==count_box_w))
                //paint->setBrush(QBrush(Qt::black, Qt::SolidPattern));
                v->rect(QBrush(Qt::black, Qt::SolidPattern),*(new QColor(255,34,255,255)),pix_dop_x/2+i*h_box,pix_dop_y/2+j*w_box,pix_dop_x+(i+1)*h_box,pix_dop_y+(j+1)*w_box);
            else
                v->rect(QBrush(Qt::yellow, Qt::SolidPattern),*(new QColor(255,34,255,255)),pix_dop_x/2+i*h_box,pix_dop_y/2+j*w_box,pix_dop_x+(i+1)*h_box,pix_dop_y+(j+1)*w_box);
                //    paint->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
                //paint->drawRect(pix_dop_x/2+i*h_box,pix_dop_y/2+j*w_box,pix_dop_x+(i+1)*h_box,pix_dop_y+(j+1)*w_box);
        }
    for (int i=0;i<5;i++)
    {
        v->rect(QBrush(Qt::red, Qt::SolidPattern),
                *(new QColor(255,34,255,255)),
                pix_dop_x/2+(i)*h_box,
                pix_dop_y/2+7*w_box,
                h_box,
                w_box);//припятствие
        QPoint temp;
        temp.setX(i);
        temp.setY(7);
        map_hindrance->push_back(temp);
        v->rect(QBrush(Qt::red, Qt::SolidPattern),
                *(new QColor(255,34,255,255)),
                pix_dop_x/2+(10+i)*h_box,
                pix_dop_y/2+7*w_box,
                h_box,
                w_box);//припятствие
        temp.setX(10+i);
        map_hindrance->push_back(temp);
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

QPixmap* my_map::map(view *v)
{
    return v->get_pix_map();
}
void my_map::on_size_change(view * v)
{
    emit v->on_size_change();
    //level1();
    write_current_level(v);
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
void my_map::on_level_up(view * v)
{
    //game::hard_zero();
    current_player_level++;
    write_current_level(v);
}
void my_map::write_current_level(view * v)
{
    map_hindrance->clear();
    if (current_player_level<=total_level_count)
    {
        switch (current_player_level) {
        case 1:
        {
            level1(v);
            break;
        }
        case 2:
        {
            level2(v);
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
bool my_map::is_interference(int x,int y)
{
    bool result;
    for (int i=0;i<map_hindrance->size();i++)
    {
        if ((map_hindrance->at(i).x()==x)&&(map_hindrance->at(i).y()==y)) return true;
    }
    if (x>=count_box_h || y>=count_box_w || x<0 || y<0) return true;
    else return false;
}
