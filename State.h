//
// Created by adi on 09/01/19.
//

#ifndef PROJECT2_STATE_H
#define PROJECT2_STATE_H

#include <string>

template <class T>
class State {
T state;
/*State<T>* upState;
State<T>* downState;
State<T>* rightState;
State<T>* leftState;*/

// cost to reach this state (set by a setter)
double cost;
// the state we came from to this state (setter)
State<T>* cameFrom;
bool isMarked;
public:
    State(T state, double cost) : state(state), cost(cost), isMarked(false), cameFrom(nullptr){}

    void setIsMarked(bool marked) {
        this->isMarked = marked;
    }

    void setCameFrom(State<T>* cameFrom) {
        this->cameFrom = cameFrom;
    }

    bool Equals(State<T> *s) // we overload Object's Equals method
    {
        return this->state ==s->getState();
    }

    T getState() const {
        return state;
    }

    double getCost() const {
        return cost;
    }

    State<T> *getCameFrom() const {
        return cameFrom;
    }

    bool operator<(const State *other) const
    {
        return this->cost < other->getCost();
    }

};

struct SearchResult {

    std::string shortestPathRoute;

    double shortestPathWeight;

    int developedVerticels;

};

#endif //PROJECT2_STATE_H
