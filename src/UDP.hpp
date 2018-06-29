/**
 * @file UDP.hpp
 * @brief This file contains the classes to set up an UDP server/client
 * @author Laurens van der Sluis
 * @license see LICENSE
 */

#ifndef UDP_HH
#define UDP_HH

#include "socket.hpp"
#include <iostream>
#include <stdexcept>

namespace LiveVideoFeed {
class UDP {
  protected:
    Socket UDPsocket;
    std::string ipaddress;
    int port;

  public:
    /**
     * @brief Construcotr for the UDP client/server base class.
     *
     * @param[in]    &port    The port the UDP client/server will use.
     */
    UDP(int port);

    /**
     * @brief Construcotr for the UDP client/server base class.
     *
     * @param[in]    address  The ip adress the UDP client/server will use.
     * @param[in]    &port    The port the UDP client/server will use.
     */

    UDP(std::string address, int port);

    /**
     * @brief Returns the current set port number.
     *
     * @return Integer with the port number.
     */
    int getPort() const;

    /**
     * @brief Returns the current set ip address.
     *
     * @return std::string with the address.
     */
    const char *getAddress() const;

    /**
     * @brief Close the connection
     */
    void close();
};

class UDPClient : public UDP {
  public:
    /**
     * @brief Constructor for a UDP client
     *
     * @param[in]     &address    The ip adress the UDP Client will use.
     * @param[in]     &port       The port the UDP Client will use.
     */
    UDPClient(const std::string &address, int port);

    /**
     * @brief Send data.
     *
     * Call this function with a char array and the size of the array to send it over UDP.
     *
     * @param[in]     *data    The array to send.
     */
    void send(const char *data);
};

class UDPServer : public UDP {
  public:
    /**
     * @brief Constructor for a UDP Server
     *
     * @param[in]     port    The port the UDP Server will use.
     * @return What will the function return
     */
    UDPServer(int port);

    /**
     * @brief Receive data.
     *
     * Call this function to receive incomming data. Supply this function with an char array to store the incomming data.
     * Also specify the maximum length of the array.
     *
     * @param[in]     *data    The array to store incomming data.
     * @param[in]     size    The size of the array.
     */
    int receive(char *data, size_t max_size);
};

} // namespace LiveVideoFeed
#endif
// UDP_HH