//
// Created by yael on 1/6/19.
//

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H


#include <map>
#include "CacheManager.h"

class FileCacheManager : public CacheManager<class Problem, class Solution>{
    map<Problem, Solution> cache;
public:
    bool findSolution(Problem* problem) {
    }

    const Solution &getSolution() {
    }

    void storeSolution(Problem* problem, Solution* solution) {
    }

};


#endif //PROJECT2_FILECACHEMANAGER_H
