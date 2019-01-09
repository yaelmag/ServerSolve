//
// Created by adi on 09/01/19.
//

#ifndef PROJECT2_MATRIX_H
#define PROJECT2_MATRIX_H

#include "Searchable.h"
template <class T>
class MatrixSearchable : public Searchable<class T> {
    std::vector<std::vector<State<T>>> matrix;
    State<T> start;
    State<T> end;

public:
    MatrixSearchable(std::vector<State<T>> matrix,State<T> start,State<T> end) {
        this->matrix = matrix;
        this->start = start;
        this->end = end;
    }

    State<T> getInitialState() override {
        return this->start;
    }

    State<T> getGoalState() override {
        return this->end;
    }

    std::vector<State<T>> getAllPossibleStates(State<T> s) override {
        std::vector<State<T>> allStates;
        unsigned long numRows, numCols;
        numRows = matrix.size();
        numCols = matrix[0].size();
        for (unsigned long i = 0; i < numRows; i++) {
            for (unsigned long j = 0; j < numCols; j++) {
                if (matrix[i][j] == s) {
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
                }
            }
        }
        return allStates;
    }
};


#endif //PROJECT2_MATRIX_H
