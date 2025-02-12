#include <stdio.h>
#include <winsock2.h>

#define DEFAULT_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nHello, world!";
    char buffer[BUFFER_SIZE];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "Failed to initialize Winsock\n");
        return 1;
    }

    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        fprintf(stderr, "Failed to create socket\n");
        WSACleanup();
        return 1;
    }

    // Set up the server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(DEFAULT_PORT);

    // Bind the socket to the server address
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        fprintf(stderr, "Bind failed\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        fprintf(stderr, "Listen failed\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("Server is running on http://localhost:%d\n", DEFAULT_PORT);

    while (1) {
        int clientAddrLen = sizeof(clientAddr);

        // Accept a client connection
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (clientSocket == INVALID_SOCKET) {
            fprintf(stderr, "Accept failed\n");
            closesocket(serverSocket);
            WSACleanup();
            return 1;
        }

        // Read client request
        int bytesRead = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesRead == SOCKET_ERROR) {
            fprintf(stderr, "Receive failed\n");
            closesocket(clientSocket);
            continue;
        }

        // Send response to client
        if (send(clientSocket, response, strlen(response), 0) == SOCKET_ERROR) {
            fprintf(stderr, "Send failed\n");
            closesocket(clientSocket);
            continue;
        }

        // Close the client socket
        closesocket(clientSocket);
    }

    // Close the server socket
    closesocket(serverSocket);

    // Cleanup Winsock
    WSACleanup();

    return 0;
}
