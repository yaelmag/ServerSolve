//
// Created by yael on 1/15/19.
//

#ifndef PROJECT2_PRIORITYQUEUE_H
#define PROJECT2_PRIORITYQUEUE_H

#include <queue>

/**
 * wrapper for the built in priority queue. enables to send priority as parameter
 */
namespace server_side {

    template<typename T, typename priority_t>
    struct PriorityQueue {
        typedef std::pair<priority_t, T> PQElement;
        std::priority_queue<PQElement, std::vector<PQElement>,
                std::greater<PQElement>> elements;

        inline bool empty() const {
            return elements.empty();
        }

        inline void put(T item, priority_t priority) {
            elements.emplace(priority, item);
        }

        T get() {
            T best_item = elements.top().second;
            elements.pop();
            return best_item;
        }
    };
}


#endif //PROJECT2_PRIORITYQUEUE_H