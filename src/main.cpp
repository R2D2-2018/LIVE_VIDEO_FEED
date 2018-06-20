#include "UDP.hpp"
#include "sock_exception_handler.hpp"
#include <iostream>

int main() {
    LiveVideoFeed::UDPServer LVFserver("192.168.68.120", 26296);
    std::cout << LVFserver.getAddress() << '\n';
    std::cout << LVFserver.getPort() << '\n';
    return 0;
}
