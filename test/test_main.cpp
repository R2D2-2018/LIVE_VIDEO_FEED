#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "UDP.hpp"
#include "catch.hpp"

LiveVideoFeed::UDPServer LVFserver(26296);
LiveVideoFeed::UDPClient LVFclient("127.0.0.1", 26296);

TEST_CASE("Server port check", "[Get port number]") {
    REQUIRE(26296 == LVFserver.getPort());
}

TEST_CASE("Client IPAddress check", "[Get server IPAddress]") {
    REQUIRE("127.0.0.1" == LVFclient.getAddress());
}

TEST_CASE("Client port check", "[Get port number]") {
    REQUIRE(26296 == LVFclient.getPort());
}

TEST_CASE("UDP communication check", "[Send and receive a message]") {
    LVFclient.send("This is a test message.");
    char data[24];
    LVFserver.receive(data, 24);
    std::string message(data);
    REQUIRE("This is a test message." == message);
}