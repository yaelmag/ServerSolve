//
// Created by adi on 09/01/19.
//

#ifndef PROJECT2_STATE_H
#define PROJECT2_STATE_H

template <class T>
class State {
T state;
// cost to reach this state (set by a setter)
double cost;
// the state we came from to this state (setter)
State<T>* cameFrom;
public:
    State(T state) {
        this->state = state;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setCameFrom(State<T>* cameFrom) {
        this->cameFrom = cameFrom;
    }

    /*bool Equals(State<T> s) // we overload Object's Equals method
    {
        return state.Equals(s.state);
    }*/

};

#endif //PROJECT2_STATE_H
