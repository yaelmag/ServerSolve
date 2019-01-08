//
// Created by yael on 1/8/19.
//

#include <algorithm>
#include "ReverserSolver.h"

std::string ReverserSolver::solve(std::string problem) {
    std::string copyProblem = problem;
    std::reverse(copyProblem.begin(), copyProblem.end());
    return copyProblem;
}
