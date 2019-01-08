//
// Created by yael on 1/6/19.
//


#include "MySerialServer.h"
#include "TcpServer.h"
#include <thread>


server_side::MySerialServer::MySerialServer() {
    this->stopRunning = false;
}

void server_side::MySerialServer::open(int port, ClientHandler* c) {
    int socketId = TcpServer::openSocket(port);
    std::thread t (&start, socketId, c);
    t.detach();
}

void server_side::MySerialServer::start(int socketId, ClientHandler* c) {
    int cliSockfd;
    while (!stopRunning) {
        cliSockfd = TcpServer::acceptConnection(socketId);
        if (cliSockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        c->handleClient(cliSockfd);
        TcpServer::closeSocket(cliSockfd);
    }
    TcpServer::closeSocket(socketId);
}

void server_side::MySerialServer::stop() {
    this->stopRunning = true;
}