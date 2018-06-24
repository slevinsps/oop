#ifndef CONTROLLING_H
#define CONTROLLING_H

#include "point.h"
#include "my_scene.h"
#include <QGraphicsScene>


enum type_action { ROTATE, LOAD, MOVE, SCALE, SAVE, DRAW, CHOOSE_SAVE_FILE, CHOOSE_OPEN_FILE, FREE};
int controlling_center( My_Scene &my_scene, type_action act, Point coefficient_model );

#endif // CONTROLLING_H
