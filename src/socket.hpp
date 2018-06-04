/**
 * @file    socket.hpp
 * @brief   Socket class declaration. This class aims for cross-platform functionality.
 * @author  Nick Swaerdens
 * @license See LICENSE
 */

#ifndef SOCKET
#define SOCKET

// Socket includes for different OS.
#if defined(__linux) || defined(__linux__) || defined(linux)
#define __LINUX__
#include <sys/socket.h>
#include <sys/types.h>

#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64)
#define __WINDOWS__
#include <winsock2.h>
#endif

namespace LiveVideoFeed {
class Socket {
  protected:
    int sockfd;

  public:
};

} // namespace LiveVideoFeed

#endif // SOCKET