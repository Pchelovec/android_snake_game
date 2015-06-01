#include "graf_viev_modicicate.h"
#include <QPoint>
#include <QDebug>
int graf_viev_modicicate::w=0;
int graf_viev_modicicate::h=0;
int graf_viev_modicicate::hard=1;
graf_viev_modicicate::graf_viev_modicicate()
{
    sn=new snake();
    buf_mouse=new QPoint;
    map=new my_map();
    map->on_size_change();
    sn->start_move();
//    connect(this->sn,SIGNAL(level_up(void )),this->map,SLOT(on_level_up(void )));
}

graf_viev_modicicate::~graf_viev_modicicate()
{
    delete sn;
    delete buf_mouse;
}

void graf_viev_modicicate::set_size(int head, int weigth)
{
    h=head;
    w=weigth;
    //перерисовать задний фон
    emit map->on_size_change();//revrite backgrount
}

void graf_viev_modicicate::game_paint(QPainter & painter)
{
    painter.drawPixmap(0,0,graf_viev_modicicate::w,graf_viev_modicicate::h,(*map->map()));//const background

    sn->paint_snake(&painter,map->box_h(),map->box_w());

    sn->paint_froit(&painter,map->box_h(),map->box_w());

    bool complete=sn->complete_level();
    if (complete)
    {
        map->on_level_up();
        sn->new_fruit();
        sn->start_pos();
    }
}

void graf_viev_modicicate::set_mouse_press(QPoint * pole)
{
    buf_mouse->setX(pole->x());
    buf_mouse->setY(pole->y());
}

void graf_viev_modicicate::set_mouse_unpress(QPoint * pole)
{
    buf_mouse->setX(buf_mouse->x()-pole->x());
    buf_mouse->setY(buf_mouse->y()-pole->y());
    sn->new_move_to(buf_mouse);
}
QPoint graf_viev_modicicate::size_screen()
{
    QPoint result;
    result.setX(graf_viev_modicicate::w);
    result.setY(graf_viev_modicicate::h);
    return result;
}
void graf_viev_modicicate::up_hard()
{
    hard+=1;
}

void graf_viev_modicicate::hard_zero()
{
    hard=1;
}

int graf_viev_modicicate::get_hard()
{
    return hard;
}
void graf_viev_modicicate::on_new_level(void)
{
    hard=1;
}
