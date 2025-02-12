#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    SOCKADDR_IN serverAddr, clientAddr;
    int clientAddrSize = sizeof(clientAddr);
    char message[1024];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return 1;
    }

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "socket creation failed" << std::endl;
        WSACleanup();
        return 1;
    }

    // Bind socket to port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(1234);
    if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "socket binding failed" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "socket listening failed" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Accept incoming connection
    std::cout << "Waiting for client connection..." << std::endl;
    clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &clientAddrSize);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "socket accept failed" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    std::cout << "Client connected" << std::endl;

    // Receive and send messages
    while (true) {
        int bytesReceived = recv(clientSocket, message, sizeof(message), 0);
        if (bytesReceived == SOCKET_ERROR) {
            std::cerr << "socket receive failed" << std::endl;
            break;
        }
        std::cout << "Received message: " << message << std::endl;
        if(bytesReceived > 0){
            
        }
    }

    // Cleanup
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
