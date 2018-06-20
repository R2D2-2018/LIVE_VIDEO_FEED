/**
 * @file    socket.hpp
 * @brief   Socket class declaration. This class aims for cross-platform functionality.
 * @author  Laurens van der Sluis
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
    Socket();

    /**
     * @brief Send data.
     * [BLANK]
     * Call this function with a char array and the size of the array to send it over UDP.
     * The implementation of this function depends on the platform it was compiled on.
     * [BLANK]
     * @param[in]     *data    The array to send.
     * @param[in]     size    The size of the array.
     */
    void send(const char *data, size_t size);

    /**
     * @brief Receive data.
     * [BLANK]
     * Call this function to receive incomming data. Supply this function with an char array to store the incomming data.
     * Also specify the maximum length of the array.
     * The implementation of this function depends on the platform it was compiled on.
     * [BLANK]
     * @param[in]     *data    The array to store incomming data.
     * @param[in]     size    The size of the array.
     */
    void receive(char *data, size_t max_size);

    /**
     * @brief Close the connection
     */
    void close();
};

} // namespace LiveVideoFeed

#endif // SOCKET