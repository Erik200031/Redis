#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <string>

namespace myl {
    class client
    {
    public:
        client(int argc, char *argv[]);
        ~client();
        client(const client&) = delete;
        client& operator=(const client&) = delete;
        client(client&&) = delete;
        client& operator=(client&&) = delete;
    private:
        void conect(int argc, char *argv[]);
        void communicate();
        void error(const char *msg);
    private:
        int sockfd;
        int portno;
        int n;
        sockaddr_in serv_addr;
        hostent *server;
    };
}

#endif