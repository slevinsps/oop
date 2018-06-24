#ifndef LOAD_SAVE_FILE_H
#define LOAD_SAVE_FILE_H

#include "point.h"
#include "model.h"
#include "file_structs.h"

int save_model(Model my_model, Filename my_filename);
int load_model(Model &my_model, Filename my_filename);

#endif // LOAD_SAVE_FILE_H
