//
// Created by yael on 1/6/19.
//

#ifndef PROJECT2_MYSERIALSERVER_H
#define PROJECT2_MYSERIALSERVER_H

#include "server_side.h"

using namespace server_side;

class MySerialServer : public Server {
public:
    void open(int port, ClientHandler c) override;

    void close() override;
};


#endif //PROJECT2_MYSERIALSERVER_H
