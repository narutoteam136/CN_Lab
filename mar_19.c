#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
    int sock;
    struct sockaddr_in server;
    char request[500], response[2000];

    // Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);

    server.sin_addr.s_addr = inet_addr("93.184.216.34"); // example.com IP
    server.sin_family = AF_INET;
    server.sin_port = htons(80); // HTTP port

    // Connect to server
    connect(sock , (struct sockaddr *)&server , sizeof(server));

    // HTTP GET request
    strcpy(request ,
    "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n");

    // Send request
    send(sock , request , strlen(request) , 0);

    // Receive response
    while(recv(sock , response , 2000 , 0) > 0)
    {
        printf("%s", response);
    }

    close(sock);

    return 0;
}
