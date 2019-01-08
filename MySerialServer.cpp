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
   /* std::thread t (&start, socketId, c);
    t.detach();*/
    serverThread = std::thread([](int socketId,ClientHandler *c,
            bool* stopRunning) {
        int cliSockfd;
        while (!*stopRunning) {
            cliSockfd = TcpServer::acceptConnection(socketId);
            if (cliSockfd < 0) {
                perror("ERROR on accept");
                exit(1);
            }
            c->handleClient(cliSockfd);
            TcpServer::closeSocket(cliSockfd);
        }

        TcpServer::closeSocket(socketId);

    }, socketId, c, stopRunning);

}

/*void server_side::MySerialServer::start(int socketId, ClientHandler* c) {
    int cliSockfd;
    while (!*(stopRunning)) {
        cliSockfd = TcpServer::acceptConnection(socketId);
        if (cliSockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        c->handleClient(cliSockfd);
        TcpServer::closeSocket(cliSockfd);
    }
    TcpServer::closeSocket(socketId);
}*/

void server_side::MySerialServer::stop() {
    *(this->stopRunning) = true;

    //wait for the thread to end
    serverThread.join();
    delete(this->stopRunning);
}