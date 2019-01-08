//
// Created by yael on 1/6/19.
//

#ifndef PROJECT2_MYSERIALSERVER_H
#define PROJECT2_MYSERIALSERVER_H

#include "Server.h"

namespace server_side {

    class MySerialServer : public Server {
        bool stopRunning;
    public:
        MySerialServer();
        void open(int port, ClientHandler* c) override;
        void stop() override;
        void start(int socketId, ClientHandler* c) override;
    };

}

#endif //PROJECT2_MYSERIALSERVER_H
