#ifndef UDP_HH
#define UDP_HH

#include "socket.hpp"
#include <stdexcept>

namespace LiveVideoFeed {
class UDP {
  protected:
    Socket UDPsocket;
    std::string address;
    int port;

  public:
    UDP(const std::string &address, const int port);

    int getPort() const;

    std::string getAddress() const;

    void close();
};

class UDPClient : public UDP {
  public:
    UDPClient(const std::string &address, int port);

    void send(const char *data, size_t size);
};

class UDPServer : public UDP {
  public:
    UDPServer(const std::string &address, int port);

    void receive(char *data, size_t max_size);
};

} // namespace LiveVideoFeed
#endif
// UDP_HH