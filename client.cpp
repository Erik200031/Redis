#include "client.h"

myl::client::client(int argc, char **argv)
{
    conect(argc,argv);
    communicate();
}

myl::client::~client()
{
    close(sockfd);
}

void myl::client::conect(int argc, char **argv)
{
    if (argc < 3) {
        std::cout << "usage " << argv[0] << " hostname port" << std::endl;
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        error("ERROR, no such host");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
}

void myl::client::communicate()
{
    String buffer;

    while(true)
    {
        buffer.clear();
        //std::getline(std::cin,buffer);
        std::cin >> buffer;
        n = write(sockfd,buffer.c_str(),strlen(buffer.c_str()));  //uxarkume namak serverin

        if(buffer == "QUIT") break;

        if (n < 0) {
            error("ERROR writing to socket");
        }

        bzero(const_cast<char*>(buffer.c_str()), buffer.size());

        n = read(sockfd, const_cast<char*>(buffer.c_str()), buffer.size()); // stanume namak serveric

        if (n < 0) {
            error("ERROR reading from socket");
        }

        std::cout << buffer << std::endl; // tpume serveric ekac namaky
    }
}

void myl::client::error(const char *msg)
{
    std::cerr << msg << std::endl;
    throw;
}

int main(int argc, char *argv[])
{
    myl::client ob(argc,argv);
}