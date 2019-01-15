//
// Created by adi on 09/01/19.
//

#ifndef PROJECT2_STATE_H
#define PROJECT2_STATE_H

#include <string>
#include <vector>

/**
 * enum that represent direction
 */
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
    /**
     * constructor
     * @param state - the state
     * @param cost - the cost
     */
    State(T state, double cost) : state(state), cost(cost), upState(NULL), downState(NULL),
    leftState(NULL), rightState(NULL), cameFrom(NotSet), isMarked(false) {}
    /**
     * set the up state
     * @param upState - the up state
     */
    void setUpState(State<T> *upState) {
        State::upState = upState;
    }
    /**
     * set the down state
     * @param downState - the down state
     */
    void setDownState(State<T> *downState) {
        State::downState = downState;
    }
    /**
     * set the left state
     * @param leftState - the left state
     */
    void setLeftState(State<T> *leftState) {
        State::leftState = leftState;
    }
    /**
     * set the right state
     * @param rightState - the right state
     */
    void setRightState(State<T> *rightState) {
        State::rightState = rightState;
    }
    /**
     * set isMarked
     * @param marked - a boolean variable
     */
    void setIsMarked(bool marked) {
        this->isMarked = marked;
    }
    /**
     * set the direction that the state came from
     * @param cameFrom - the direction the state came from
     */
    void setCameFrom(Direction cameFrom) {
        State::cameFrom = cameFrom;
    }
    /**
     * get the state
     * @return the state
     */
    T getState() const {
        return state;
    }
    /**
     * get the cost of the state
     * @return the cost of the state
     */
    double getCost() const {
        return cost;
    }
    /**
     * get the direction the state came from
     * @return the direction the state came from
     */
    Direction getCameFrom() const {
        return cameFrom;
    }
    /**
     * return isMarked
     * @return isMarked
     */
    bool getIsMarked() const {
        return isMarked;
    }
    /**
     * get the upState
     * @return the upState
     */
    State<T> *getUpState() const {
        return upState;
    }
    /**
     * get the downState
     * @return the downState
     */
    State<T> *getDownState() const {
        return downState;
    }
    /**
     * get the leftState
     * @return the leftState
     */
    State<T> *getLeftState() const {
        return leftState;
    }
    /**
     * get the rightState
     * @return the rightState
     */
    State<T> *getRightState() const {
        return rightState;
    }
    /**
     * get all the neighbors of the state
     * @return all the neighbors of the state
     */
    std::vector<State<T>*> getAllNeighbors() {
        std::vector<State<T>*> allNeighbors;
        if (this->upState != NULL) {
            allNeighbors.push_back(this->upState);
        }
        if (this->downState != NULL) {
            allNeighbors.push_back(this->downState);
        }
        if (this->leftState != NULL) {
            allNeighbors.push_back(this->leftState);
        }
        if (this->rightState != NULL) {
            allNeighbors.push_back(this->rightState);
        }
        return allNeighbors;
    }

    /**
     * override operator <
     * @param other - a state
     * @return - true if 'this' state cost is smaller than 'other' state cost
     */
    bool operator<(const State *other) const {
        return this->cost < other->getCost();
    }

    /**
     * override operator ==
     * @param other - a state
     * @return - true if the two states are equals and that their cost is equal, else return false
     */
    bool operator==(const State *other) const {
        return (this->getState() == other->getState() && this->cost == other->cost);
    }

};

/**
 * struct that represent the search result
 */
struct SearchResult {

    std::string shortestPathRoute;

    double shortestPathWeight;

    int developedVerticels;

};

#endif //PROJECT2_STATE_H
