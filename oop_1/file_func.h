#ifndef FILE_FUNC
#define FILE_FUNC

#include "model.h"
#include "file_structs.h"

typedef struct my_QString_s
{
    QString line;
}my_QString;

typedef struct my_QList_s
{
    QList<QString> baList;
}my_List;

int get_file_open_name(Filename &my_filename);
int get_file_save_name(Filename &my_filename);
int check_empy_file_name(Filename &my_filename);
int open_file_read(File &my_file, Filename my_filename);
int open_file_write(File &my_file, Filename my_filename);
void close_file(File &my_file);
int read_point(Point &my_point, File &my_file);
int read_rib(Model_ribs &ribs, File &my_file);
int read_number(int &num, File &my_file);
void write_number(File &my_file, int num);
void write_rib(File &my_file, Model_ribs ribs);
void write_point(File &my_file, Point my_point);


#endif // FILE_FUNC
