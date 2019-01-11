//
// Created by yael on 1/6/19.
//

#ifndef PROJECT2_CACHEMANAGER_H
#define PROJECT2_CACHEMANAGER_H

#include <string>


class CacheManager {
public:
    virtual bool findSolution(std::string problem) = 0;

    virtual std::string getSolution(std::string problem) = 0;

    virtual void storeSolution(std::string problem, std::string solution) = 0;

    virtual void loadAtStart() = 0;

    virtual void storeAtTheEnd() = 0;

    virtual ~CacheManager() = default;
};


#endif //PROJECT2_CACHEMANAGER_H
