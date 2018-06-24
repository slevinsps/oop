#ifndef COMMAND_INTERFACE_HPP
#define COMMAND_INTERFACE_HPP

#include "objects/camera.hpp"

class command_interface {
    public:
        command_interface() = default;
        command_interface(command_interface&) = delete;
        command_interface(const command_interface&) = delete;
        ~command_interface() = default;

        virtual void execute(camera*&) = 0;
};

namespace camera_dimensional_transformations {

    class rot_cam_y : public command_interface {
        public:
            rot_cam_y(double angle) : angle(angle) {}
            rot_cam_y(rot_cam_y&) = delete;
            rot_cam_y(const rot_cam_y&) = delete;
            ~rot_cam_y() = default;

            void execute(camera*& c) override {
                c->rot_cam_y(angle);
            }

        private:
            double angle;
    };

    class rot_cam_x : public command_interface {
        public:
            rot_cam_x(double angle) : angle(angle) {}
            rot_cam_x(rot_cam_x&) = delete;
            rot_cam_x(const rot_cam_x&) = delete;
            ~rot_cam_x() = default;

            void execute(camera*& c) override {
                c->rot_cam_x(angle);
            }

        private:
            double angle;
    };

    class rot_cam_z : public command_interface {
        public:
            rot_cam_z(double angle) : angle(angle) {}
            rot_cam_z(rot_cam_z&) = delete;
            rot_cam_z(const rot_cam_z&) = delete;
            ~rot_cam_z() = default;

            void execute(camera*& c) override {
                c->rot_cam_z(angle);
            }

        private:
            double angle;
    };
}

#endif // COMMAND_INTERFACE_HPP
