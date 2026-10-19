#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Create TCP socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("Socket creation failed");
        return 1;
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        close(server_fd);
        return 1;
    }

    // Listen for connections
    if (listen(server_fd, 5) < 0)
    {
        perror("Listen failed");
        close(server_fd);
        return 1;
    }

    printf("TCP Server waiting on port %d...\n", PORT);

    // Accept client connection
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0)
    {
        perror("Accept failed");
        close(server_fd);
        return 1;
    }

    printf("Client connected successfully!\n");

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        int bytes = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
        if (bytes <= 0)
        {
            printf("Client disconnected.\n");
            break;
        }

        buffer[bytes] = '\0';
        printf("Client: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0)
            break;

        printf("Enter reply: ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            break;

        buffer[strcspn(buffer, "\n")] = '\0';

        if (send(client_fd, buffer, strlen(buffer), 0) < 0)
        {
            perror("Send failed");
            break;
        }

        if (strcmp(buffer, "exit") == 0)
            break;
    }

    close(client_fd);
    close(server_fd);
    return 0;
}
