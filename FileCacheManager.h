//
// Created by yael on 1/6/19.
//

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H


#include <map>
#include <vector>
#include "CacheManager.h"

using std::string;
class FileCacheManager : public CacheManager {
    std::map<string, string> generalCache;
    std::map<string, string> updatedCache;
public:
    FileCacheManager() = default;

    virtual bool findSolution(string problem) override;

    virtual std::string getSolution(string problem) override;

    virtual void storeSolution(string problem, string solution) override;

    void writeToFile(string fileName);

    void readFromFile(string fileName);

    std::vector<string> split(string info, char divide);
};


#endif //PROJECT2_FILECACHEMANAGER_H
