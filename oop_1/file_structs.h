#ifndef FILE_STRUCTS_H
#define FILE_STRUCTS_H

#include <QString>
#include <QFile>

typedef struct File_s
{
    QFile file;
}File;

typedef struct Filename_s
{
    QString filename;
}Filename;


#endif // FILE_STRUCTS_H
