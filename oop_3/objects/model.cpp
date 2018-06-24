#include "model.hpp"

model::model(const std::string& name, const vector<pair<point3d<double>, point3d<double>>>& lines)
    : name(name), lines(lines) {

}

model::model(const model& other)
    : visible_object(), name(other.name), lines(other.lines) {

}

model& model::operator=(const model& other) {
    if (this != &other) {
        this->name = other.name;
        this->lines = other.lines;
    }

    return *this;
}

model& model::operator=(model&& other) {
    if (this != &other) {
        this->name = other.name;
        this->lines = other.lines;
        other.~model();
    }

    return *this;
}
