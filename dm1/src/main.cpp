#include "app.hpp"

int main(int argc, char** argv) {
    try {
        DemoApplication app;
        app.run();
        return 0;
    }
    catch (const std::exception& ex) {
        return -1;
    }
}


