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
#include "TcpServer.h"
#include "MatrixSearchable.h"
using namespace std;

class MyClientHandler : public ClientHandler {
    vector<vector<State<vector<int>>*>> matrix;
public:
    MyClientHandler() = default;
    void handleClient(int cliSocket) override;
    void addLine(std::string line, int row);
    vector<string> split(string info, char divide);
};


#endif //PROJECT2_MYCLIENTHANDLER_H
