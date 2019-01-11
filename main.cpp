/*#include <iostream>
#include <algorithm>
#include <string>
#include "Solver.h"
#include "ReverserSolver.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "MyClientHandler.h"*/
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

    /*Solver<std::string, std::string>* solver = new ReverserSolver();
    CacheManager* cacheManager = new FileCacheManager();
    ClientHandler* myTestClientHandler = new MyTestClientHandler(solver, cacheManager);
    ClientHandler* c = new MyClientHandler();
    //myTestClientHandler->handleClient(5400);
    server_side::MySerialServer mySerialServer = server_side::MySerialServer();
    mySerialServer.open(5500, c);
    std::cout << "inmain" << std::endl;*/

    return 0;
}