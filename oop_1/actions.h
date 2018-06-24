#ifndef ACTIONS_H
#define ACTIONS_H

#include "point.h"
#include "model.h"
#include <vector>

void transform3d_to_2d(Model &my_model);
int replace_figure(Model &my_model, Point replace_koef);
int rotate_figure(Model &my_model, Point rotate_koef);
int scale_figure(Model &my_model, Point scale_koef);
Model initialize_model(void);
int copy_model(Model &my_model, Model my_model_load);
int free_model(Model &my_model);


#endif // ACTIONS_H
