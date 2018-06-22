#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "UDP.hpp"
#include "catch.hpp"

TEST_CASE("IPaddress check", "[Get IP address]") {
    LiveVideoFeed::UDPServer LVFserver("192.168.68.120", 26296);
    REQUIRE("192.168.68.120" == LVFserver.getAddress());
    LVFserver.close();
}

TEST_CASE("Port check", "[Get port number]") {
    LiveVideoFeed::UDPServer LVFserver("192.168.68.120", 26296);
    REQUIRE(26296 == LVFserver.getPort());
}