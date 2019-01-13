//
// Created by adi on 08/01/19.
//

#ifndef PROJECT2_SEARCHER_H
#define PROJECT2_SEARCHER_H

#include "Searchable.h"
template <class T>
class Searcher {
public:
    virtual SearchResult search(Searchable<T> *searchable) = 0;
};
#endif //PROJECT2_SEARCHER_H
