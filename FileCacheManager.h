//
// Created by yael on 1/6/19.
//

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H


#include <map>
#include "CacheManager.h"

class FileCacheManager : public CacheManager<class Problem, class Solution>{
    std::map<Problem, Solution> cache;
public:
    bool findSolution(Problem* problem) override;

    const Solution &getSolution(Problem* problem) override;

    void storeSolution(Problem* problem, Solution* solution);

    void writeToFile(std::string fileName);
};


#endif //PROJECT2_FILECACHEMANAGER_H
