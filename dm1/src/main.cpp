#include <iostream>
#include "app.hpp"

int main(int argc, char** argv) {
    try {
        DemoApplication app;
        app.run();
        return 0;
    }
    catch (const std::exception& ex) {
        std::cerr << ">>>>>>>>>>>>>>>>>>>>\n" << ex.what() << std::endl;
        return -1;
    }
}


