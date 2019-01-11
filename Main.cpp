//
// Created by adi on 11/01/19.
//

#include <iostream>
#include <algorithm>
#include <string>
#include "Solver.h"
#include "ReverserSolver.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"

namespace boot {
// the main is over after 3 timeout or after the sleep seconds.
    class Main {
    public:
        int main(int port) {
            Solver<std::string, std::string> *solver = new ReverserSolver();
            CacheManager *cacheManager = new FileCacheManager();
            ClientHandler *myTestClientHandler = new MyTestClientHandler(solver, cacheManager);
            server_side::MySerialServer mySerialServer = server_side::MySerialServer();
            mySerialServer.open(port, myTestClientHandler);
            std::this_thread::sleep_for(std::chrono::milliseconds(10000));
            mySerialServer.stop();
            return 0;
        }
    };
}