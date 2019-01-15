//
// Created by adi on 08/01/19.
//

#ifndef PROJECT2_BFS_H
#define PROJECT2_BFS_H

#include "Searcher.h"
#include "MatrixSearchable.h"
#include <queue>
#include <map>
using namespace std;

template <class T>
class BFS : public Searcher<T> {
public:
    SearchResult search(Searchable<T> *searchable) override {
        SearchResult searchResult;
        // initialize the search result
        searchResult.developedVerticels = 0;
        searchResult.shortestPathRoute = "";
        searchResult.shortestPathWeight = 0;

        State<T> *initialState, *goalState, *currentNode;
        std::vector<State<T>*> neighbors;
        std::queue<State<T>*> q;

        initialState = searchable->getInitialState();
        goalState = searchable->getGoalState();
        initialState->setCameFrom(Start);
        q.push(initialState);

        while (!q.empty())
        {
            currentNode = q.front();
            q.pop();

            //finished
            if (currentNode == goalState)
            {
                break;
            }

            //upState
            if (currentNode->getUpState() != NULL && currentNode->getUpState()->getCameFrom() == NotSet) {
                currentNode->getUpState()->setCameFrom(Down);
                q.push(currentNode->getUpState());

            }
            //downState
            if (currentNode->getDownState() != NULL && currentNode->getDownState()->getCameFrom() == NotSet) {
                currentNode->getDownState()->setCameFrom(Up);
                q.push(currentNode->getDownState());

            }
            //leftState
            if (currentNode->getLeftState() != NULL && currentNode->getLeftState()->getCameFrom() == NotSet) {
                currentNode->getLeftState()->setCameFrom(Right);
                q.push(currentNode->getLeftState());

            }
            //rightState
            if (currentNode->getRightState() != NULL && currentNode->getRightState()->getCameFrom() == NotSet) {
                currentNode->getRightState()->setCameFrom(Left);
                q.push(currentNode->getRightState());

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
        string currentDir;
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

#endif //PROJECT2_BFS_H
