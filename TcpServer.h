//
// Created by adi on 08/01/19.
//

#ifndef PROJECT2_TCPSERVER_H
#define PROJECT2_TCPSERVER_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <sys/socket.h>
#include <sstream>

namespace server_side {
    class TcpServer {
    public:
        static int openSocket(int port);
        static int acceptConnection(int socketId);
        static void closeSocket(int socketId);
        static std::string readData(int cliSock);
    };
}

#endif //PROJECT2_TCPSERVER_H
