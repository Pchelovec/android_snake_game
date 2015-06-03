#ifndef VIEV_H
#define VIEV_H
#include <QPixmap>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include "snake.h"
class view
{
private:
    QPainter *ready_map;
    QPixmap *pix_map;
    QPixmap apple;
    QPixmap gress;
    QPixmap box;
    QPixmap Snake;
public:
    view();
    ~view();
    //void rect(int x,int y,int x2,int y2);//old

    QPixmap * get_pix_map();

    void paint_snake(snake *sh,QPainter*paint,int x,int y);

    void paint_good_snake(snake *sh,QPainter*paint,int x,int y,int x2,int y2);
    void paint_good_apple(QPainter *paint,int x,int y,int x2,int y2);
    void set_apple_gress_pixmap();

    void map_good(int x,int y,int x2,int y2);
    void rect_box(int x,int y,int x2,int y2);


    void elipse(QPainter *paint,QBrush br, QColor pen_color,int x,int y,int x2,int y2);//old graphik
public slots:
    void on_size_change();
};

#endif // VIEV_H
