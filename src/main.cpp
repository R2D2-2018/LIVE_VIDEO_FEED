#include "src/sock_exception_handler.hpp"
#include <iostream>

int main() {
    std::cout << "Hello world!" << std::endl;

    throw LiveVideoFeed::SockExceptionHandler("NEE");

    return 0;
}
