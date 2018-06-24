#ifndef UPLOAD_EXCEPTIONS_HPP
#define UPLOAD_EXCEPTIONS_HPP

#include "base_exception.hpp"

class base_stream_exception : public base_exception {
    public:
        explicit base_stream_exception() = default;

        explicit base_stream_exception(const char* message)
            : base_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "uploader::(base stream exception)!" : message.c_str();
        }
};

class open_stream_exception : public base_stream_exception {
    public:
        explicit open_stream_exception() = default;

        explicit open_stream_exception(const char* message)
            : base_stream_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "uploader::(opening stream exception)!" : message.c_str();
        }
};

class read_stream_exception : public base_stream_exception {
    public:
        explicit read_stream_exception() = default;

        explicit read_stream_exception(const char* message)
            : base_stream_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "uploader::(reading stream exception)!" : message.c_str();
        }
};

class close_stream_exception : public base_stream_exception {
    public:
        explicit close_stream_exception() = default;

        explicit close_stream_exception(const char* message)
            : base_stream_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "uploader::(closing stream exception)!" : message.c_str();
        }
};

class json_exception : public base_stream_exception {
    public:
        explicit json_exception() = default;

        explicit json_exception(const char* message)
            : base_stream_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "uploader::jsmn::(error parsing json)!" : message.c_str();
        }
};

#endif // UPLOAD_EXCEPTIONS_HPP
