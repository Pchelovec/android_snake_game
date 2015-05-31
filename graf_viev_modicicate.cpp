#include "graf_viev_modicicate.h"
#include <QPoint>
#include <QDebug>
int graf_viev_modicicate::w=0;
int graf_viev_modicicate::h=0;
graf_viev_modicicate::graf_viev_modicicate()
{
    sn=new snake();
    buf_mouse=new QPoint;
    map=new my_map();
    map->on_size_change();
    current_player_level=1;
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

//    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.setPen(QPen(Qt::black, 12, Qt::DashDotLine, Qt::RoundCap));
//    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));

    //painter.drawEllipse(80, 80, 400, 240);
//    QVector <QPoint> *arr_sh=new QVector <QPoint>;
//    arr_sh=sn->snake_koord();

////    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));

//    qDebug()<<"shake painted"<<arr_sh->size()<<endl;
//    for (int i=0;i<arr_sh->size();i++)
//    {
////        QPoint temp;
////        temp.setX(arr_sh[i].at(i).x());
////        temp.setY(arr_sh[i].at(i).y());
////        qDebug()<<temp;
//        painter.drawEllipse(arr_sh[i].at(i).x(),arr_sh[i].at(i).y(),arr_sh[i].at(i).x()+map->box_h(),arr_sh[i].at(i).y()+map->box_w());
//    }
}

void graf_viev_modicicate::const_pole_initial()
{
    //load from my_map

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
