//
// Created by yael on 1/6/19.
//

#include "MyTestClientHandler.h"
#include "TcpServer.h"
#include <algorithm>

void MyTestClientHandler::handleClient(int cliSocket) {
    std::string problem;
    std::string solution;
    problem = server_side::TcpServer::readLine(cliSocket);
    while (problem.compare("end")) {
        if (!problem.compare("")) {
            problem = server_side::TcpServer::readLine(cliSocket);
            continue;
        }
        if (cache->findSolution(problem)) {
            solution = cache->getSolution(problem);
        } else {
            solution = this->solver->solve(problem);
            cache->storeSolution(problem, solution);
        }
        server_side::TcpServer::writeToClient(cliSocket, solution);
        server_side::TcpServer::writeToClient(cliSocket, "\n");
        problem = server_side::TcpServer::readLine(cliSocket);
    }
}

CacheManager* MyTestClientHandler::getCache() {
    return this->cache;
}

MyTestClientHandler::~MyTestClientHandler() {
    delete cache;
}