//
// Created by yael on 1/10/19.
//

#include "MyParallelServer.h"
#include "TcpServer.h"

server_side::MyParallelServer::MyParallelServer() {
    this->stopRunning = new bool;
    *(this->stopRunning) = false;
    this->threadVec = new std::vector<std::thread>;
}

void server_side::MyParallelServer::open(int port, ClientHandler *c) {
    int socketId = TcpServer::openSocket(port);
    listen(socketId, SOMAXCONN);
    this->generalThread = std::thread(&start, socketId, c, stopRunning, this->threadVec);
}

void server_side::MyParallelServer::start(int serverSocket, ClientHandler* c,bool *stopRunning, std::vector<std::thread>* threadVec) {
    int cliSockfd;
    //int timeOutCount = 0;
    while (!*(stopRunning)) {
        cliSockfd = TcpServer::acceptConnection(serverSocket);
        if (cliSockfd < 0) {
            continue;
        }
        threadVec->push_back(std::thread(&openThreadForClient, cliSockfd, c));
    }
}

void server_side::MyParallelServer::openThreadForClient(int cliSocket, ClientHandler* c) {
    c->getCache()->loadAtStart();
    c->handleClient(cliSocket);
    c->getCache()->storeAtTheEnd();
    TcpServer::closeSocket(cliSocket);
}

void server_side::MyParallelServer::stop() {
    *(this->stopRunning) = true;
    this->generalThread.join();
    for (std::vector<std::thread>::iterator it = this->threadVec->begin(); it != this->threadVec->end(); it++) {
        it->join();
    }

    delete this->stopRunning;
    delete this->threadVec;
}