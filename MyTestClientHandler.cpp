//
// Created by yael on 1/6/19.
//

#include "MyTestClientHandler.h"
#include "TcpServer.h"
#include <algorithm>
//todo
//איפה ומתי מזינים לקלאס את הקאש והסולבר
void MyTestClientHandler::handleClient(int cliSocket) {
    std::string problem = "";
    std::string solution;
    while (problem != "end") {
        problem = server_side::TcpServer::readLine(cliSocket);
        if (cache->findSolution(&problem)) {
            solution = cache->getSolution(&problem);
        } else {
            solution = this->solver->solve(problem);
            cache->storeSolution(&problem, &solution);
        }
    }
    // write to client.
}