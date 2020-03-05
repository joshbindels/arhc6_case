#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>


#define PORT 8080


int main(int argc, char** argv)
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;

    if(socket_fd == -1)
    {
        puts("Couldn't create socket");
        return -1;
    }
    else
    {
        puts("Created socket");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if(connect(socket_fd, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    puts("Connected");


    return 0;
}
