#include <QApplication>

#include "gui/mainwindow.hpp"
#include "facade/Mediator.hpp"
#include "commands/command.hpp"

int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    MainWindow window;
    window.show();

    return application.exec();
}
