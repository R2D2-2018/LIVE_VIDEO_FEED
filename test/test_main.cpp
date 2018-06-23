#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "UDP.hpp"
#include "catch.hpp"

TEST_CASE("Server port check", "[Get port number]") {
    LiveVideoFeed::UDPServer LVFserver(26296);
    REQUIRE(26296 == LVFserver.getPort());
}

TEST_CASE("Client IPAddress check", "[Get server IPAddress]") {
    LiveVideoFeed::UDPServer LVFclient("127.0.0.1", 26296);
    REQUIRE("127.0.0.1" == LVFserver.getAddress());
}

TEST_CASE("Client port check", "[Get port number]") {
    LiveVideoFeed::UDPServer LVFclient("127.0.0.1", 26296);
    REQUIRE(26296 == LVFserver.getPort());
}