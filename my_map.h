#ifndef MY_MAP_H
#define MY_MAP_H
#include <QPixmap>
#include <QPainter>
#include <QPoint>
#define total_level_count 2//leves in game
//40 50 pixels 1 box
//15 20 boxes
class my_map
{
private:
    QPainter *paint;
    QPixmap *pix_map;
    static int w_box,h_box;
//logic map arr
    static int count_box_w,count_box_h;//for current leve
    static int pix_dop_x,pix_dop_y;//остаток
    static int leng_for_complete_level;
    static int current_player_level;
    void count_initial_size();
    void write_current_level();
public:
    my_map();
    ~my_map();
    void level1();
    void level2();

    static int box_w();
    static int box_h();
    void set_count_box(QPoint * screen_size);
    QPixmap* map();
    static int x_extra();
    static int y_extra();

    static int get_count_box_h();
    static int get_count_box_w();

    static int get_comlete_snake_leng();
    static int get_current_level();
public slots:
    void on_size_change();
    void on_level_up();

};

#endif // MY_MAP_H
