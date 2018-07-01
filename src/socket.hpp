/**
 * @file    socket.hpp
 * @brief   Socket class declaration. This class aims for cross-platform functionality.
 * @author  Laurens van der Sluis
 * @license See LICENSE
 */

#ifndef SOCKET_HH
#define SOCKET_HH
#include "sock_exception_handler.hpp"
#include <cstring>
#include <iostream>

// Socket includes for different OS.
#if defined(__linux) || defined(__linux__) || defined(linux)
#define __LINUX__
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64)
#define __WINDOWS__
#include <winsock2.h>
#endif

namespace LiveVideoFeed {
class Socket {
  private:
    int domain, type, protocol;
    struct sockaddr_in socketSettings;
    struct sockaddr_in remoteSocketSettings;

  protected:
#ifdef __LINUX__
    // Code for linux implementation
    int sockfd;
#elif defined __WINDOWS__
    // Code for windows implementation
    SOCKET sockfd;
    WSADATA wsa;
#endif

  public:
    Socket(const int domain, const int type, const int protocol);

    /**
     * @brief Attach a port to socket.
     *
     * This function will bind the necessary properties to a socket for use as a server.
     * Only supply this function with a port to listen on.
     *
     * @param[in]     port    The port number to connect with.
     */
    void attach(const int &port);

    /**
     * @brief Attach address and port to socket.
     *
     * This function will bind the necessary properties to a socket for use as a client.
     * The address will hold the ip address of the server to connect to.
     * The port number will be the port that will be used to connect with.
     *
     * @param[in]     &address    A std::string ipaddress of a server to connect to.
     * @param[in]     port    The port number to connect with.
     */
    void attach(const std::string &address, const int &port);

    /**
     * @brief Send data.
     *
     * Call this function with a char array and the size of the array to send it over UDP.
     * The implementation of this function depends on the platform it was compiled on.
     *
     * @param[in]     *data    The array to send.
     */
    void send(const char *data);

    /**
     * @brief Receive data.
     *
     * Call this function to receive incomming data. Supply this function with an char array to store the incomming data.
     * Also specify the maximum length of the array.
     * The implementation of this function depends on the platform it was compiled on.
     *
     * @param[in]     *data    The array to store incomming data.
     * @param[in]     size    The size of the array.
     */
    int receive(char *data, size_t max_size);

    /**
     * @brief Close the connection
     */
    void terminate();

    ~Socket();
};

} // namespace LiveVideoFeed

#endif // SOCKET_HH