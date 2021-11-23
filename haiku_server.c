#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

// definition of the PORT
#define PORT 5755

// message of haiku
const char haiku_msg[] = "Birds fly through the wind\nThe wind blows through the blue sky\nWinds of change grow close";

int main()
{
int server_fd, new_socket;
struct sockaddr_in address;
int addrlen = sizeof(address);
// Creating socket file descriptor
if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
perror("socket failed");
exit(EXIT_FAILURE);

}

address.sin_family = AF_INET;

address.sin_addr.s_addr = INADDR_ANY;

address.sin_port = htons(PORT);

if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {

perror("bind failed");

exit(EXIT_FAILURE);

}

printf("haiku server started...\n\n");

if (listen(server_fd, 5) < 0) {

perror("listen");

exit(EXIT_FAILURE);

}

if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {

perror("accept");

exit(EXIT_FAILURE);

}

printf("\nClient connected to haiku server.\nsending msg.\n");

send(new_socket, haiku_msg, strlen(haiku_msg), 0);

printf("haiku sent to client.\n\n");

return 0;

}





