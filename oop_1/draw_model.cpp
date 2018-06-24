#include "point.h"
#include "errors.h"
#include <QGraphicsScene>
#include <QDebug>
#include "model.h"
#include "actions.h"
#include "my_scene.h"

void clear_scene(My_Scene &my_scene)
{
    my_scene.scene->clear();
}

void draw_line(My_Scene &my_scene, double x1, double y1, double x2, double y2)
{
     QPen blackpen(Qt::black);
     my_scene.scene->addLine(x1, y1, x2, y2, blackpen);
}

int draw_figure(My_Scene &my_scene, Model my_model)
{
    int err = OK;

    double x1, y1, x2, y2;

    Point *points = my_model.points;
    Model_ribs *ribs = my_model.ribs;
    if (!points || !ribs)
        err = EMPTY_POINTS;
    else
    {
        clear_scene(my_scene);
        for(int i = 0; i < my_model.n_ribs; i++)
        {
            x1 = points[ribs[i].point1 - 1].x;
            y1 = points[ribs[i].point1 - 1].y;
            x2 = points[ribs[i].point2 - 1].x;
            y2 = points[ribs[i].point2 - 1].y;
            draw_line(my_scene, x1, y1, x2, y2);
        }
    }
    return err;
}
