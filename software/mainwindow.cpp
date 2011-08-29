#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <gst/gst.h>
#include <gst/interfaces/xoverlay.h>

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
