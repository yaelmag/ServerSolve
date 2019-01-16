//
// Created by yael on 1/6/19.
//


#include "MySerialServer.h"
#include "TcpServer.h"

server_side::MySerialServer::MySerialServer() {
    this->stopRunning = new bool();
    *(this->stopRunning) = false;
}

void server_side::MySerialServer::open(int port, ClientHandler* c) {
    int socketId = TcpServer::openSocket(port);
    this->serverThread = std::thread(&start, socketId, c, stopRunning);
}

void server_side::MySerialServer::start(int socketId, ClientHandler* c, bool *stopRunning) {
    int cliSockfd;
    int timeOutCount= 0;
    c->getCache()->loadAtStart();
    while (!*(stopRunning)) {
        cliSockfd = TcpServer::acceptConnection(true, socketId);
        if (cliSockfd < 0) {
            if (errno == EWOULDBLOCK) {
                std::cout << "timeout!" << std::endl;
                if (++timeOutCount == 3) {
                    *stopRunning = true;
                }
                continue;
            } else {
                perror("other error");
                exit(3);
            }
        }
        c->handleClient(cliSockfd);
        TcpServer::closeSocket(cliSockfd);
    }
    c->getCache()->storeAtTheEnd();
    TcpServer::closeSocket(socketId);
}

void server_side::MySerialServer::stop() {
    *(this->stopRunning) = true;
    //wait for the thread to end
    serverThread.join();
    delete(this->stopRunning);
}