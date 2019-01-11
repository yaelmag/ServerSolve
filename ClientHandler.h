//
// Created by yael on 1/6/19.
//

#ifndef PROJECT2_CLIENTHANDLER_H
#define PROJECT2_CLIENTHANDLER_H

#include "CacheManager.h"

class ClientHandler {
public:
    virtual void handleClient(int cliSocket) = 0;

    virtual CacheManager* getCache() {}

    virtual ~ClientHandler() = default;
};


#endif //PROJECT2_CLIENTHANDLER_H
