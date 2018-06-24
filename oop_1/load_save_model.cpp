#include "mainwindow.h"
#include <QFileDialog>
#include "load_save_model.h"
#include "constants.h"
#include "errors.h"
#include "model.h"
#include "file_func.h"
#include "file_structs.h"
#include "actions.h"

int save_model(Model my_model, Filename my_filename)
{
    int err = OK;

    File my_file;

    if (!open_file_write(my_file, my_filename)) return DONT_CREATE_FILE;

    write_number(my_file, my_model.n_points);
    for (int i = 0; i < my_model.n_points; i++)
    {
        write_point(my_file, my_model.points[i]);
    }
    write_number(my_file, my_model.n_ribs);
    for (int i = 0; i < my_model.n_ribs; i++)
    {
        write_rib(my_file, my_model.ribs[i]);;
    }
    close_file(my_file);

    return err;
}

int load_points(Model &my_model, File &my_file)
{
    int err = OK;
    Point my_point;

    err = read_number(my_model.n_points, my_file);
    if (err == ERROR_READ_COUNT || my_model.n_points < 0) return ERROR_READ_COUNT_POINTS;

    my_model.points = (Point*)malloc(sizeof(Point) * my_model.n_points);
    if (!my_model.points) return MEMORY_ERROR;

    for (int i = 0; err == OK && i < my_model.n_points; i+=1)
    {
         err = read_point(my_point, my_file);
         if (err == OK)
             my_model.points[i] = my_point;
    }
    if (err != OK)
        free(my_model.points);

    return err;
}

int check_rib_range(Model_ribs ribs, int n_points)
{
    int err = OK;
    if (ribs.point1 < 1 || ribs.point1 > n_points ||
                 ribs.point2 < 1 || ribs.point2 > n_points)
        err = INCORRECT_NUMBER_OF_RIBS;
    return err;
}

int load_ribs(Model &my_model, File &my_file)
{
    int err = OK;
    Model_ribs rib;

    err = read_number(my_model.n_ribs, my_file);
    if (err == ERROR_READ_COUNT || my_model.n_ribs < 0) return ERROR_READ_COUNT_RIBS;

    my_model.ribs = (Model_ribs*)malloc(sizeof(Model_ribs) * my_model.n_ribs);
    if (!my_model.ribs) return MEMORY_ERROR;


    for (int i = 0; err == OK && i < my_model.n_ribs; i++)
    {
        err = read_rib(rib, my_file);
        if (err == OK)
        {
            err = check_rib_range(rib, my_model.n_points);
            if (err == OK)
                my_model.ribs[i] = rib;
        }
    }
    if (err != OK)
        free(my_model.ribs);
    return err;
}


int load_model(Model &my_model, Filename my_filename)
{
    int err = OK;
    Model my_model_load = initialize_model();

    File my_file;

    if (!open_file_read(my_file, my_filename)) return DONT_OPEN_FILE;
 
    err = load_points(my_model_load, my_file);
    if (err == OK)
        err = load_ribs(my_model_load, my_file);
    close_file(my_file);

	if (err == OK)
		copy_model(my_model, my_model_load);

    return err;
}
