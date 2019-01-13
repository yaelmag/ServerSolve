//
// Created by adi on 08/01/19.
//

#ifndef PROJECT2_BFS_H
#define PROJECT2_BFS_H

#include "Searcher.h"
#include <queue>

template <class T>
class BFS : public Searcher<T> {
public:
    SearchResult search(Searchable<T> *searchable) override {
        SearchResult searchResult;
        searchResult.developedVerticels = 0;
        searchResult.shortestPathRoute = "";
        searchResult.shortestPathWeight = 0;

        State<T> *initialState, *goalState;
        initialState = searchable->getInitialState();
        goalState = searchable->getGoalState();


    }

};

#endif //PROJECT2_BFS_H
