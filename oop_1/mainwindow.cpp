#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "math.h"
#include "glwidget.h"
#include "QStandardItemModel"
#include "QStandardItem"
#include <QMessageBox>
#include <QFileDialog>

#include "point.h"
#include "actions.h"
#include "load_save_model.h"
#include "controlling.h"
#include "errors.h"
#include "constants.h"
#include "my_scene.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_scene.scene = new QGraphicsScene(this);
    my_scene.scene->setSceneRect(X_RECTANGLE_AREA, Y_RECTANGLE_AREA, W_RECTANGLE_AREA, H_RECTANGLE_AREA);
    ui->graphicsView->setScene(my_scene.scene);
}

MainWindow::~MainWindow()
{
    Point coefficient_model;
    controlling_center(my_scene, FREE, coefficient_model);
    delete ui;
}


void MainWindow::show_message(QString message)
{
     QMessageBox::information(this, "Ошибка", message, "Ok");
}


int MainWindow::on_pushButton_replace_clicked()
{
    int err = OK;

    QString d_x_s = ui->lineEdit_x->text();
    QString d_y_s = ui->lineEdit_y->text();
    QString d_z_s = ui->lineEdit_z->text();

    double d_x, d_y, d_z;
    bool ok;
    d_x = d_x_s.toDouble(&ok);
    if (!ok)
    {
        show_message("Неверно введен d_x!");
        return ERROR_INPUT_MOVE;
    }
    d_y = d_y_s.toDouble(&ok);
    if (!ok)
    {
        show_message("Неверно введен d_y!");
        return ERROR_INPUT_MOVE;
    }
    d_z = d_z_s.toDouble(&ok);
    if (!ok)
    {
        show_message("Неверно введен d_z!");
        return ERROR_INPUT_MOVE;
    }

    Point coefficient_model;
    coefficient_model.x = d_x;
    coefficient_model.y = d_y;
    coefficient_model.z = d_z;
    err = controlling_center(my_scene, MOVE, coefficient_model);
    if (err == OK)
        err = controlling_center(my_scene, DRAW, coefficient_model);
    switch(err)
    {
        case(EMPTY_POINTS):
        {
            show_message("Модель не загружена!");
            break;
        }
    }
    return err;
}

int MainWindow::on_pushButton_rot_clicked()
{
    int err = OK;

    QString d_x_s = ui->lineEdit_x_r->text();
    QString d_y_s = ui->lineEdit_y_r->text();
    QString d_z_s = ui->lineEdit_z_r->text();

    double x_angle, y_angle, z_angle;
    bool ok;
    x_angle = d_x_s.toDouble(&ok);
    if (!ok)
    {
        show_message("Неверно введен angle_x!");
        return ERROR_INPUT_ROT;
    }
    y_angle = d_y_s.toDouble(&ok);
    if (!ok)
    {
        show_message("Неверно введен angle_y!");
        return ERROR_INPUT_ROT;
    }
    z_angle = d_z_s.toDouble(&ok);
    if (!ok)
    {
        show_message("Неверно введен angle_z!");
        return ERROR_INPUT_ROT;
    }

    Point coefficient_model;
    coefficient_model.x = x_angle;
    coefficient_model.y = y_angle;
    coefficient_model.z = z_angle;

    err = controlling_center(my_scene, ROTATE, coefficient_model);
    if (err == OK)
        err = controlling_center(my_scene, DRAW, coefficient_model);
    switch(err)
    {
        case(EMPTY_POINTS):
        {
            show_message("Модель не загружена!");
            break;
        }
    }
    return err;
}

int MainWindow::on_pushButton_scale_clicked()
{

    int err = OK;

    QString k_x_s = ui->lineEdit_x_s->text();
    QString k_y_s = ui->lineEdit_y_s->text();
    QString k_z_s = ui->lineEdit_z_s->text();

    bool ok;
    double k_x = k_x_s.toDouble(&ok);
    if (!ok)
    {
        show_message("Неверно введен k_x!");
        return  ERROR_INPUT_SCALE;
    }
    double k_y = k_y_s.toDouble(&ok);
    if (!ok)
    {
        show_message("Неверно введен k_y!");
        return ERROR_INPUT_SCALE;
    }
    double k_z = k_z_s.toDouble(&ok);
    if (!ok)
    {
        show_message("Неверно введен k_z!");
        return ERROR_INPUT_SCALE;
    }

    if (k_x == 0 || k_y == 0 || k_z == 0)
    {
        show_message("Коэфициент не может быть равен 0");
        return KOEF_SCALE_ZERO;
    }

    Point coefficient_model;
    coefficient_model.x = k_x;
    coefficient_model.y = k_y;
    coefficient_model.z = k_z;

    err = controlling_center(my_scene, SCALE, coefficient_model);
    if (err == OK)
        err = controlling_center(my_scene, DRAW, coefficient_model);
    switch(err)
    {
        case(EMPTY_POINTS):
        {
            show_message("Модель не загружена!");
            break;
        }
    }

    return err;
}

int MainWindow::on_pushButton_save_clicked()
{
    int err = OK;
    Point coefficient_model;
    err = controlling_center(my_scene, CHOOSE_SAVE_FILE, coefficient_model);
    if (err == OK)
    {
        err = controlling_center(my_scene, SAVE, coefficient_model);
        switch(err)
        {
            case(DONT_CREATE_FILE):
            {
                show_message("Невозможно создать файл!");
                break;
            }
        }
    }

    return err;
}


int MainWindow::on_pushButton_load_clicked()
{
    int err = OK;
    Point coefficient_model;
    err = controlling_center(my_scene, CHOOSE_OPEN_FILE, coefficient_model);
    if (err == OK)
    {
        err = controlling_center(my_scene, LOAD, coefficient_model);
        switch(err)
        {
            case(OK):
            {
                controlling_center(my_scene, DRAW, coefficient_model);
                break;
            }
            case(ERROR_READ_COUNT_POINTS):
            {
                show_message("Неверно введено количество точек!");
                break;
            }
            case(ERROR_READ_COUNT_RIBS):
            {
                show_message("Неверно введено количество ребер!");
                break;
            }
            case(ERROR_READ_POINTS):
            {
                show_message("Ошибка в списке точек!");
                break;
            }
            case(ERROR_READ_RIBS):
            {
                show_message("Ошибка в списке ребер!");
                break;
            }
            case(DONT_OPEN_FILE):
            {
                show_message("Невозможно откыть файл!");
                break;
            }
            case(INCORRECT_NUMBER_OF_RIBS):
            {
                show_message("Некорректный номер точки в списке ребер!");
                break;
            }
            default:
                break;
        }
    }
    return err;
}
