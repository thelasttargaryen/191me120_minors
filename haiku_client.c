#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#include <arpa/inet.h>

#include <sys/socket.h>

#include <netinet/in.h>

// Here we have defined the PORT

#define PORT 5755

int main()

{

char buffer[1024] = "";

struct sockaddr_in address;

struct sockaddr_in serv_addr;

int sock = 0;

if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)

{

printf("\n Socket creation error \n");

return -1;

}

memset(&serv_addr, '0', sizeof(serv_addr));

serv_addr.sin_family = AF_INET;

serv_addr.sin_port = htons(PORT);

// Convert IPv4 and IPv6 addresses from text to binary form

if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)

{

printf("\nInvalid address/ Address not supported \n");

return -1;

}

if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)

{

printf("\nConnection Failed \n");

return -1;

}

read( sock , buffer, 1024);

printf("\nMessage from server : \n%s\n\n",buffer );

return 0;

}