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
    vector<vector<State<Point>*>> matrix;
    Solver<Searchable<Point>*, SearchResult> *solver;
    CacheManager* cache;
public:
    MyClientHandler(Solver<Searchable<Point> *, SearchResult> *solver, CacheManager *cache)
            : solver(solver), cache(cache) {}

    MyClientHandler() = default;
    void handleClient(int cliSocket) override;
    MatrixSearchable<Point>* createMatrix(vector<string> allInfo);
    void addLine(std::string line, int row);
    vector<string> split(string info, char divide);
    bool checkValidOfPoint(Point p);
    void deleteMatrixSearchable(MatrixSearchable<Point>* m);
    virtual CacheManager* getCache() override;
    virtual ~MyClientHandler() override;
};


#endif //PROJECT2_MYCLIENTHANDLER_H
