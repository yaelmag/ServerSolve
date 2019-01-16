//
// Created by adi on 08/01/19.
//

#ifndef PROJECT2_ASTAR_H
#define PROJECT2_ASTAR_H
// A C++ Program to implement A* Search Algorithm
#include "Searcher.h"
#include "Point.h"
#include "State.h"
#include <queue>
#include <algorithm>
#include <map>
#include "PriorityQueue.h"

using namespace std;

template<class T>
class AStar : public Searcher<T> {
public:
    // A Function to find the shortest path between
    // a given source cell to a destination cell according
    // to A* Search Algorithm
    SearchResult search(Searchable<T> *searchable) override {
        SearchResult searchResult;
        // initialize the search result
        searchResult.developedVertices = 0;
        searchResult.shortestPathRoute = "";
        searchResult.shortestPathWeight = 0;

        State<T> *initialState, *goalState, *currentNode;
        initialState = searchable->getInitialState();
        goalState = searchable->getGoalState();

        // Either the source or the destination is blocked
        if (!isUnBlocked(searchable, initialState) || !isUnBlocked(searchable, goalState)) {
            searchResult.shortestPathRoute = "Source or the destination is blocked\n";
            return searchResult;
        }

        // If the destination cell is the same as source cell
        if (initialState == goalState) {
            searchResult.shortestPathRoute = "We are already at the destination\n";
            return searchResult;
        }

        std::map<State<T>*,  State<T>*> cameFromMap;

        std::map<State<T>*, int> costMap;

        server_side::PriorityQueue<State<T>*, int> priorityQueue;
        priorityQueue.put(initialState, 0);

        cameFromMap[initialState] = initialState;
        costMap[initialState] = 0;

        while (!priorityQueue.empty()) {
            currentNode = priorityQueue.get();


            if (currentNode == goalState) {
                break;
            }

            for (State<T> *next : currentNode->getAllNeighbors()) {
                double new_cost = costMap[currentNode] + next->getCost();
                if (costMap.find(next) == costMap.end()
                    || new_cost < costMap[next]) {
                    costMap[next] = (int)new_cost;
                    int priority = new_cost + heuristic(next, goalState);
                    priorityQueue.put(next, priority);
                    cameFromMap[next] = currentNode;
                    searchResult.developedVertices++;
                }
            }

        }

        //reconstruction

        std::vector<State<T> *> path;


        //no route!
        if (currentNode != goalState){
            searchResult.shortestPathRoute = "";
            searchResult.shortestPathWeight = -1;
            return searchResult;
        }


        while (currentNode != initialState) {
            path.push_back(currentNode);
            currentNode = cameFromMap[currentNode];
            searchResult.shortestPathWeight += currentNode->getCost();
        }

        path.push_back(initialState); // optional
        std::reverse(path.begin(), path.end());

        //we have the path in states
        std::string step;
        for (auto it = path.begin(); it != path.end() && it + 1 != path.end(); it++){

            //went right
            if ((*(it+1))->getState().getCol() > (*(it))->getState().getCol()) {
                step = "Right, ";
            }
            //went left
            if ((*(it+1))->getState().getCol() < (*(it))->getState().getCol())
                step = "Left, ";
            //down
            if ((*(it+1))->getState().getRow() > (*(it))->getState().getRow())
                step = "Down, ";
            //up
            if((*(it+1))->getState().getRow() < (*(it))->getState().getRow())
                step = "Up, ";

            searchResult.shortestPathRoute.append(step);

        }

        searchResult.shortestPathRoute =
                searchResult.shortestPathRoute.substr(0, searchResult.shortestPathRoute.length() - 2);

        return searchResult;

    }

    // A Utility Function to check whether the given cell is
    // blocked or not
    bool isUnBlocked(Searchable<T>* searchable, State<T>* state) {
        // Returns true if the cell is not blocked else false
        return (searchable->getAllPossibleStates(state).size() != 0);
    }

    int heuristic(State<T>* cur, State<T>* dest) {
        return ((std::abs)(cur->getState().getRow() - dest->getState().getRow()) +
                (std::abs)(cur->getState().getCol() - dest->getState().getCol()));
    }

};



#endif //PROJECT2_ASTAR_H
