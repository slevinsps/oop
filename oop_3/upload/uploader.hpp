#ifndef UPLOADER_HPP
#define UPLOADER_HPP

#include <fstream>
#include <cstring>
#include <functional>

#include "exceptions/upload_exceptions.hpp"
#include "containers/vector/vector.hpp"
#include "containers/pair/pair.hpp"
#include "objects/model.hpp"
#include "base_uploader.hpp"

class uploader : public base_uploader {
    public:
        explicit uploader(std::string);
        virtual ~uploader() = default;

        void open() override;
        model get_model() override;
        void close() override;

    protected:
        model load_model();

    private:
        std::string file_name;
        FILE *f;
};

#endif // UPLOADER_HPP
