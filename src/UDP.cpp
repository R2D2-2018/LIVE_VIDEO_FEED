/**
 * @file      UDP.cpp
 * @brief     Implementation of UDP classes.
 * @author    Laurens van der Sluis
 * @license   See LICENSE
 */

#include "UDP.hpp"

namespace LiveVideoFeed {

// UDP Superclass
UDP::UDP(const int port) : UDPsocket{Socket(AF_INET, SOCK_DGRAM, 0)}, port{port} {
    UDPsocket.attach(port);
}

UDP::UDP(const std::string address, const int port) : UDPsocket{Socket(AF_INET, SOCK_DGRAM, 0)}, ipaddress{address}, port{port} {
    UDPsocket.attach(address, port);
}

int UDP::getPort() const {
    return port;
}

std::string UDP::getAddress() {
    return std::string(ipaddress);
}

void UDP::close() {
    UDPsocket.terminate();
}

// CLIENT
UDPClient::UDPClient(const std::string &address, const int port) : UDP(address, port) {
}

void UDPClient::send(const char *data, size_t size) {
    UDPsocket.send(data, size);
}

// SERVER
UDPServer::UDPServer(const std::string &address, const int port) : UDP(address, port) {
}

void UDPServer::receive(char *data, size_t max_size) {
    UDPsocket.receive(data, max_size);
}
} // namespace LiveVideoFeed
