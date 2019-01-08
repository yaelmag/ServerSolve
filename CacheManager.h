//
// Created by yael on 1/6/19.
//

#ifndef PROJECT2_CACHEMANAGER_H
#define PROJECT2_CACHEMANAGER_H

#include <string>


template<class Problem, class Solution>
class CacheManager {
public:
    virtual bool findSolution(Problem* problem) = 0;

    virtual const Solution& getSolution(Problem* problem) = 0;

    virtual void storeSolution(Problem* problem, Solution* solution) = 0;
};


#endif //PROJECT2_CACHEMANAGER_H
