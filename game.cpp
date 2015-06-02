#include "game.h"
#include <QPoint>
#include <QDebug>
int game::w=0;
int game::h=0;
int game::hard=1;
game::game()
{
    sn=new snake();
    buf_mouse=new QPoint;
    map=new my_map();
    sn->start_move();
    v=new view;
    map->on_size_change(v);//изменился размер отображаемой части
}

game::~game()
{
    delete sn;
    delete buf_mouse;
}

void game::set_size(int head, int weigth)
{
    h=head;
    w=weigth;
    //перерисовать задний фон
    emit map->on_size_change(v);//revrite backgrount
}

void game::game_paint(QPainter & painter)
{
    painter.drawPixmap(0,0,game::w,game::h,(*map->map(v)));//const background

    sn->paint_snake(&painter,map->box_h(),map->box_w());//android and desctope
    //v->paint_snake(sn,&painter,map->box_h(),map->box_w());//problem with android

    //sn->paint_froit(&painter,map->box_h(),map->box_w());

    v->elipse(&painter,//fruit painting
              (QBrush(Qt::red, Qt::Dense2Pattern)),
              (QColor(255,0,0,255)),
              (sn->get_fruit_x() * my_map::box_h()+ my_map::x_extra()/2),
              (sn->get_fruit_y() * my_map::box_w()+my_map::y_extra()/2),
              my_map::box_h(),
              my_map::box_w());

    bool complete=sn->complete_level();
    if (complete)
    {
        map->on_level_up(v);
        sn->new_fruit();
        sn->start_pos();
    }
}

void game::set_mouse_press(QPoint * pole)
{
    buf_mouse->setX(pole->x());
    buf_mouse->setY(pole->y());
}

void game::set_mouse_unpress(QPoint * pole)
{
    buf_mouse->setX(buf_mouse->x()-pole->x());
    buf_mouse->setY(buf_mouse->y()-pole->y());
    sn->new_move_to(buf_mouse);
}
QPoint game::size_screen()
{
    QPoint result;
    result.setX(game::w);
    result.setY(game::h);
    return result;
}
void game::up_hard()
{
    hard+=1;
}

void game::hard_zero()
{
    hard=1;
}

int game::get_hard()
{
    return hard;
}
void game::on_new_level(void)
{
    hard=1;
}
