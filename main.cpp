#include "Main.cpp"

int main(int argc, char* argv[]) {
    int port;
    if (argc != 2) {
        std::cout << "invalid number arguments to main";
        return 1;
    }
    try {
        port = atoi(argv[1]);
    } catch (...) {
        std::cout << "atoi error";
        return 1;
    }
    boot::Main().main(port);
    return 0;
}