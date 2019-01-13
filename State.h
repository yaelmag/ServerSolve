//
// Created by adi on 09/01/19.
//

#ifndef PROJECT2_STATE_H
#define PROJECT2_STATE_H

#include <string>
#include <vector>

template <class T>
class State {
T state;
State<T>* upState;
State<T>* downState;
State<T>* leftState;
State<T>* rightState;

// cost to reach this state (set by a setter)
double cost;
// the state we came from to this state (setter)
/*State<T>* cameFrom;*/
std::string cameFrom;
private:
    bool isMarked;
public:
    State(T state, double cost) : state(state), cost(cost), upState(nullptr), downState(nullptr),
    leftState(nullptr), rightState(nullptr), cameFrom(""), isMarked(false) {}

    //State(T state, double cost) : state(state), cost(cost), isMarked(false), cameFrom(nullptr){}

    void setUpState(State<T> *upState) {
        State::upState = upState;
    }

    void setDownState(State<T> *downState) {
        State::downState = downState;
    }

    void setLeftState(State<T> *leftState) {
        State::leftState = leftState;
    }

    void setRightState(State<T> *rightState) {
        State::rightState = rightState;
    }

    void setIsMarked(bool marked) {
        this->isMarked = marked;
    }

    void setCameFrom(const std::string &cameFrom) {
        State::cameFrom = cameFrom;
    }

    /*void setCameFrom(State<T>* cameFrom) {
        this->cameFrom = cameFrom;
    }*/

   /* bool Equals(State<T> *s) // we overload Object's Equals method
    {
        return this->state ==s->getState();
    }*/

    T getState() const {
        return state;
    }

    double getCost() const {
        return cost;
    }

    const std::string &getCameFrom() const {
        return cameFrom;
    }

    State<T> *getUpState() const {
        return upState;
    }

    State<T> *getDownState() const {
        return downState;
    }

    State<T> *getLeftState() const {
        return leftState;
    }

    State<T> *getRightState() const {
        return rightState;
    }

    std::vector<State<T>*> getAllNeighbors() {
        std::vector<State<T>*> allNeighbors;
        if (this->upState != nullptr) {
            allNeighbors.push_back(this->upState);
        }
        if (this->downState != nullptr) {
            allNeighbors.push_back(this->downState);
        }
        if (this->leftState != nullptr) {
            allNeighbors.push_back(this->leftState);
        }
        if (this->rightState != nullptr) {
            allNeighbors.push_back(this->rightState);
        }
        return allNeighbors;
    }

    /*State<T> *getCameFrom() const {
        return cameFrom;
    }*/

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
