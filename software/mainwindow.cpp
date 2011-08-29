#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "microview.h"
#include <gst/gst.h>
#include <gst/interfaces/xoverlay.h>
#include <QMessageBox>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gst_init (NULL,NULL);

    GstElement *GSTpipeline = gst_pipeline_new ("pipeline");
    g_assert(GSTpipeline);
    GstElement *GSTsource = gst_element_factory_make("v4l2src", "source");
    g_assert(GSTsource);
    GstElement *GSTdest = gst_element_factory_make("xvimagesink", "view");
    g_assert(GSTdest);

    gst_bin_add_many(GST_BIN(GSTpipeline), GSTsource, GSTdest, NULL);
    gst_element_link_many(GSTsource, GSTdest, NULL);

    unsigned long win_id = ui->wgtVideo->winId();
    QApplication::syncX();
    gst_x_overlay_set_xwindow_id(GST_X_OVERLAY(GSTdest), win_id);

    gst_element_set_state(GST_ELEMENT(GSTpipeline), GST_STATE_PLAYING);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_pushExit_clicked()
{
    close();
}

void MainWindow::on_pushAbout_clicked()
{
    QMessageBox aboutBox(QMessageBox::NoIcon, "About µView", QString::fromUtf8("µView\n\nhackerspace brmlab - http://brmlab.cz/\n\nSee README for more info and COPYING for the license." ), QMessageBox::Ok, this);
    aboutBox.setIconPixmap(QPixmap(":/icons/icon.png"));
    aboutBox.exec();
}

void MainWindow::on_pushL_clicked()
{
    qDebug() << MSG_LEFT;
}

void MainWindow::on_pushR_clicked()
{
    qDebug() << MSG_RIGHT;
}

void MainWindow::on_pushU_clicked()
{
    qDebug() << MSG_UP;
}

void MainWindow::on_pushD_clicked()
{
    qDebug() << MSG_DOWN;
}

void MainWindow::on_pushZoomIn_clicked()
{
    qDebug() << MSG_PLUS;
}

void MainWindow::on_pushZoomOut_clicked()
{
    qDebug() << MSG_MINUS;
}

void MainWindow::on_pushSnap_clicked()
{
    qDebug() << MSG_SNAP;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_A:
        on_pushL_clicked();
        break;
    case Qt::Key_S:
        on_pushD_clicked();
        break;
    case Qt::Key_D:
        on_pushR_clicked();
        break;
    case Qt::Key_W:
        on_pushU_clicked();
        break;
    case Qt::Key_O:
        on_pushZoomIn_clicked();
        break;
    case Qt::Key_L:
        on_pushZoomOut_clicked();
        break;
    case Qt::Key_Y:
        on_pushSnap_clicked();
        break;
    }
}
