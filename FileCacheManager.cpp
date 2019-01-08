//
// Created by yael on 1/6/19.
//

#include "FileCacheManager.h"


bool FileCacheManager::findSolution(Problem* problem) {
    return (generalCache.count(problem) != 0);
}

const Solution &FileCacheManager::getSolution(Problem* problem) {
    if (this->generalCache.count(problem)) {
        //return this->generalCache.
    }
}

//void FileCacheManager::storeSolution(Problem* problem, Solution* solution) {
//    this->generalCache.insert(std::pair<Problem, Solution>(&problem, &solution));
//    this->updatedCache.insert(std::pair<Problem, Solution>(&problem, &solution));
//}

void FileCacheManager::writeToFile(std::string fileName) {
    /*for (auto problem: cache) {

    }*/
}