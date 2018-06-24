#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include <vector>

typedef struct Model_ribs_s
{
    int point1;
    int point2;
}Model_ribs;

typedef struct Model_s
{
    Point *points;
    int n_points;
	Model_ribs *ribs;
    int n_ribs;
}Model;

#endif // MODEL_H
