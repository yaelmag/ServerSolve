//
// Created by adi on 09/01/19.
//

#include "MyClientHandler.h"
#include <string>
#include "TcpServer.h"
#include "MatrixSearchable.h"


void MyClientHandler::handleClient(int cliSocket) {
    string line;
    vector<string> s, e;
    vector<int> startV, endV;
    int row;
    row = 0;
    line = server_side::TcpServer::readLine(cliSocket);

    // read all the matrix
    while (line != "end") {
        this->addLine(line, row);
        line = server_side::TcpServer::readLine(cliSocket);
        row++;
    }
    // read the start point
    line = server_side::TcpServer::readLine(cliSocket);
    s = split(line, ',');
    //Point startP = Point(stoi(s[0]), stoi(s[1]));
    startV.push_back(stoi(s[0]));
    startV.push_back(stoi(s[1]));
    State<vector<int>> *start1 = this->matrix[startV[0]][startV[1]];

    // read the end point
    line = server_side::TcpServer::readLine(cliSocket);
    e = split(line, ',');
    //Point endP = Point(stoi(e[0]), stoi(e[1]));
    endV.push_back(stoi(e[0]));
    endV.push_back(stoi(e[1]));
    State<vector<int>> *end1 = this->matrix[endV[0]][endV[1]];

    MatrixSearchable<vector<int>>* m = new MatrixSearchable <vector<int>>(this->matrix, start1, end1);
    m->printMatrix();
}

void MyClientHandler::addLine(std::string line, int row) {
    vector<string> allNums = split(line, ',');

    double cost;
    vector<int> place;
    for (int i = 0; i < allNums.size(); i++) {
        cost = stod(allNums[i]);
        //Point point = Point(row, i);
        place.push_back(row);
        place.push_back(i);

        State<vector<int>> *myState = new State<vector<int>>(place, cost);
        cout<<"create"<<endl;
        this->matrix[row].push_back(myState);
        cout<<"in metrix"<<endl;
        place.clear();
    }
}

vector<string> MyClientHandler::split(std::string info, char divide) {
    std::stringstream s(info);
    std::string part;
    std::vector<std::string> splitLine;

    while (getline(s, part, divide)) {
        splitLine.push_back(part);
    }
    return splitLine;
}