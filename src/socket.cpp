/**
 * @file      socket.cpp
 * @brief     Implementation of Socket class.
 * @author    Laurens van der Sluis
 * @license   See LICENSE
 */

#include "socket.hpp"

namespace LiveVideoFeed {

Socket::Socket(const int domain, const int type, const int protocol) : domain{domain}, type{type}, protocol{protocol} {
    sockfd = socket(domain, type, protocol);
    if (sockfd < 0) {
        throw SockExceptionHandler("Failed to create socket");
    }
}

void Socket::attach(int port) {
    memset((char *)&socketSettings, 0, sizeof(socketSettings));
    socketSettings.sin_family = AF_INET;
    socketSettings.sin_addr.s_addr = htonl(INADDR_ANY);
    socketSettings.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&socketSettings, sizeof(socketSettings)) < 0) {
        throw SockExceptionHandler("Failed to attach socket properties");
    }
}

void Socket::attach(const std::string &address, int port) {
    inet_pton(AF_INET, address.c_str(), &(socketSettings.sin_addr)); // Convert ip string
    memset((char *)&socketSettings, 0, sizeof(socketSettings));
    socketSettings.sin_family = AF_INET;
    socketSettings.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&socketSettings, sizeof(socketSettings)) < 0) {
        throw SockExceptionHandler("Failed to attach socket properties");
    }
}

void Socket::send(const char *data, size_t size) {
#ifdef __LINUX__
// Code for linux implementation
#elif defined __WINDOWS__
// Code for windows implementation
#endif
}

void Socket::receive(char *data, size_t max_size) {
#ifdef __LINUX__

#elif defined __WINDOWS__

#endif
}

void Socket::terminate() {
#ifdef __LINUX__
    // Code for linux implementation
    close(sockfd);
#elif defined __WINDOWS__
// Code for windows implementation
#endif
}
} // namespace LiveVideoFeed