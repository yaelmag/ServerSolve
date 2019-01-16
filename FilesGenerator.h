//
// Created by adi on 15/01/19.
//


#ifndef SERVERAPPLICATION_FILESGENERATOR_H
#define SERVERAPPLICATION_FILESGENERATOR_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>

#include "MatrixSearchable.h"
#include "SearcherSolver.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "AStar.h"
#include "Point.h"
#include "State.h"

using namespace server_side;
using std::fstream;
using std::vector;
using std::pair;
using std::to_string;


/**
 * usage - create instance in main and call generateFiles()
 *
 * make sure you adjust the functions to your project (expected parameters etc.)
 *
 *
 * output:
 *
 * graphs1.txt  the graphs file to submit
 * solution1.txt    the solution file to submit
 *
 * 8 more files - 2 for each algorithm :
 *
 * <algorithm_name>_size_developed.txt  developed vertices as a function of size
 * <algorithm_name>_size_weight.txt  weight of route as a function of size
 *
 * you might find them useful for creating the PDF required in submission instructions
 * javascript code can read this format and generate a graph
 *
 *
 * we accept gratitude in the form of checks.
 *
 */
class FilesGenerator {


    void appendToFile(std::string fileName, std::string dataToAppend) {

        std::fstream stream;
        stream.open(fileName, std::ios::app | std::ios::ate);

        stream << dataToAppend;

        stream.flush();
        stream.close();

    }

    void prepareForGraph(string file_developed, string file_weight, SearchResult result, unsigned matrixSize) {

        appendToFile(file_developed,
                     "{ x: " + std::to_string(matrixSize) + ", y: " + to_string(result.developedVertices) + " },\n");

        appendToFile(file_weight,
                     "{ x: " + std::to_string(matrixSize) + ", y: " + to_string(result.shortestPathWeight) + " },\n");

    }

    //creates vector square matrix of size n
    vector<std::vector<int>> generateMatrix(unsigned n){

        /*int cost;
        vector<vector<State<Point>*>> vec;

        for (int k = 0; k < n; ++k) {
            vector<State<Point>*> curLine;
            for (int i = 0; i < n; ++i) {
                cost = (rand() % 10);
                Point point = Point(k, i);
                auto *myState = new State<Point>(point, cost);
                curLine.push_back(myState);
            }
            vec.push_back(curLine);
        }

        return vec;*/

        vector<vector<int>> vec;

        for (int k = 0; k < n; ++k) {
            vector<int> curLine;
            for (int i = 0; i < n; ++i) {
                curLine.push_back(rand() % 10);
            }
            vec.push_back(curLine);
        }

        return vec;
    }


    SearchResult solveMatrixAStar(vector<std::vector<int>> matrix) {
        int cost;
        vector<vector<State<Point>*>> vec;

        for (int k = 0; k < matrix.size(); ++k) {
            vector<State<Point>*> curLine;
            for (int i = 0; i < matrix.size(); ++i) {
                cost = matrix[k][i];
                Point point = Point(k, i);
                auto *myState = new State<Point>(point, cost);
                curLine.push_back(myState);
            }
            vec.push_back(curLine);
        }
        State<Point> *source = vec[0][0];
        State<Point> *dest = vec[matrix.size() - 1][matrix.size() - 1];

        auto graph = new MatrixSearchable<Point>(vec, source, dest);

        auto solver = new SearcherSolver<Point>(new AStar<Point>());
        auto result = solver->solve(graph);

        prepareForGraph("Astar_size_developed.txt","Astar_size_weight.txt", result, matrix.size());

        return result;

    }

    SearchResult solveMatrixBFS(vector<std::vector<int>> matrix) {
        int cost;
        vector<vector<State<Point>*>> vec;

        for (int k = 0; k < matrix.size(); ++k) {
            vector<State<Point>*> curLine;
            for (int i = 0; i < matrix.size(); ++i) {
                cost = matrix[k][i];
                Point point = Point(k, i);
                auto *myState = new State<Point>(point, cost);
                curLine.push_back(myState);
            }
            vec.push_back(curLine);
        }
        State<Point> *source = vec[0][0];
        State<Point> *dest = vec[matrix.size() - 1][matrix.size() - 1];

        auto graph = new MatrixSearchable<Point>(vec, source, dest);

        auto solver = new SearcherSolver<Point>(new BFS<Point>());
        auto result = solver->solve(graph);
        prepareForGraph("bfs_size_developed.txt","bfs_size_weight.txt", result, matrix.size());

        return result;


    }

