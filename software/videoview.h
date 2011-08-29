#ifndef VIDEOVIEW_H
#define VIDEOVIEW_H

#include <QWidget>
#include <QMouseEvent>
#include <QWheelEvent>

class VideoView : public QWidget
{
    Q_OBJECT
public:
    explicit VideoView(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
signals:

public slots:

};

#endif // VIDEOVIEW_H
