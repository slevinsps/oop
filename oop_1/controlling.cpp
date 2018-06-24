#include "controlling.h"
#include "point.h"
#include "actions.h"
#include "load_save_model.h"
#include "errors.h"
#include "draw_model.h"
#include "model.h"
#include <QGraphicsScene>
#include <QDebug>
#include "file_func.h"
#include "file_structs.h"
#include "my_scene.h"

int controlling_center( My_Scene &my_scene, type_action act, Point coefficient_model )
{
    static Filename my_filename = {NULL};
    static Model my_model = initialize_model();

    int err = OK;
    switch (act)
    {
        case CHOOSE_OPEN_FILE:
            err = get_file_open_name(my_filename);
            break;
        case LOAD:
            err = load_model(my_model, my_filename);
            break;
        case ROTATE:
            err = rotate_figure(my_model, coefficient_model);
            break;
        case MOVE:
            err = replace_figure(my_model, coefficient_model);
            break;
        case SCALE:
            err = scale_figure(my_model, coefficient_model);
            break;
        case DRAW:
            err = draw_figure(my_scene, my_model);
            break;
        case CHOOSE_SAVE_FILE:
            err = get_file_save_name(my_filename);
            break;
        case SAVE:
            err = save_model(my_model, my_filename);
            break;
        case FREE:
            err = free_model(my_model);
            break;
        default:
            err = INCORRECT_COMAND;
            break;
    }
    return err;
}

