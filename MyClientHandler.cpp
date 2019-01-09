//
// Created by adi on 09/01/19.
//

#include "MyClientHandler.h"
#include <string>
#include "TcpServer.h"
#include "MatrixSearchable.h"

void MyClientHandler::handleClient(int cliSocket) {
    std::string line;
    std::vector<std::string> s, e;
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
    Point startP = Point(stoi(s[0]), stoi(s[1]));
    State<Point> start1 = State<Point>(startP, this->matrix[startP.getRow()][startP.getCol()].getCost());

    // read the end point
    line = server_side::TcpServer::readLine(cliSocket);
    e = split(line, ',');
    Point endP = Point(stoi(e[0]), stoi(e[1]));
    State<Point> end1 = State<Point>(endP, this->matrix[endP.getRow()][endP.getCol()].getCost());

    MatrixSearchable<Point> m = new MatrixSearchable<Point>(this->matrix, start1, end1);
}

void MyClientHandler::addLine(std::string line, int row) {
    std::vector<std::string> allNums = split(line, ',');
    double cost;
    for (int i = 0; i < allNums.size(); i++) {
        cost = stod(allNums[i]);
        Point point = Point(row, i);
        this->matrix[row].push_back(State<Point>(point, cost));
    }

}

std::vector<std::string> MyClientHandler::split(std::string info, char divide) {
    std::stringstream s(info);
    std::string part;
    std::vector<std::string> splitLine;

    while (getline(s, part, divide)) {
        splitLine.push_back(part);
    }
    return splitLine;
}