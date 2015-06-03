#ifndef SNAKE_H
#define SNAKE_H
#define UP 1
#define DOUN 2
#define LEFT 3
#define RIGHT 4
#include <QObject>
#include <QVector>
#include <QPoint>
#include <QTimer>
#include <QPainter>
class snake : public QObject
{Q_OBJECT
private :
    QPixmap gress;//

    bool change_move;//for 1 litte bug
    QPixmap Snake;
    int move_to;//left,right...
    QVector <QPoint> sh;//shake pos
    QPoint fruit;//random fruit pos
    QTimer *timer;
    bool is_snake_pos(int x,int y);
    bool is_froit_eated();

    void eat_myself();
public:

    explicit snake(QObject *parent = 0);
    void start_move();
    ~snake();
    void new_move_to(QPoint *);
    void start_pos();

    bool complete_level();
    void new_fruit();

    int get_fruit_x(){return fruit.x();}
    int get_fruit_y(){return fruit.y();}

    int size_snake();
    QPoint *get_sh(int i);
void paint_snake(QPainter * paint, int x, int y, int x2, int y2);

signals:
    void level_up();

public slots:
    void on_snake_move();
};

#endif // SNAKE_H
