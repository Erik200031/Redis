#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace myl {
    class server {
    public:
        server(int argc, char *argv[]);
        ~server();
        server(const server&) = delete;
        server& operator=(const server&) = delete;
        server(server&&) = delete;
        server& operator=(server&&) = delete;
    private:
        void conect(int argc, char *argv[]);
        void communicate();
        void error(const char*);
    private:
        int sockfd;
        int newsockfd;
        int portno;
        socklen_t clilen;
        sockaddr_in serv_addr;
        sockaddr_in cli_addr;
    };
}

#endif