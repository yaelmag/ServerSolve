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
    vector<vector<State<Point>*>> matrix;
    State<T>* start;
    State<T>* end;

public:
    MatrixSearchable(const vector<vector<State<Point> *>> &matrix, State<T> *start,
                     State<T> *end) : matrix(matrix), start(start), end(end) {}

    State<T>* getInitialState() override {
       return this->start;
    }

    State<T>* getGoalState() override {
        return this->end;
    }

    vector<State<T>*> getAllPossibleStates(State<T>* s) override {
        std::vector<State<Point>*> allStates;
        unsigned long numRows, numCols, row, col;
        numRows = matrix.size();
        numCols = matrix[0].size();
        /* bool flag = false;
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
        }*/
        row = s->getState().getRow();
        col = s->getState().getCol();

        if (row != 0 && this->matrix[row - 1][col]->getCost() != -1) {
            allStates.push_back(this->matrix[row - 1][col]);
        }
        if (row != numRows - 1 && this->matrix[row + 1][col]->getCost() != -1) {
            allStates.push_back(this->matrix[row + 1][col]);
        }
        if (col != 0 && this->matrix[row][col - 1]->getCost() != -1) {
            allStates.push_back(this->matrix[row][col - 1]);
        }
        if (col != numCols - 1 && this->matrix[row][col + 1]->getCost() != -1) {
            allStates.push_back(this->matrix[row][col + 1]);
        }
        printStates(allStates && this->matrix[row - 1][col]->getCost() != -1);
        return allStates;
    }

    void printStates (vector<State<T>*> states) {
        double cost;
        for (unsigned long i = 0; i < states.size(); i++) {
            cost = states[i]->getCost();
            cout<<cost<<",";
        }
        cout<<endl;
    }

    void printMatrix() {
        unsigned long numRows, numCols;
        numRows = matrix.size();
        numCols = matrix[0].size();
        double cost;

        for (unsigned long i = 0; i < numRows; i++) {
            for (unsigned long j = 0; j < numCols; j++) {
                cost = this->matrix[i][j]->getCost();
                std::cout<<cost<<",";
            }
            std::cout<<std::endl;
        }
    }
};


#endif //PROJECT2_MATRIX_H
