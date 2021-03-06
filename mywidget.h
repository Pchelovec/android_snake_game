#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QtGui>
#include <QWidget>
#include <QTimer>
#include "game.h"

class MyWidget : public QWidget
{
    Q_OBJECT
public:
   MyWidget();

protected:
    QTimer *timer;
    game * table;
    void paintEvent(QPaintEvent *event);
    void mousePressEvent ( QMouseEvent * event );
    void mouseReleaseEvent ( QMouseEvent * event );
    void resizeEvent(QResizeEvent *);
signals:

public
    slots:

};

#endif // MYWIDGET_H
