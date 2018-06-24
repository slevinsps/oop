#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include "my_scene.h"

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


    int on_pushButton_replace_clicked();

    int on_pushButton_rot_clicked();

    int on_pushButton_scale_clicked();

    int on_pushButton_save_clicked();

    int on_pushButton_load_clicked();

    void show_message(QString message);

private:
    Ui::MainWindow *ui;
    My_Scene my_scene;

};

#endif // MAINWINDOW_H
