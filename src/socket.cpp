/**
 * @file      socket.cpp
 * @brief     Implementation of Socket class.
 * @author    Laurens van der Sluis
 * @license   See LICENSE
 */

#include "socket.hpp"

namespace LiveVideoFeed {

Socket::Socket(const int domain, const int type, const int protocol) : domain{domain}, type{type}, protocol{protocol} {
#ifdef __LINUX__
    sockfd = socket(domain, type, protocol);
    if (sockfd < 0) {
        throw SockExceptionHandler("Failed to create socket");
    }

#elif defined __WINDOWS__
    // Code for windows implementation

    // Initialize winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        throw SockExceptionHandler("Failed to initialize winsock");
    }

    // Create socket
    sockfd = socket(domain, type, protocol);
    if (sockfd == INVALID_SOCKET) {
        throw SockExceptionHandler("Failed to create socket");
    }

#endif
}

void Socket::attach(const int &port) {
#ifdef __LINUX__
    // Code for linux implementation
    memset(reinterpret_cast<char *>(&socketSettings), 0, sizeof(socketSettings));
    socketSettings.sin_family = AF_INET;
    socketSettings.sin_addr.s_addr = htonl(INADDR_ANY);
    socketSettings.sin_port = htons(port);

    if (bind(sockfd, reinterpret_cast<struct sockaddr *>(&socketSettings), sizeof(socketSettings)) < 0) {
        throw SockExceptionHandler("Failed to attach socket properties");
    }

#elif defined __WINDOWS__
    // Code for windows implementation
    socketSettings.sin_family = AF_INET;
    socketSettings.sin_addr.s_addr = INADDR_ANY;
    socketSettings.sin_port = htons(port);

    if (bind(sockfd, reinterpret_cast<struct sockaddr *>(&socketSettings), sizeof(socketSettings)) == SOCKET_ERROR) {
        throw SockExceptionHandler("Failed to attach socket properties");
    }
#endif
}

void Socket::attach(const std::string &address, const int &port) {
#ifdef __LINUX__
    // Code for windows implementation
    inet_pton(AF_INET, address.c_str(), &(socketSettings.sin_addr)); // Convert ip string
    memset(reinterpret_cast<char *>(&socketSettings), 0, sizeof(socketSettings));
    socketSettings.sin_family = AF_INET;
    socketSettings.sin_port = htons(port);

#elif defined __WINDOWS__
    // Code for windows implementation
    memset(reinterpret_cast<char *>(&socketSettings), 0, sizeof(socketSettings));
    socketSettings.sin_family = AF_INET;
    socketSettings.sin_port = htons(port);
    socketSettings.sin_addr.S_un.S_addr = inet_addr(address.c_str());
#endif
}

void Socket::send(const char *data) {
    if (sendto(sockfd, data, strlen(data), 0, reinterpret_cast<struct sockaddr *>(&socketSettings), sizeof(socketSettings)) < 0) {
        throw SockExceptionHandler("Failed to send message");
    }
}

int Socket::receive(char *data, size_t max_size) {
#ifdef __LINUX__
    // Code for linux implementation
    socklen_t remoteSocketSettingsLength = sizeof(remoteSocketSettings);
    return recvfrom(sockfd, data, max_size, 0, reinterpret_cast<struct sockaddr *>(&remoteSocketSettings),
                    &remoteSocketSettingsLength);

#elif defined __WINDOWS__
    // Code for linux implementation
    int remoteSocketSettingsLength = sizeof(remoteSocketSettings);
    return recvfrom(sockfd, data, max_size, 0, reinterpret_cast<struct sockaddr *>(&remoteSocketSettings),
                    &remoteSocketSettingsLength);
#endif
}

void Socket::terminate() {
#ifdef __LINUX__
    // Code for linux implementation
    close(sockfd);

#elif defined __WINDOWS__
    // Code for windows implementation
    closesocket(sockfd);
    WSACleanup();
#endif
}

Socket::~Socket() {
    this->terminate();
}

} // namespace LiveVideoFeed