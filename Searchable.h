//
// Created by adi on 09/01/19.
//

#ifndef PROJECT2_SEARCHABLE_H
#define PROJECT2_SEARCHABLE_H

#include "State.h"
#include <vector>

template <class T>
class Searchable {
    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getGoalState() = 0;
    virtual std::vector<State<T>*> getAllPossibleStates(State<T>* s) = 0;
};


#endif //PROJECT2_SEARCHABLE_H
