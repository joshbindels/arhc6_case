#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>


#define PORT 8080

int main(int argc, char** argv)
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    int client_connection_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int opt = 1;
    int buffer_size = 1024;
    char buffer[buffer_size];

    if(socket_fd == -1)
    {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR|SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Failed setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if(bind(socket_fd, (struct sockaddr*)&address, sizeof(address))<0)
    {
        perror("Failed bind");
        exit(EXIT_FAILURE);
    }

    if(listen(socket_fd, 3) < 0)
    {
        perror("failed listen");
        exit(EXIT_FAILURE);
    }

    puts("Listening");

    client_connection_fd = accept(socket_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if(client_connection_fd < 0)
    {
        perror("Failed to accept client");
        exit(EXIT_FAILURE);
    }

    puts("Received connection");

    read(client_connection_fd, buffer, buffer_size);
    puts(buffer);

    return 0;

}
