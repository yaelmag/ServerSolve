//
// Created by yael on 1/8/19.
//

#ifndef PROJECT2_REVERSERSOLVER_H
#define PROJECT2_REVERSERSOLVER_H


#include <map>
#include "Solver.h"

using std::string;
class ReverserSolver : public Solver<string, string> {
public:
    string solve(string problem) override;
};


#endif //PROJECT2_REVERSERSOLVER_H
