#include "videoview.h"
#include "microview.h"
#include <qdebug.h>

VideoView::VideoView(QWidget *parent) :
    QWidget(parent)
{
}

void VideoView::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << event->pos();
}

void VideoView::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0) {
        qDebug() << MSG_PLUS;
    } else
    if (event->delta() < 0) {
        qDebug() << MSG_MINUS;
    }
}
