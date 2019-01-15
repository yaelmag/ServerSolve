//
// Created by adi on 08/01/19.
//

#ifndef PROJECT2_DFS_H
#define PROJECT2_DFS_H

#include "Searcher.h"

template <class T>
class DFS : public Searcher <T> {
    SearchResult searchResult;
    State<T>* goalState;
public:
    SearchResult search(Searchable<T> *searchable) override {
        // initialize the search result
        this->searchResult.developedVerticels = 0;
        this->searchResult.shortestPathRoute = "";
        this->searchResult.shortestPathWeight = 0;

        this->goalState = searchable->getGoalState();
        State<T>* initialState = searchable->getInitialState();
        recursiveSearch(initialState);

        this->searchResult.shortestPathRoute = this->searchResult.shortestPathRoute.substr(0,
                searchResult.shortestPathRoute.length() - 2);
        return this->searchResult;
    }

    bool recursiveSearch(State<T>* currentState) {
        if (currentState == NULL || currentState->getIsMarked()) {
            return false;
        }

        this->searchResult.shortestPathWeight += currentState->getCost();

        searchResult.developedVerticels++;

        //finished
        if (currentState == goalState) {
            return true;
        }

        currentState->setIsMarked(true);

        if (currentState->getLeftState() != NULL && recursiveSearch(currentState->getLeftState()))
        {
            this->searchResult.shortestPathRoute.insert(0, "Left, ");
            return true;
        }

        if (currentState->getUpState() != NULL && recursiveSearch(currentState->getUpState()))
        {
            this->searchResult.shortestPathRoute.insert(0, "Up, ");
            return true;
        }

        if (currentState->getRightState() != NULL && recursiveSearch(currentState->getRightState()))
        {
            this->searchResult.shortestPathRoute.insert(0, "Right, ");
            return true;
        }

        if (currentState->getDownState() != NULL && recursiveSearch(currentState->getDownState()))
        {
            this->searchResult.shortestPathRoute.insert(0, "Down, ");
            return true;
        }

        this->searchResult.shortestPathWeight -= currentState->getCost();

        return false;
    }
};

#endif //PROJECT2_DFS_H