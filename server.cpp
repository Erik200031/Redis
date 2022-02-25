#include "server.h"

myl::server::server(int argc, char **argv)
{
    conect(argc,argv);
    communicate();
}

void myl::server::conect(int argc, char **argv)
{
    if (argc < 2) {
        error("ERROR, no port provided\n");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0) {
        error("ERROR on accept");
    }
}

void myl::server::communicate()
{
    char buffer[256];
    while (strcmp(buffer,"Exit"))
    {
        bzero(buffer,256);
        int n = read(newsockfd,buffer,255);

        if (n < 0) {
            error("ERROR reading from socket");
        }

        std::cout << "Here is the message: " << buffer << std::endl; // tpume clientis stacac stringy

        n = write(newsockfd,"OK",3);  // uxarkum e clientin tvac stringy

        if (n < 0) {
            error("ERROR writing to socket");
        }
    }
}

void myl::server::error(const char *msg)
{
    std::cerr << msg << std::endl;
    throw;
}

myl::server::~server()
{
    close(newsockfd);
    close(sockfd);
}

int main(int argc, char **argv)
{
    myl::server ob(argc,argv);
}