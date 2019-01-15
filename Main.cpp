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
#include "MyClientHandler.h"
#include "SearcherSolver.h"
#include "Point.h"
#include "Searcher.h"
#include "BFS.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "Astar.h"
#include "MyParallelServer.h"


namespace boot {
    class Main {
    public:
        int main(int port) {
            Solver<Searchable<Point>*, SearchResult> *solver = new SearcherSolver<Point>(new Astar<Point>());
            CacheManager *cacheManager = new FileCacheManager();
            ClientHandler *ClientHandler = new MyClientHandler(solver, cacheManager);
            server_side::MyParallelServer* parallelServer = new server_side::MyParallelServer();
            parallelServer->open(port, ClientHandler);
            std::this_thread::sleep_for(std::chrono::milliseconds(10000));
            parallelServer->stop();
            delete(solver);
            delete(cacheManager);
            delete(ClientHandler);
            delete(parallelServer);
            return 0;
        }
    };
}