#ifndef FACADE_HPP
#define FACADE_HPP

#include <string>

#include "controller/controller.hpp"
#include "commands/command.hpp"
#include "exceptions/base_exception.hpp"

class Mediator {
    public:
        Mediator() {
            this->__controller = controller::instance();
        }

        Mediator(Mediator&) = delete;
        Mediator(const Mediator&) = delete;

        ~Mediator() {
            delete this->__controller;
        }

        void execute_command(command& c) {
            c.execute(this->__controller);
        }

    private:
        controller* __controller;
};

#endif // FACADE_HPP
