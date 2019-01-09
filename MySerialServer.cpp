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
    std::thread serverThread (&start, socketId, c, stopRunning);
    serverThread.join();
    std::cout << "beforethread" << std::endl;
    /*serverThread = std::thread([](int socketId,ClientHandler *c,
            bool* stopRunning) {
        *//*int cliSockfd;*//*
        std::cout << "outsideloop" << std::endl;
        while (!(*stopRunning)) {
            std::cout << "inloop" << std::endl;
            int cliSockfd = TcpServer::acceptConnection(socketId);
            if (cliSockfd < 0) {
                perror("ERROR on accept");
                exit(1);
            }
            c->handleClient(cliSockfd);
            TcpServer::closeSocket(cliSockfd);
        }

        TcpServer::closeSocket(socketId);

    }, socketId, c, stopRunning);
*/
}

void server_side::MySerialServer::start(int socketId, ClientHandler* c, bool *stopRunning) {
    int cliSockfd;
    while (!*(stopRunning)) {
        std::cout<<"infunc"<<std::endl;
        cliSockfd = TcpServer::acceptConnection(socketId);
        if (cliSockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        std::cout<<"yayy"<<std::endl;
        c->handleClient(cliSockfd);
        TcpServer::closeSocket(cliSockfd);
    }
    TcpServer::closeSocket(socketId);
}

void server_side::MySerialServer::stop() {
    *(this->stopRunning) = true;

    //wait for the thread to end
    serverThread.join();
    delete(this->stopRunning);
}