#ifndef BASE_UPLOADER_HPP
#define BASE_UPLOADER_HPP

#include "objects/model.hpp"

class base_uploader {
    public:
        base_uploader() = default;
        base_uploader(base_uploader&) = delete;
        base_uploader(const base_uploader&) = delete;
        virtual ~base_uploader() = default;

        virtual void open() = 0;
        virtual model get_model() = 0;
        virtual void close() = 0;
};

#endif // BASE_UPLOADER_HPP
