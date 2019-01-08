//
// Created by yael on 1/8/19.
//

#include <algorithm>
#include "ReverserSolver.h"

string ReverserSolver::solve(string problem) {
    string copyProblem = problem;
    std::reverse(copyProblem.begin(), copyProblem.end());
    return copyProblem;
}
