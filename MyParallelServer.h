//
// Created by yael on 1/10/19.
//

#ifndef PROJECT2_MYPARALLELSERVER_H
#define PROJECT2_MYPARALLELSERVER_H

#include <thread>
#include <vector>
#include "Server.h"

using namespace std;
namespace server_side {
    class MyParallelServer : public Server {
        bool* stopRunning;
        std::thread generalThread;
        std::vector<std::thread> * threadVec;
    public:
        MyParallelServer();
        void open(int port, ClientHandler *c) override;
        static void start(int socketId, ClientHandler* c, bool* stopRunning, std::vector<std::thread>* threadVec);
        static void openThreadForClient(int cliSocket, ClientHandler* c);
        void stop() override;
    };
}

#endif //PROJECT2_MYPARALLELSERVER_H