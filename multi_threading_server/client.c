// MUTLI THREAD SERVER CLIENT - ROMAN AHMAD ZEIA 100821974
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"


int main(int argc, char *argv[]) {

    int client_socket; // client socket
    struct sockaddr_in server_addr; 
    char buffer[256]; // buffer for username and password

    // create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // connecting to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    printf("Connection established\n");

    // send username and password to server
    snprintf(buffer, sizeof(buffer), "%s %s", argv[1], argv[2]); // storing the username and password to the buffer
    send(client_socket, buffer, strlen(buffer), 0); // sending info
    printf("Login Info sent to the Server\n");
    printf("Waiting for response\n");
    // Receive authentication response from server
    recv(client_socket, buffer, sizeof(buffer), 0); // receive response from server
    printf("Received from the Server -> %s\n", buffer);

    close(client_socket); // close the connection
    return 0;
}
