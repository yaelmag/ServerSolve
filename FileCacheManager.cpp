//
// Created by yael on 1/6/19.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "FileCacheManager.h"
#define FILE_NAME "cacheFile.txt"

/**
 * check if the problem and his solution already exist in the cache
 * @param problem - a problem
 * @return true if the problem and his solution already exist in the cache, else return false
 */
bool FileCacheManager::findSolution(string problem) {
    return (generalCache.count(problem) != 0);
}

/**
 * if the problem and his solution already exist in the cache, get the solution from the cache
 * @param problem - a problem
 * @return the solution
 */
std::string FileCacheManager::getSolution(string problem) {
    if (this->findSolution(problem)) {
        return this->generalCache.find(problem)->second;
    }
    return "";
}

/**
 * store the solution in the maps
 * @param problem - a problem
 * @param solution - a solution
 */
void FileCacheManager::storeSolution(string problem, string solution) {
    this->generalCache.insert(std::pair<string, string>(problem, solution));
    this->updatedCache.insert(std::pair<string, string>(problem, solution));
}

/**
 * write all the new problems and their solutions in the cache file
 * @param fileName - the cache file name
 */
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

/**
 * load all the problems and their solutions to the map
 * @param fileName - the cache file name
 */
void FileCacheManager::loadFromFile(std::string fileName) {
    string line, solution, problem = "";
    std::ifstream file(fileName, std::ios::in);
    std::vector<string> splittedLine;
    if (file.is_open()) {
        while (getline(file, line)) {
            // if we get to the solution
            if (line.find('$') != std::string::npos) {
                splittedLine = split(line, '$');
                problem += splittedLine.at(0);
                solution = splittedLine.at(1);
                // insert the problem and the solution to the map
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

/**
 * split string of information according to the 'divide' char
 * @param info - a string of information
 * @param divide - a char to divide the line according to him
 * @return - a vector of the splitted line
 */
std::vector<string> FileCacheManager::split(string info, char divide) {
    std::stringstream s(info);
    string part;
    std::vector<string> splitLine;

    while (getline(s, part, divide)) {
        splitLine.push_back(part);
    }
    return splitLine;
}

/**
 * store all the new problems and their solution in the cache file
 */
void FileCacheManager::storeAtTheEnd() {
    this->writeToFile(FILE_NAME);
}

/**
 * load all the problems and their solutions from the cache file to the map
 */
void FileCacheManager::loadAtStart() {
    this->loadFromFile(FILE_NAME);
}

FileCacheManager::~FileCacheManager() {}