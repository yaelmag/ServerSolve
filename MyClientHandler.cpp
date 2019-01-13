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
    if (!this->checkValidOfPoint(startP)) {
        __throw_invalid_argument("The point is invalid, there isn't an exist state in this place");
    }
    State<Point> *start1 = this->matrix[startP.getRow()][startP.getCol()];

    // read the end point
    line = server_side::TcpServer::readLine(cliSocket);
    e = split(line, ',');
    Point endP = Point(stoi(e[0]), stoi(e[1]));
    if (!this->checkValidOfPoint(endP)) {
        __throw_invalid_argument("The point is invalid, there isn't an exist state in this place");
    }
    State<Point> *end1 = this->matrix[endP.getRow()][endP.getCol()];

    MatrixSearchable<Point>* m = new MatrixSearchable <Point>(this->matrix, start1, end1);
    m->printMatrix();
    m->getAllPossibleStates(this->matrix[0][0]);
    m->getAllPossibleStates(this->matrix[1][1]);
    m->getAllPossibleStates(this->matrix[2][2]);
}

void MyClientHandler::addLine(std::string line, int row) {
    vector<string> allNums = split(line, ',');

    double cost;
    vector<State<Point>*> allStates;
    for (int i = 0; i < allNums.size(); i++) {
        cost = stod(allNums[i]);
        Point point = Point(row, i);

        State<Point> *myState = new State<Point>(point, cost);
        allStates.push_back(myState);
    }
    this->matrix.push_back(allStates);
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

bool MyClientHandler::checkValidOfPoint(Point p) {
    unsigned long rowsNum, colsNum;
    int row, col;
    rowsNum = this->matrix.size();
    colsNum = this->matrix[0].size();
    row = p.getRow();
    col = p.getCol();

    if (row < 0 || row > rowsNum - 1) {
        return false;
    }
    if (col < 0 || col > colsNum - 1) {
        return false;
    }
    return true;
}