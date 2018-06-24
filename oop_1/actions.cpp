#include <vector>
#include <math.h>
#include <cstdlib>
#include <QDebug>
#include "constants.h"
#include "actions.h"
#include "errors.h"
#include "model.h"

void transform3d_to_2d(Model &my_model)
{
    double A, B, C, D;
    double x1 = 2, x2 = 10, x0 = 5;
    double y1 = 10, y2 = 4, y0 = 12;
    double z1 = 0, z2 = 0, z0 = 0;

    A=(y1-y0)*(z2-z0)-(z1-z0)*(y2-y0);
    B=(z1-z0)*(x2-x0)-(x1-x0)*(z2-z0);
    C=(x1-x0)*(y2-y0)-(y1-y0)*(x2-x0);
    D=-(A*x0+B*y0+C*z0);

    double xp, yp, zp;
    double xpp, ypp, zpp;
    double a1;
    double a2;

    for(int i = 0; i < my_model.n_points; i++)
    {
        xp = my_model.points[i].x;
        yp = my_model.points[i].y;
        zp = my_model.points[i].z;

        if (C!=0)
        {
           a1 = C*yp-B*zp;
           a2 = C*xp-A*zp;

           zpp=-(A*a2+B*a1+D*C)/(A*A+B*B+C*C);
           ypp=(B*zpp+a1)/C;
           xpp=(A*zpp+a2)/C;
        }
        else
        {
           if (B!=0)
           {
              a1 = B*xp-A*yp;
              a2 = B*zp;
              ypp=-(A*a1+D*B)/(A*A+B*B);
              xpp=(A*ypp+a1)/B;
              zpp=a2/B;
           }
           else
           {
              a1 = A*yp;
              a2 = A*zp;
              xpp = -D/A;
              ypp = a1/A;
              zpp= a2/A;
           }
        }
        my_model.points[i].x = xpp;
        my_model.points[i].y = ypp;
        my_model.points[i].z = zpp;
    }
}


int find_center(Model my_model, Point &center_model)
{
    Point *points = my_model.points;
    int err = OK;

    if (!my_model.points)
        err = EMPTY_POINTS;
    else
    {
        double min_x = points[0].x;
        double max_x = points[0].x;
        double min_y = points[0].y;
        double max_y = points[0].y;
        double min_z = points[0].z;
        double max_z = points[0].z;

        for (int i = 1; i < my_model.n_points; i++)
        {
            if (min_x > points[i].x)
                min_x = points[i].x;
            if (max_x < points[i].x)
                max_x = points[i].x;

            if (min_y > points[i].y)
                min_y = points[i].y;
            if (max_y < points[i].y)
                max_y = points[i].y;

            if (min_z > points[i].z)
                min_z = points[i].z;
            if (max_z < points[i].z)
                max_z = points[i].z;
        }

        center_model.x = (min_x + max_x) / 2;
        center_model.y = (min_y + max_y) / 2;
        center_model.z = (min_z + max_z) / 2;
    }
    return err;
}

int replace_figure(Model &my_model, Point replace_koef)
{
    int err = OK;
    if (!my_model.points)
        err = EMPTY_POINTS;
    else
    {
        for (int i = 0; i < my_model.n_points; i++)
        {
            my_model.points[i].x += replace_koef.x;
            my_model.points[i].y += replace_koef.y;
            my_model.points[i].z += replace_koef.z;
        }
        //transform3d_to_2d(my_model);
    }
    return err;
}


void rotate_figure_x(Point &coord_point, Point center_model, double x_angle)
{
    double y_d = coord_point.y;
    double z_d = coord_point.z;

    coord_point.y = center_model.y + (y_d - center_model.y)*cos(x_angle) + (z_d - center_model.z)*sin(x_angle);
    coord_point.z = center_model.z - (y_d - center_model.y)*sin(x_angle) + (z_d - center_model.z)*cos(x_angle);
}

void rotate_figure_y(Point &coord_point, Point center_model, double y_angle)
{
    double x_d = coord_point.x;
    double z_d = coord_point.z;

    coord_point.x = center_model.x + (x_d - center_model.x) *cos(y_angle) + (z_d - center_model.z)*sin(y_angle);
    coord_point.z = center_model.z - (x_d - center_model.x)*sin(y_angle) + (z_d - center_model.z)*cos(y_angle);
}

rotate_figure_z(Point &coord_point, Point center_model, double z_angle)
{
    double x_d = coord_point.x;
    double y_d = coord_point.y;

    coord_point.x = center_model.x + (x_d - center_model.x)*cos(z_angle) - (y_d - center_model.y)*sin(z_angle);
    coord_point.y = center_model.y + (y_d - center_model.y)*cos(z_angle) + (x_d - center_model.x)*sin(z_angle);
}


double from_grad_to_rad(double grad)
{
    return (grad / 180) * PI;
}

int rotate_figure(Model &my_model, Point rotate_koef)
{
    int err = OK;
    if (!my_model.points)
        err = EMPTY_POINTS;
    else
    {
        Point center_model;
        find_center(my_model, center_model);
        //qDebug() << "center = " << center_model.x << ' ' << center_model.y << ' ' << center_model.z;
        rotate_koef.x = from_grad_to_rad(rotate_koef.x);
        rotate_koef.y = from_grad_to_rad(rotate_koef.y);
        rotate_koef.z = from_grad_to_rad(rotate_koef.z);

        for (int i = 0; i < my_model.n_points; i++)
        {
            rotate_figure_x(my_model.points[i], center_model, rotate_koef.x);
            rotate_figure_y(my_model.points[i], center_model, rotate_koef.y);
            rotate_figure_z(my_model.points[i], center_model, rotate_koef.z);
        }
    }
    return err;
}


double scale_formula(double begin_coord, double koef, double center_coord)
{
    return begin_coord * koef + (1 - koef) * center_coord;
}
int scale_figure(Model &my_model, Point scale_koef)
{
    int err = OK;
    if (!my_model.points)
        err = EMPTY_POINTS;
    else
    {
        Point center_model;
        find_center(my_model, center_model);
        for (int i = 0; i < my_model.n_points; i++)
        {

            my_model.points[i].x = scale_formula(my_model.points[i].x, scale_koef.x, center_model.x);
            my_model.points[i].y = scale_formula(my_model.points[i].y, scale_koef.y, center_model.y);
            my_model.points[i].z = scale_formula(my_model.points[i].z, scale_koef.z, center_model.z);
        }
    }
    return err;
}

Model initialize_model(void)
{
    Model my_model;
    my_model.n_points = 0;
    my_model.points = NULL;
    my_model.n_ribs = 0;
    my_model.ribs = NULL;
    return my_model;
}

int free_model(Model &my_model)
{
    int err = OK;
    free(my_model.points);
    free(my_model.ribs);
    return err;
}

int copy_model(Model &my_model, Model my_model_load)
{
	int err = OK;
    free_model(my_model);
    my_model = my_model_load;
    return err;
}





