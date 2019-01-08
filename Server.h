//
// Created by yael on 1/6/19.
//

#ifndef PROJECT2_SERVER_SIDE_H
#define PROJECT2_SERVER_SIDE_H


#include "ClientHandler.h"

namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler* c) = 0;
        virtual void stop() = 0;
        static void start(int socketId, ClientHandler* c);
    };
}


#endif //PROJECT2_SERVER_SIDE_H
