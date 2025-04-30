#include <iostream>
#include <boost/filesystem/operations.hpp>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "[Usage]\n" << argv[0] << " [file_path]" << std::endl;
        return 1;
    }

    boost::filesystem::path file_path(argv[1]);

    try {
        if (boost::filesystem::exists(file_path)) {
            std::cout << "[Given File]\n" << boost::filesystem::absolute(file_path)
                << "\n\n[Size in bytes]\n" << boost::filesystem::file_size(file_path) << std::endl;
        } else {
            std::cerr << "[Error]\nFile not found." << std::endl;
            return 1;
        }
    } catch (const boost::filesystem::filesystem_error &e) {
        std::cerr << "[Error]\n" << e.what() << std::endl;
        return 1;
    }

    return 0;
}
