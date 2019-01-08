#include <iostream>
#include <algorithm>
#include <string>
#include "Solver.h"
#include "ReverserSolver.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"

int main() {
    Solver<std::string, std::string>* solver = new ReverserSolver();
    CacheManager* cacheManager = new FileCacheManager();
    ClientHandler* myTestClientHandler = new MyTestClientHandler(solver, cacheManager);
    //myTestClientHandler->handleClient(5400);
    server_side::MySerialServer mySerialServer = server_side::MySerialServer();
    mySerialServer.open(5500, myTestClientHandler);
    std::cout << "inmain" << std::endl;

    return 0;
}