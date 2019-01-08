//
// Created by yael on 1/6/19.
//

#ifndef PROJECT2_MYSERIALSERVER_H
#define PROJECT2_MYSERIALSERVER_H

#include "Server.h"
#include <thread>

namespace server_side {

    class MySerialServer : public Server {
        bool* stopRunning;
        std::thread serverThread;
    public:
        MySerialServer();
        void open(int port, ClientHandler* c) override;
        void stop() override;
        static void start(int socketId, ClientHandler* c, bool *stopRunning);
    };

}

#endif //PROJECT2_MYSERIALSERVER_H
