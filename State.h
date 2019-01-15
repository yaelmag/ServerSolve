//
// Created by adi on 09/01/19.
//

#ifndef PROJECT2_STATE_H
#define PROJECT2_STATE_H

#include <string>
#include <vector>

enum Direction {
    NotSet = 0,
    Start = 1,
    Left = 2,
    Up = 3,
    Right = 4,
    Down = 5,
};


template <class T>
class State {

T state;
State<T>* upState;
State<T>* downState;
State<T>* leftState;
State<T>* rightState;
double cost;
Direction cameFrom;
bool isMarked;

public:
    State(T state, double cost) : state(state), cost(cost), upState(NULL), downState(NULL),
    leftState(NULL), rightState(NULL), cameFrom(NotSet), isMarked(false) {}

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

    void setCameFrom(Direction cameFrom) {
        State::cameFrom = cameFrom;
    }

    T getState() const {
        return state;
    }

    double getCost() const {
        return cost;
    }

    Direction getCameFrom() const {
        return cameFrom;
    }

    bool getIsMarked() const {
        return isMarked;
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
