/**
 * @file      UDP.cpp
 * @brief     Implementation of UDP classes.
 * @author    Laurens van der Sluis
 * @license   See LICENSE
 */

#include "UDP.hpp"

namespace LiveVideoFeed {

// UDP Superclass
UDP::UDP(int port) : UDPsocket{Socket(AF_INET, SOCK_DGRAM, 0)}, port{port} {
    UDPsocket.attach(port);
}

UDP::UDP(const std::string address, int port) : UDPsocket{Socket(AF_INET, SOCK_DGRAM, 0)}, ipaddress{address}, port{port} {
    UDPsocket.attach(address, port);
}

int UDP::getPort() const {
    return port;
}

const char *UDP::getAddress() const {
    return ipaddress.c_str();
}

void UDP::close() {
    UDPsocket.terminate();
}

// CLIENT
UDPClient::UDPClient(const std::string &address, int port) : UDP(address, port) {
}

void UDPClient::send(const char *data) {
    UDPsocket.send(data);
}

// SERVER
UDPServer::UDPServer(int port) : UDP(port) {
}

int UDPServer::receive(char *data, size_t max_size) {
    return UDPsocket.receive(data, max_size);
}
} // namespace LiveVideoFeed
