//
// Created by yael on 1/6/19.
//

#ifndef PROJECT2_SOLVER_H
#define PROJECT2_SOLVER_H

#include <string>
using namespace std;

template <class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem problem) = 0;
};


#endif //PROJECT2_SOLVER_H
