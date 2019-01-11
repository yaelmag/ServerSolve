//
// Created by adi on 09/01/19.
//

#ifndef PROJECT2_MATRIX_H
#define PROJECT2_MATRIX_H

#include "Searchable.h"
#include "Point.h"
#include <iostream>

using namespace std;

template <class T>
class MatrixSearchable : public Searchable <T> {
    vector<vector<State<vector<int>>*>> matrix;
    State<T>* start;
    State<T>* end;

public:
    MatrixSearchable(const vector<vector<State<vector<int>> *>> &matrix, State<T> *start,
                     State<T> *end) : matrix(matrix), start(start), end(end) {}

    State<T>* getInitialState() override {
       /* vector<int> temp = this->start.getState();
        return this->matrix[temp[0]][temp[1]];*/
       return this->start;
    }

    State<T>* getGoalState() override {
        /*vector<int> temp = this->end.getState();
        return this->matrix[temp[0]][temp[1]];*/
        return this->end;
    }

   /* std::vector<State<T>*> getAllPossibleStates(State<T>* s) override {
        std::vector<State<vector<int>>*> allStates;
        unsigned long numRows, numCols;
        numRows = matrix.size();
        numCols = matrix[0].size();
        bool flag = false;
        for (unsigned long i = 0; i < numRows; i++) {
            for (unsigned long j = 0; j < numCols; j++) {
                if (matrix[i][j]->getState()[0] == s->getState()[0] && matrix[i][j]->getState()[1]
                == s->getState()[1]) {
                    // check up state
                    if (i != 0) {
                        allStates.push_back(matrix[i - 1][j]);
                    }
                    // check down state
                    if (i != numRows - 1) {
                        allStates.push_back(matrix[i + 1][j]);
                    }
                    // check left state
                    if (j != 0) {
                        allStates.push_back(matrix[i][j - 1]);
                    }
                    // check right state
                    if (j != numCols - 1) {
                        allStates.push_back(matrix[i][j + 1]);
                    }
                    flag = true;
                    break;
                }
            }
            if (flag == true) {
                break;
            }
        }
        return allStates;
    }*/

    void printMatrix() {
        unsigned long numRows, numCols;
        numRows = matrix.size();
        numCols = matrix[0].size();
        double cost;

        for (unsigned long i = 0; i < numRows; i++) {
            for (unsigned long j = 0; j < numCols; j++) {
                cost = this->matrix[i][j]->getCost();
                std::cout<<cost<<","<<std::endl;
            }
            std::cout<<std::endl;
        }
    }
};


#endif //PROJECT2_MATRIX_H
