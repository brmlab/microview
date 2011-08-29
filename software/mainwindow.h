#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushExit_clicked();
    void on_pushAbout_clicked();
    void on_pushL_clicked();
    void on_pushR_clicked();
    void on_pushU_clicked();
    void on_pushD_clicked();
    void on_pushZoomIn_clicked();
    void on_pushZoomOut_clicked();
    void on_pushSnap_clicked();
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
