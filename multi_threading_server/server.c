// MUTLI THREAD SERVER - ROMAN AHMAD ZEIA 100821974
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5 // max number of clients

struct Login {         // pre defined struct for a login of username and password
    char userName[8];
    char password[8];
};

struct Login logins[5] = { // hard coded logins to test
    {"john", "12345"},
    {"steve", "canada"},
    {"bill", "ontario"},
    {"elon", "tesla"},
    {"tim", "apple"}
};

void *login_client(void *arg) { // method to handle the clients on the server
    int client_socket = *((int *)arg); // makes client socket
    char buffer[256];       // a buffer to hold clients input

    // Receive username and password from client
    recv(client_socket, buffer, sizeof(buffer), 0); // receive response


    // check if username and password match
    int flag = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(logins[i].userName, strtok(buffer, " ")) == 0 &&
            strcmp(logins[i].password, strtok(NULL, " ")) == 0) {
            flag = 1;
            break;
        }
    }

    // send authentication response based on flag value, 1 = success, 0 = unsuccessful
    if (flag)
        send(client_socket, "Login Successful", strlen("Login Successful"), 0);
    else
        send(client_socket, "Login Unsuccessful", strlen("Login Unsuccessful"), 0);
    printf("Authentication response sent\n");

    close(client_socket); // close the connection
    free(arg);          // free the memory
    pthread_exit(NULL); //exit thread
}

int main() {
    int server_socket; //server socket
    int client_socket; // client socket
    int addr_len; //length of address
    struct sockaddr_in server_addr, client_addr;
    pthread_t *threads[MAX_CLIENTS]; // new thread
    int *new_client_socket; // points to a new client socket

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) { // create socket
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Server socket created!\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) { // bind socket
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }
    printf("Socket bound successfully\n");

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Socket listening failed");
        exit(EXIT_FAILURE);
    }
    printf("Listening to socket\n");

    while (1) { // a while loop to keep accepting connections
        addr_len = sizeof(struct sockaddr_in);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len)) == -1) {
            perror("Connection accepting failed");
            exit(EXIT_FAILURE);
        }
        printf("Accepting new connections!\n");
        printf("Connection Established with %s\n", inet_ntoa(client_addr.sin_addr));

        new_client_socket = (int *)malloc(sizeof(int)); // allocate memory for client
        if (new_client_socket == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        *new_client_socket = client_socket;

        threads[MAX_CLIENTS] = (pthread_t *)malloc(sizeof(pthread_t));
        if (threads[MAX_CLIENTS] == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        if (pthread_create(threads[MAX_CLIENTS], NULL, login_client, (void *)new_client_socket) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
        printf("Client requesting for authentication...\n");
    }

    close(server_socket); // close the server when complete
    return 0;
}
