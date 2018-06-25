#include "UDP.hpp"
#include "sock_exception_handler.hpp"
#include <chrono>
#include <iostream>
#include <thread>

int main() {
    bool server = 1;

    if (!server) {
        char serveraddress[] = "127.0.0.1";
        int port = 26296;

        LiveVideoFeed::UDPClient LVFclient(serveraddress, port);
        std::cout << "UDP Client sending to: " << LVFclient.getAddress() << " at port: " << LVFclient.getPort() << '\n';

        while (true) {
            LVFclient.send("Message for testing Live Video Feed UDP transfer.\n", 51);
            std::cout << "Message send.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    if (server) {
        int port = 26296;
        char data[100];

        LiveVideoFeed::UDPServer LVFserver(port);
        std::cout << "UDP Client Listening on: "
                  << "Not implemented yet"
                  << " at port: " << LVFserver.getPort() << '\n';

        while (true) {
            int datalength;
            datalength = LVFserver.receive(data, 100);
            std::cout << "received " << datalength << " bytes:\n";
            if (datalength > 0) {
                for (int i = 0; datalength > i; ++i) {
                    std::cout << data[i];
                }
            }
        }
    }

    return 0;
}
