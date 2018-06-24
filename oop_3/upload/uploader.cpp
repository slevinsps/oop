#include "uploader.hpp"
#include <QDebug>
#include <stdio.h>

uploader::uploader(std::string file_name) : base_uploader(), file_name(file_name) {
}

model uploader::load_model() {
    std::string model_name = "model";
    pair<point3d<double>, point3d<double>> points;
    vector<pair<point3d<double>, point3d<double>>> lines;
    point3d<double> point1;
    point3d<double> point2;
    int n;
    double x, y, z;
    if (fscanf(f,"%d",&n) != 1)
        throw read_stream_exception();
    qDebug() << n;

    for(int i = 0; i < n; i++)
    {
        if (fscanf(f,"%lf %lf %lf",&x, &y, &z) != 3)
            throw read_stream_exception();
        point1.set_x(x);  point1.set_y(y);  point1.set_z(z);
        points.set_first(point1);

        if (fscanf(f,"%lf %lf %lf",&x, &y, &z) != 3)
            throw read_stream_exception();
        point2.set_x(x);  point2.set_y(y);  point2.set_z(z);
        points.set_second(point2);
        //qDebug() << points.get_first().get_x() << " " << points.get_first().get_y() << " " << points.get_first().get_z() << " // " << points.get_second().get_x() << " " << points.get_second().get_y() << " " << points.get_second().get_z();
        lines.push_back(points);
    }

    for(int i = 0; i < lines.size(); i++)
    {
        qDebug() << lines[i].get_first().get_x() << " " << lines[i].get_first().get_y() << " " << lines[i].get_first().get_z() << " // " << lines[i].get_second().get_x() << " " << lines[i].get_second().get_y() << " " << lines[i].get_second().get_z();
    }
    return model(model_name, lines);
}

void uploader::open() {
    const char * f_name = this->file_name.c_str();
    f = fopen(f_name,"r");
    if (!f)
        throw open_stream_exception();
}

model uploader::get_model() {
    return this->load_model();
}

void uploader::close() {
    try {
        fclose(f);
    } catch (std::ifstream::failure& e) {
        throw close_stream_exception();
    }
}
