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

void Socket::close() {
#ifdef __LINUX__
// Code for linux implementation
#elif defined __WINDOWS__
// Code for windows implementation
#endif
}
} // namespace LiveVideoFeed