#ifndef GRAF_VIEV_MODICICATE_H
#define GRAF_VIEV_MODICICATE_H
#include "snake.h"
#include "my_map.h"

class graf_viev_modicicate
{
private:
    static int h,w;
    snake *sn;
    QPoint *buf_mouse;
    my_map * map;
    int current_player_level;
    int hard;
public:
    graf_viev_modicicate();
    ~graf_viev_modicicate();
    void game_paint(QPainter &);
    void shake_print();
    void const_pole_initial();
    void set_size(int head, int weigth);
    void set_mouse_press(QPoint *);
    void set_mouse_unpress(QPoint *);//change snake
    static QPoint size_screen();
public slots:
};

#endif // GRAF_VIEV_MODICICATE_H
