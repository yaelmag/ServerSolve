//
// Created by yael on 1/6/19.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "FileCacheManager.h"


bool FileCacheManager::findSolution(string problem) {
    return (generalCache.count(problem) != 0);
}

std::string FileCacheManager::getSolution(string problem) {
    if (this->findSolution(problem)) {
        return this->generalCache.find(problem)->second;
    }
    return "";
}

void FileCacheManager::storeSolution(string problem, string solution) {
    this->generalCache.insert(std::pair<string, string>(problem, solution));
    this->updatedCache.insert(std::pair<string, string>(problem, solution));
}

void FileCacheManager::writeToFile(string fileName) {
    std::ofstream f(fileName);
    if (f.is_open()) {
        for (const auto &problem: updatedCache) {
            f << problem.first;
            f << "$";
            f << problem.second;
            f << std::endl;
        }
    } else {
        std::cout << "unable to open file";
    }
}

void FileCacheManager::readFromFile(std::string fileName) {
    string line;
    std::ifstream file(fileName);
    std::vector<string> splittedLine;
    if (file.is_open()) {
        while (getline(file, line)) {
            splittedLine = split(line, '$');
            string problem = splittedLine.at(0);
            string solution = splittedLine.at(1);
            this->generalCache.insert(std::pair<string, string>(problem, solution));
        }
    } else {
        std::cout << "unable to open file";
    }
}

std::vector<string> FileCacheManager::split(string info, char divide) {
    std::stringstream s(info);
    string part;
    std::vector<string> splitLine;

    while (getline(s, part, divide)) {
        splitLine.push_back(part);
    }
    return splitLine;
}