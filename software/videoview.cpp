#include "videoview.h"
#include <qdebug.h>

VideoView::VideoView(QWidget *parent) :
    QWidget(parent)
{
}

void VideoView::mouseMoveEvent(QMouseEvent *event)
{
    // TODO: process position
    qDebug() << event->pos();
}

void VideoView::wheelEvent(QWheelEvent *event)
{
    // TODO: process delta
    qDebug() << event->delta();
}
