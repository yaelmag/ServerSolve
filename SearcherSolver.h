//
// Created by adi on 13/01/19.
//

#ifndef PROJECT2_MATRIXSOLVER_H
#define PROJECT2_MATRIXSOLVER_H

#include "Solver.h"
#include "Searcher.h"

template <class T>
class SearcherSolver : public Solver<Searchable<T>*, SearchResult> {
    Searcher<T> *searcher;
public:
    SearcherSolver(Searcher<T> *searcher) : searcher(searcher) {}
    SearchResult solve(Searchable<T> *problem) override {
        return searcher->search(problem);
    }
};

#endif //PROJECT2_MATRIXSOLVER_H
