//
// Created by yael on 1/8/19.
//

#ifndef PROJECT2_REVERSERSOLVER_H
#define PROJECT2_REVERSERSOLVER_H


#include <map>
#include "Solver.h"

class ReverserSolver : Solver<std::string, std::string> {
public:
    std::string solve(std::string problem) override;
};


#endif //PROJECT2_REVERSERSOLVER_H
