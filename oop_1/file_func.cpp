#include "mainwindow.h"
#include <QFileDialog>
#include "load_save_model.h"
#include "errors.h"
#include "model.h"
#include "file_func.h"
#include "file_structs.h"

int check_empy_file_name(Filename &my_filename)
{
    return my_filename.filename.isEmpty();
}

int get_file_open_name(Filename &my_filename)
{
    Filename my_filename_choose;
    int err = OK;
    my_filename_choose.filename = QFileDialog::getOpenFileName(0,
                                QString::fromUtf8("Load file"),
                                QDir::currentPath(),
                                "(*.txt *.doc);;All files (*.*)");
    if (check_empy_file_name(my_filename_choose))
        err = EMPTY_FILE_NAME;
    if (err == OK)
        my_filename = my_filename_choose;
    return err;
}

int get_file_save_name(Filename &my_filename)
{
    Filename my_filename_choose;
    int err = OK;
    my_filename_choose.filename = QFileDialog::getSaveFileName(0,
                                QString::fromUtf8("Save file"),
                                QDir::currentPath(),
                                "(*.txt *.doc);;All files (*.*)");
    if (check_empy_file_name(my_filename_choose))
        err = EMPTY_FILE_NAME;
    if (err == OK)
        my_filename = my_filename_choose;
    return err;
}

int open_file_read(File &my_file, Filename my_filename)
{
    my_file.file.setFileName(my_filename.filename);
    return my_file.file.open(QIODevice::Text | QIODevice::ReadOnly);
}

int open_file_write(File &my_file, Filename my_filename)
{
    my_file.file.setFileName(my_filename.filename);
    return my_file.file.open(QIODevice::Text | QIODevice::WriteOnly);
}

void close_file(File &my_file)
{
    my_file.file.close();
}

my_QString my_readline(File &my_file)
{
    my_QString my_line;
    my_line.line = my_file.file.readLine();
    return my_line;
}

void my_simplified(my_QString &my_line)
{
    my_line.line.simplified();
}

my_List my_split(my_QString my_line)
{
    my_List my_baList;
    my_baList.baList = my_line.line.split(' ');
    return my_baList;
}

double translate_to_double(my_List my_baList, int i, bool *check)
{
    return my_baList.baList[i].toDouble(check);
}

double translate_to_int(my_List my_baList, int i, bool *check)
{
    return my_baList.baList[i].toInt(check);
}

int read_point(Point &my_point, File &my_file)
{
	int err = OK;
    my_QString my_line;
    my_List my_baList;
    bool check_x;
    bool check_y;
    bool check_z;

    my_line = my_readline(my_file);
    my_simplified(my_line);
    my_baList = my_split(my_line);
    my_point.x = translate_to_double(my_baList, 0, &check_x);
    my_point.y = translate_to_double(my_baList, 1, &check_y);
    my_point.z = translate_to_double(my_baList, 2, &check_z);
	if (!check_x || !check_y || !check_z)
	   err = ERROR_READ_POINTS;
	return err;
}

int read_rib(Model_ribs &ribs, File &my_file)
{
    int err = OK;
    my_QString my_line;
    my_List my_baList;
    bool check_point1;
    bool check_point2;

    my_line = my_readline(my_file);
    my_simplified(my_line);
    my_baList = my_split(my_line);
    ribs.point1 = translate_to_int(my_baList, 0, &check_point1);
    ribs.point2 = translate_to_int(my_baList, 1, &check_point2);
	
	if (!check_point1 || !check_point2)
		err = ERROR_READ_RIBS;
	return err;
}

int read_number(int &num, File &my_file)
{
    my_QString my_line;
    my_List my_baList;
    int err = OK;
    bool check_count;

    my_line = my_readline(my_file);
    my_simplified(my_line);
    my_baList = my_split(my_line);

    num = translate_to_int(my_baList, 0, &check_count);
    if (!check_count)
    {
        err = ERROR_READ_COUNT;
    }
	return err;
}


void write_number(File &my_file, int num)
{
     QTextStream out(&my_file.file);
	 out << num << '\n';
}

void write_rib(File &my_file, Model_ribs ribs)
{
    QTextStream out(&my_file.file);
    out << ribs.point1 << " " << ribs.point2 << '\n';
}


void write_point(File &my_file, Point my_point)
{
    QTextStream out(&my_file.file);
    out << my_point.x << " " << my_point.y << " " << my_point.z << '\n';
}
