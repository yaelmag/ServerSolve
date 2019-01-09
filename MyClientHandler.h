//
// Created by adi on 09/01/19.
//

#ifndef PROJECT2_MYCLIENTHANDLER_H
#define PROJECT2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "State.h"
#include "Point.h"
#include <vector>
#include <string>

class MyClientHandler : ClientHandler {
    std::vector<std::vector<State<Point>>> matrix;
public:
    void handleClient(int cliSocket) override;
    void addLine(std::string line, int row);
    std::vector<std::string> split(std::string info, char divide);
};


#endif //PROJECT2_MYCLIENTHANDLER_H
