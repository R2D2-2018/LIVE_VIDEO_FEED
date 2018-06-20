/**
 * @file      UDP.cpp
 * @brief     Implementation of UDP classes.
 * @author    Laurens van der Sluis
 * @license   See LICENSE
 */

#include "UDP.hpp"

namespace LiveVideoFeed {

// UDP Superclass
UDP::UDP(const std::string &address, const int port) : address{address}, port{port} {
}

int UDP::getPort() const {
    return port;
}

std::string UDP::getAddress() const {
    return address;
}

void UDP::close() {
}

// CLIENT
UDPClient::UDPClient(const std::string &address, const int port) : UDP(address, port) {
}

void UDPClient::send(const char *data, size_t size) {
}

// SERVER
UDPServer::UDPServer(const std::string &address, const int port) : UDP(address, port) {
}

void UDPServer::receive(char *data, size_t max_size) {
}
} // namespace LiveVideoFeed
