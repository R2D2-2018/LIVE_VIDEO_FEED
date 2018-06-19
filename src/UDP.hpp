#ifndef UDP_HH
#define UDP_HH

#include "socket.hpp"
#include <netdb.h>
#include <stdexcept>
#include <sys/socket.h>
#include <sys/types.h>

namespace LiveVideoFeed {
class UDPClient : public Socket {
  private:
    Socket UDPsocket;
    std::string addr;
    int port;

  public:
    UDPClient(const std::string &addr, int port);
};

class UDPServer : public Socket {
  private:
    Socket UDPsocket;
    std::string addr;
    int port;

  public:
    UDPServer(const std::string &addr, int port);
};

} // namespace LiveVideoFeed
#endif
// UDP_HH