//
//  run_server.c
//  DataProject
//
//  Created by Nunu Nugraha on 25/02/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, const char * argv[]) {
    int server_fd, new_socket;
    long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    // HTTP response header
    char *httpHeader = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\n";
    // HTTP response body
    char *httpBody = "";
    
    // Membuat socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("In socket");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
    
    // Bind socket ke port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    
    // mendengarkan koneksi masuk
    if (listen(server_fd, 10) < 0) {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
    
    
    // terima koneksi dan kirim response
    while (1) {
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("in accept");
            exit(EXIT_FAILURE);
        }
        
        char buffer[30000] = {0};
        valread = read( new_socket, buffer, 30000);
        printf("%s\n", buffer);
       
        // Send the HTTP response header
        write(new_socket, httpHeader, strlen(httpHeader));
        // Send the HTTP response body
        httpBody = "Hello there... Dorothy...";
        write(new_socket, httpBody, strlen(httpBody));
        
        printf("------------------Hello message sent-------------------\n");
        close(new_socket);
    }
    
    return 0;
}

