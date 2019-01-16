//
// Created by yael on 1/10/19.
//

#include "MyParallelServer.h"
#include "TcpServer.h"

server_side::MyParallelServer::MyParallelServer() = default;

void server_side::MyParallelServer::open(int port, ClientHandler *c) {
    this->serverSock = TcpServer::openSocket(port);
    listen(this->serverSock, SOMAXCONN);
    start(this->serverSock, c);
}

void server_side::MyParallelServer::start(int serverSocket, ClientHandler *c) {
    bool stillRun = true;
    int cliSockfd;
    bool afterFirstConnection = false;
    while (stillRun) {
        cliSockfd = TcpServer::acceptConnection(afterFirstConnection, serverSocket);
        afterFirstConnection = true;
        if (cliSockfd < 0) {
            if (errno == EWOULDBLOCK) {
                stillRun = false;
                continue;
            } else {
                continue;
            }
        }
        threadVec.push_back(new std::thread(&openThreadForClient, cliSockfd, c));
    }
}

void server_side::MyParallelServer::openThreadForClient(int cliSocket, ClientHandler *c) {
    c->getCache()->loadAtStart();
    c->handleClient(cliSocket);
    c->getCache()->storeAtTheEnd();
    TcpServer::closeSocket(cliSocket);
}

void server_side::MyParallelServer::stop() {
    for (std::vector<std::thread *>::iterator it = this->threadVec.begin(); it != this->threadVec.end(); it++) {
        (*(it))->join();
        delete(*it);
    }
    close(this->serverSock);
}