#ifndef MY_MAP_H
#define MY_MAP_H
#include <QPixmap>
#include <QPainter>
#include <QPoint>

//40 50 pixels 1 box
//15 20 boxes
class my_map
{
private:
    QPainter *paint;
    QPixmap *pix_map;
    static int w_box,h_box;

    int count_box_w,count_box_h;//for current leve
    static int pix_dop_x,pix_dop_y;//остаток
    void count_initial_size();
public:
    my_map();
    ~my_map();
    void level1();
    static int box_w();
    static int box_h();
    void set_count_box(QPoint * screen_size);
    QPixmap* map();
    static int x_extra();
    static int y_extra();
public slots:
    void on_size_change();
};

#endif // MY_MAP_H
