//
// Created by yael on 1/6/19.
//

#ifndef PROJECT2_MYTESTCLIENTHANDLER_H
#define PROJECT2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
    Solver<std::string, std::string>* solver;
    CacheManager *cache;
public:
    MyTestClientHandler(Solver<std::string, std::string>* solver, CacheManager* cache) : solver(solver) {
        this->cache = cache;
    }
    void handleClient(int cliSocket) override;
};


#endif //PROJECT2_MYTESTCLIENTHANDLER_H
