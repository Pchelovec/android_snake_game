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
public:
    view();
    ~view();
    void rect(QBrush br, QColor pen_color,int x,int y,int x2,int y2);
    void elipse(QPainter *paint,QBrush br, QColor pen_color,int x,int y,int x2,int y2);
    QPixmap * get_pix_map();
    void paint_snake(snake *sh,QPainter*paint,int x,int y);

public slots:
    void on_size_change();
};

#endif // VIEV_H
