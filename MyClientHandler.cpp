//
// Created by adi on 09/01/19.
//

#include "MyClientHandler.h"
#include <string>
#include "TcpServer.h"
#include "MatrixSearchable.h"

void MyClientHandler::handleClient(int cliSocket) {
    SearchResult searchResult;
    string line, wholeProblem, solution;
    vector<string> s, e;
    vector<string> allInfo;
    line = server_side::TcpServer::readLine(cliSocket);

    // read all the information: matrix, initialState and goalState
    while (line != "end") {
        allInfo.push_back(line);
        wholeProblem += (line + "\n");
        line = server_side::TcpServer::readLine(cliSocket);
    }

    // create the matrix and the initial state and the goal state
    MatrixSearchable<Point>* m = this->createMatrix(allInfo);

    // if the problem already exist in the cache take the solution from their
    if (cache->findSolution(wholeProblem)) {
        solution = cache->getSolution(wholeProblem);
        // else, solve the problem with the solver
    } else {
        searchResult = this->solver->solve(m);
        solution = searchResult.shortestPathRoute;
        cache->storeSolution(wholeProblem, solution);
    }
    // write to the client the solution
    server_side::TcpServer::writeToClient(cliSocket, solution);
    server_side::TcpServer::writeToClient(cliSocket, "\n");

    // delete the matrixSearchable
    this->deleteMatrixSearchable(m);
}

/**
 * create the matrix, the initial state and the goal state
 * @param allInfo - all the information the client send
 * @return a MatrixSearchable
 */
MatrixSearchable<Point>* MyClientHandler::createMatrix(vector<string> allInfo) {
    vector<string> s, e;
    unsigned long length = allInfo.size();
    //create the matrix
    for (unsigned long i = 0; i < length - 2; i++) {
        this->addLine(allInfo[i], i);
    }

    //create the start point
    s = split(allInfo[length - 2], ',');
    Point startP = Point(stoi(s[0]), stoi(s[1]));
    if (!this->checkValidOfPoint(startP)) {
        __throw_invalid_argument("The point is invalid, there isn't an exist state in this place");
    }
    State<Point> *start1 = this->matrix[startP.getRow()][startP.getCol()];

    //create the end point
    e = split(allInfo[length - 1], ',');
    Point endP = Point(stoi(e[0]), stoi(e[1]));
    if (!this->checkValidOfPoint(endP)) {
        __throw_invalid_argument("The point is invalid, there isn't an exist state in this place");
    }
    State<Point> *end1 = this->matrix[endP.getRow()][endP.getCol()];

    //create the matrixSearchable
    MatrixSearchable<Point>* m = new MatrixSearchable <Point>(this->matrix, start1, end1);
    return m;
}

/**
 * add line to the matrix
 * @param line - a line in the matrix
 * @param row - the number of row we now
 */
void MyClientHandler::addLine(std::string line, int row) {
    vector<string> allNums = split(line, ',');

    double cost;
    vector<State<Point>*> allStates;
    // create the line - vector of states
    for (int i = 0; i < allNums.size(); i++) {
        cost = stod(allNums[i]);
        Point point = Point(row, i);

        auto *myState = new State<Point>(point, cost);
        allStates.push_back(myState);
    }
    // push the new line to the matrix
    this->matrix.push_back(allStates);
}

/**
 * split string of information according to the 'divide' char
 * @param info - a string of information
 * @param divide - a char to divide the line according to him
 * @return - a vector of the splitted line
 */
vector<string> MyClientHandler::split(std::string info, char divide) {
    std::stringstream s(info);
    std::string part;
    std::vector<std::string> splitLine;

    while (getline(s, part, divide)) {
        splitLine.push_back(part);
    }
    return splitLine;
}

/**
 * check if the point place exist in the matrix
 * @param p - a point
 * @return true if the point place exist in the matrix, else return false
 */
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

/**
 * delete the matrix and her states
 * @param m - a matrixSearchable
 */
void MyClientHandler::deleteMatrixSearchable(MatrixSearchable<Point>* m) {
    unsigned long rowsNum, colsNum;
    vector<vector<State<Point>*>> mat = m->getMatrix();

    rowsNum = mat.size();
    colsNum = mat[0].size();
    // delete all the states in the matrix
    for (int i = 0; i < rowsNum; i++) {
        for (int j = 0; j < colsNum; j++) {
            delete(mat[i][j]);
        }
    }
    // delete the matrix
    delete(m);
}

/**
 * get the cache
 * @return the cache
 */
CacheManager* MyClientHandler::getCache() {
    return this->cache;
}
/**
 * destructor
 */
MyClientHandler::~MyClientHandler() {}