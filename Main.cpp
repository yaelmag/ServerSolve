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
#include "AStar.h"
#include "MyParallelServer.h"


namespace boot {
    class Main {
    public:
        int main(int port) {
            Solver<Searchable<Point>*, SearchResult> *solver = new SearcherSolver<Point>(new AStar<Point>());
            CacheManager *cacheManager = new FileCacheManager();
            ClientHandler *clientHandler = new MyClientHandler(solver, cacheManager);
            server_side::MyParallelServer* myParallelServer = new server_side::MyParallelServer();
            myParallelServer->open(port, clientHandler);
            myParallelServer->stop();
            delete(solver);
            delete(cacheManager);
            delete(clientHandler);
            delete(myParallelServer);
            return 0;
        }
    };
}