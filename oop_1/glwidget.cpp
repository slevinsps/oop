#include "glwidget.h"

#include "mainwindow.h"
#include "coordinates.h"
#include "constants.h"


GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    //connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer.start(16);
    //this->angle = 0;
}


void GLWidget::initializeGL()
{
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);

    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
}


void draw_point(double x, double y)
{
    glVertex2d(x, y);
}

void draw_quad(coord p_1, coord p_2, coord p_3, coord p_4)
{
    glBegin(GL_LINES);
     draw_point(p_1.x, p_1.y);
     draw_point(p_2.x, p_2.y);

     draw_point(p_2.x, p_2.y);
     draw_point(p_3.x, p_3.y);

     draw_point(p_3.x, p_3.y);
     draw_point(p_4.x, p_4.y);

     draw_point(p_4.x, p_4.y);
     draw_point(p_1.x, p_1.y);
    glEnd();
}

void DrawCube(std::vector<coord> points_copy)
{
     // левая грань
     draw_quad(points_copy[0], points_copy[4], points_copy[7], points_copy[3]);
     // правая грань
     draw_quad(points_copy[1], points_copy[2], points_copy[6], points_copy[5]);
     // верхняя грань
     draw_quad(points_copy[0], points_copy[1], points_copy[2], points_copy[3]);
     // нижняя грань
     draw_quad(points_copy[4], points_copy[5], points_copy[6], points_copy[7]);
     // задняя грань
     draw_quad(points_copy[0], points_copy[1], points_copy[5], points_copy[4]);
     // передняя грань
     draw_quad(points_copy[3], points_copy[2], points_copy[6], points_copy[7]);
}


void GLWidget::paintGL()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glColor3f(1.0, 1.0, 1.0);
     if (!points.empty())
        DrawCube(points);

}

void GLWidget::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(X_BORDER_LEFT, X_BORDER_RIGHT, Y_BORDER_LEFT, Y_BORDER_RIGHT, Z_BORDER_LEFT, Z_BORDER_RIGHT);
    glViewport(0, 0, (GLint)w, (GLint)h);
}
