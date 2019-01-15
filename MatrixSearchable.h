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
    vector<vector<State<T>*>> matrix;
    State<T>* start;
    State<T>* end;

public:
    /**
     * constructor
     * @param matrix - a matrix
     * @param start - initial state
     * @param end - goal state
     */
    MatrixSearchable(const vector<vector<State<Point> *>> &matrix, State<T> *start,
                     State<T> *end) : matrix(matrix), start(start), end(end) {
        unsigned long numRows, numCols, row, col;
        numRows = matrix.size();
        numCols = matrix[0].size();

        // set to every state his neighbors
        for (unsigned long i = 0; i < numRows; i++) {
            for (unsigned long j = 0; j < numCols; j++) {
                // set up state
                if (i != 0 && this->matrix[i - 1][j]->getCost() != -1) {
                    this->matrix[i][j]->setUpState(this->matrix[i - 1][j]);
                }
                // set down state
                if (i != numRows - 1 && this->matrix[i + 1][j]->getCost() != -1) {
                    this->matrix[i][j]->setDownState(this->matrix[i + 1][j]);
                }
                // set left state
                if (j != 0 && this->matrix[i][j - 1]->getCost() != -1) {
                    this->matrix[i][j]->setLeftState(this->matrix[i][j - 1]);
                }
                // set right state
                if (j != numCols - 1 && this->matrix[i][j + 1]->getCost() != -1) {
                    this->matrix[i][j]->setRightState(this->matrix[i][j + 1]);
                }
            }
        }

    }

    /**
     * get the matrix
     * @return the matrix
     */
    const vector<vector<State<T> *>> &getMatrix() const {
        return matrix;
    }

    /**
     * get the initial state
     * @return the initial state
     */
    State<T>* getInitialState() override {
       return this->start;
    }
    /**
     * get the goal state
     * @return the goal state
     */
    State<T>* getGoalState() override {
        return this->end;
    }

    /**
     * get all the possible next states from a specific state
     * @param s - a state
     * @return all the possible next states from a specific state
     */
    vector<State<T>*> getAllPossibleStates(State<T>* s) override {
        return s->getAllNeighbors();
    }
};


#endif //PROJECT2_MATRIX_H
