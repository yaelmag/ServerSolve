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
            //todo
            //לכתוב בחזרה למשתמש את הפיתרון
        } else {
            std::string copyProblem = problem;
            std::reverse(copyProblem.begin(), copyProblem.end());
            solution = copyProblem;
            cache->storeSolution(&problem, &solution);
            //todo
            // לאחסן גם במפה שתעודכן בסוף בקובץ
            //לכתוב בחזרה למשתמש את הפיתרון
        }
    }
}