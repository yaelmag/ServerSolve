//
// Created by adi on 08/01/19.
//

#ifndef PROJECT2_BESTFIRSTSEARCH_H
#define PROJECT2_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include <queue>

template <class T>
class Compare
{
public:
    bool operator() (State<T> *state1, State<T> *state2)
    {
        return state1->getCost() > state2->getCost();
    }
};

template <class T>
class BestFirstSearch : public Searcher<T>{
public:
    SearchResult search(Searchable<T> *searchable) override {
        SearchResult searchResult;

        // initialize the search result
        searchResult.developedVerticels = 0;
        searchResult.shortestPathRoute = "";
        searchResult.shortestPathWeight = 0;

        State<T>* goalState, *initialState, *currentNode;
        goalState = searchable->getGoalState();
        initialState = searchable->getInitialState();
        std::priority_queue<State<T>*, std::vector<State<T>*>, Compare<T>> pq;

        searchable->getInitialState()->setCameFrom(Start);
        pq.push(initialState);

        while (!pq.empty())
        {
            currentNode = pq.top();
            pq.pop();

            //finished
            if (currentNode == goalState)
            {
                break;
            }

            //upState
            if (currentNode->getUpState() != NULL && currentNode->getUpState()->getCameFrom() == NotSet) {
                currentNode->getUpState()->setCameFrom(Down);
                pq.push(currentNode->getUpState());

            }
            //downState
            if (currentNode->getDownState() != NULL && currentNode->getDownState()->getCameFrom() == NotSet) {
                currentNode->getDownState()->setCameFrom(Up);
                pq.push(currentNode->getDownState());

            }
            //leftState
            if (currentNode->getLeftState() != NULL && currentNode->getLeftState()->getCameFrom() == NotSet) {
                currentNode->getLeftState()->setCameFrom(Right);
                pq.push(currentNode->getLeftState());

            }
            //rightState
            if (currentNode->getRightState() != NULL && currentNode->getRightState()->getCameFrom() == NotSet) {
                currentNode->getRightState()->setCameFrom(Left);
                pq.push(currentNode->getRightState());

            }
            searchResult.developedVerticels++;
        }

        //no path exists!
        if (currentNode != goalState){
            searchResult.shortestPathRoute = "";
            searchResult.shortestPathWeight = -1;
            return searchResult;
        }


        bool arrivedInitialState = false;
        std::string currentDir;
        while (!arrivedInitialState)
        {
            searchResult.shortestPathWeight += currentNode->getCost();
            switch (currentNode->getCameFrom())
            {
                case Up:
                    currentNode = currentNode->getUpState();
                    currentDir = "Down, ";
                    break;
                case Down:
                    currentNode = currentNode->getDownState();
                    currentDir = "Up, ";
                    break;
                case Left:
                    currentNode = currentNode->getLeftState();
                    currentDir = "Right, ";
                    break;
                case Right:
                    currentNode = currentNode->getRightState();
                    currentDir = "Left, ";
                    break;
                case Start:
                    arrivedInitialState = true;
                    break;
                default:
                    throw "not valid scenario";
            }
            if (!arrivedInitialState)
                searchResult.shortestPathRoute.insert(0, currentDir);
        }
        searchResult.shortestPathRoute = searchResult.shortestPathRoute.substr(0, searchResult.shortestPathRoute.length() - 2);
        return searchResult;
    }
};

#endif //PROJECT2_BESTFIRSTSEARCH_H