    SearchResult solveMatrixDFS(vector<std::vector<int>> matrix) {
        int cost;
        vector<vector<State<Point>*>> vec;

        for (int k = 0; k < matrix.size(); ++k) {
            vector<State<Point>*> curLine;
            for (int i = 0; i < matrix.size(); ++i) {
                cost = matrix[k][i];
                Point point = Point(k, i);
                auto *myState = new State<Point>(point, cost);
                curLine.push_back(myState);
            }
            vec.push_back(curLine);
        }
        State<Point> *source = vec[0][0];
        State<Point> *dest = vec[matrix.size() - 1][matrix.size() - 1];

        auto graph = new MatrixSearchable<Point>(vec, source, dest);

        auto solver = new SearcherSolver<Point>(new DFS<Point>());
        auto result = solver->solve(graph);

        prepareForGraph("dfs_size_developed.txt","dfs_size_weight.txt", result, matrix.size());

        return result;
    }

    SearchResult solveMatrixBestFirstSearch(vector<std::vector<int>> matrix) {
        int cost;
        vector<vector<State<Point>*>> vec;

        for (int k = 0; k < matrix.size(); ++k) {
            vector<State<Point>*> curLine;
            for (int i = 0; i < matrix.size(); ++i) {
                cost = matrix[k][i];
                Point point = Point(k, i);
                auto *myState = new State<Point>(point, cost);
                curLine.push_back(myState);
            }
            vec.push_back(curLine);
        }
        State<Point> *source = vec[0][0];
        State<Point> *dest = vec[matrix.size() - 1][matrix.size() - 1];

        auto graph = new MatrixSearchable<Point>(vec, source, dest);

        auto solver = new SearcherSolver<Point>(new BestFirstSearch<Point>());
        auto result = solver->solve(graph);

        prepareForGraph("best_size_developed.txt","best_size_weight.txt", result, matrix.size());

        return result;
    }


    //
    void allAlgorithmSolutions(vector<std::vector<int>> matrix) {

        auto best = solveMatrixBestFirstSearch(matrix);
        auto dfs = solveMatrixDFS(matrix);
        auto bfs = solveMatrixBFS(matrix);
        auto AStar = solveMatrixAStar(matrix);

        std::string allMatrixSolutions = std::to_string(best.shortestPathWeight) + "," + to_string(best.developedVertices) +
                                         "\n" + std::to_string(dfs.shortestPathWeight) + "," + to_string(dfs.developedVertices) +
                                         "\n" + std::to_string(bfs.shortestPathWeight) + "," + to_string(bfs.developedVertices) +
                                         "\n" + std::to_string(AStar.shortestPathWeight) + "," + to_string(AStar.developedVertices) + "\n";

        appendToFile("solution1.txt", allMatrixSolutions);

    }


    void writeMatrixToFile(vector<std::vector<int>> matrix){

        string size = std::to_string(matrix.size());
        string src = "0,0";
        string dst = std::to_string(matrix.size() - 1) + "," + std::to_string(matrix.size() - 1);


        fstream stream("graphs1.txt", std::ios::app);

        stream << size << "\n" << src << "\n" << dst << "\n";

        for (auto row: matrix){

            auto it = row.begin();

            for (;it != row.end(); it++){
                if (it + 1 != row.end())
                    stream << *it << ",";
                else
                    stream << *it;

            }
            stream << "\n";
        }

        stream.close();

    }

public:

    void generateFiles() {

        // min size and number of matrix to generate
        int n = 10;

        //number of matrix to generate
        appendToFile("graphs1.txt", to_string(n) + "\n");

        for (int i = 1; i <= 10; i++) {

            vector<std::vector<int>> matrix = generateMatrix(n);

            writeMatrixToFile(matrix);
            allAlgorithmSolutions(matrix);

            n += 4;
        }

    }


};


#endif //SERVERAPPLICATION_FILESGENERATOR_H