#ifndef SNAKE_H
#define SNAKE_H
#define UP 1
#define DOUN 2
#define LEFT 3
#define RIGHT 4
#include <QObject>
#include <QVector>
#include <QPoint>
#include <QPainter>
#include <QTimer>
class snake : public QObject
{Q_OBJECT
private :
    int length;
    int move_to;//left,right...
    QVector <QPoint> sh;//shake pos
    QPoint fruit;//random fruit pos
    QTimer *timer;
    bool is_snake_pos(int x,int y);
    bool is_froit_eated();
public:
    explicit snake(QObject *parent = 0);
    void new_move_to(QPoint *);
    void paint_snake(QPainter * paint, int ,int);
    bool is_correct_head_pos();
    QVector <QPoint> * snake_koord();
    void start_move();
    void paint_froit(QPainter * paint,int x,int y);
    QPoint head_pos();
    bool complete_level();
    void new_fruit();
    void start_pos();
    ~snake();

signals:
    void level_up();

public slots:
    void on_snake_move(void );
};

#endif // SNAKE_H
