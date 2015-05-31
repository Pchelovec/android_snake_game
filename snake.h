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
class snake : public QObject
{
private :
    int speed;
    int length;
    int move_to;//left,right...
    QVector <QPoint> sh;//shake pos
    QPoint fruit;//random fruit pos
    Q_OBJECT
public:
    explicit snake(QObject *parent = 0);
    void new_move_to(QPoint *);
    void paint_snake(QPainter * paint, int ,int);
    bool is_correct_head_pos();
    QVector <QPoint> * snake_koord();
    QPoint head_pos();
    ~snake();

signals:

public slots:
    //void on_snake_move();
};

#endif // SNAKE_H
