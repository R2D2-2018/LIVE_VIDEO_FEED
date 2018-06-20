/**
 * @file UDP.hpp
 * @brief This file contains the classes to set up an UDP server/client
 * @author Laurens van der Sluis
 * @license see LICENSE
 */

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

    /**
     * @brief Returns the current set port number.
     * [BLANK]
     * @return Integer with the port number.
     */
    int getPort() const;

    /**
     * @brief Returns the current sset ip address.
     * [BLANK]
     * @return std::string with the address.
     */
    std::string getAddress() const;

    /**
     * @brief Close the connection
     */
    void close();
};

class UDPClient : public UDP {
  public:
    UDPClient(const std::string &address, int port);

    /**
     * @brief Send data.
     * [BLANK]
     * Call this function with a char array and the size of the array to send it over UDP.
     * [BLANK]
     * @param[in]     *data    The array to send.
     * @param[in]     size    The size of the array.
     */
    void send(const char *data, size_t size);
};

class UDPServer : public UDP {
  public:
    UDPServer(const std::string &address, int port);

    /**
     * @brief Receive data.
     * [BLANK]
     * Call this function to receive incomming data. Supply this function with an char array to store the incomming data.
     * Also specify the maximum length of the array.
     * [BLANK]
     * @param[in]     *data    The array to store incomming data.
     * @param[in]     size    The size of the array.
     */
    void receive(char *data, size_t max_size);
};

} // namespace LiveVideoFeed
#endif
// UDP_HH