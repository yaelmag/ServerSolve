//
// Created by yael on 1/6/19.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "FileCacheManager.h"
#define FILE_NAME "cacheFile.txt"


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
    std::ofstream f(fileName, std::ios::out | std::ios::app | std::ios::ate);
    if (f.is_open()) {
        for (const auto &problem: updatedCache) {
            f << problem.first;
            f << "$";
            f << problem.second;
            f << std::endl;
        }
        f.close();
    } else {
        std::cout << "unable to open file";
    }
}

void FileCacheManager::loadFromFile(std::string fileName) {
    string line, solution, problem = "";
    std::ifstream file(fileName, std::ios::in);
    std::vector<string> splittedLine;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find('$') != std::string::npos) {
                splittedLine = split(line, '$');
                problem += splittedLine.at(0);
                solution = splittedLine.at(1);
                this->generalCache.insert(std::pair<string, string>(problem, solution));
                problem = "";
            } else {
                problem += (line + "\n");
            }
        }
        file.close();
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

FileCacheManager::~FileCacheManager() {
}

void FileCacheManager::storeAtTheEnd() {
    this->writeToFile(FILE_NAME);
    //this->generalCache.clear();
    //this->updatedCache.clear();
}

void FileCacheManager::loadAtStart() {
    this->loadFromFile(FILE_NAME);
}