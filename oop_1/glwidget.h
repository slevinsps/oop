#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "point.h"


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    std::vector<Point> points;
};

#endif  // GLWIDGET_H
