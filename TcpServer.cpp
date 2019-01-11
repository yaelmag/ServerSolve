//
// Created by adi on 08/01/19.
//

#include "TcpServer.h"
#define BUFFER_SIZE 1024

namespace server_side {
    int server_side::TcpServer::openSocket(int port) {
        int serverSockfd;
        struct sockaddr_in serv_addr;

        /* First call to socket() function */
        serverSockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (serverSockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }

        /* Initialize socket structure */
        bzero((char *) &serv_addr, sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(port);

        /* Now bind the host address using bind() call.*/
        if (bind(serverSockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR on binding");
            exit(1);
        }

        /* Now start listening for the clients, here process will
           * go in sleep mode and will wait for the incoming connection
        */
        listen(serverSockfd, 5);
        return serverSockfd;
    }

    int server_side::TcpServer::acceptConnection(int socketId) {
        int clilen, cliSockfd;
        struct sockaddr_in cli_addr;
        clilen = sizeof(cli_addr);

        //set accept timeout
        timeval timeout;
        // Timeout in seconds
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        //std::cout<<"before 30"<<std::endl;
        setsockopt(socketId, SOL_SOCKET, SO_RCVTIMEO,(char*)&timeout,sizeof(timeout));
        //setsockopt(socketId, SOL_SOCKET, SO_RCVTIMEO,&tv,sizeof(struct timeval));
        /* Accept actual connection from the client */
        cliSockfd = accept(socketId, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        //std::cout<<"finish 30 seconds"<<std::endl;
        return cliSockfd;
    }

    void server_side::TcpServer::closeSocket(int socketId) {
        close(socketId);
    }

    std::string server_side::TcpServer::readLine(int cliSock) {
        char buffer[BUFFER_SIZE], c;
        std::string msg;
        int n;
        msg = "";
        // If connection is established then start communicating *//*
        bzero(buffer, (BUFFER_SIZE));
        n = read(cliSock, &c, 1);
        // n = read(cliSock, buffer, (BUFFER_SIZE - 1));
        while (c != '\n') {
            if (n < 0) {
                if (errno == EWOULDBLOCK) {
                    continue;
                }
                perror("ERROR reading from socket");
                exit(1);
            }
            msg += c;
            n = read(cliSock, &c, 1);
        }
        return msg;
    }

    void server_side::TcpServer::writeToClient(int cliSock, std::string message) {
        /* Send message to the client */
        if (send(cliSock, message.c_str(), strlen(message.c_str()), 0) < 0) {
            perror("send failed: ");
            exit(1);
        }
    }
}