#ifndef UPLOAD_MANAGER_HPP
#define UPLOAD_MANAGER_HPP

#include "upload/uploader.hpp"

class upload_manager {
    public:
        upload_manager() = default;
        upload_manager(upload_manager&) = delete;
        upload_manager(const upload_manager&) = delete;
        ~upload_manager() = default;

        model upload_model(base_uploader& upldr) {
            upldr.open();
            model m = upldr.get_model();
            upldr.close();

            return m;
        }
};

#endif // UPLOAD_MANAGER_HPP
