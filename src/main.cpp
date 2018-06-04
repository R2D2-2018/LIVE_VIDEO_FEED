#include "sock_exception_handler.hpp"
#include "video_codec.hpp"
#include <iostream>

int main() {
    std::cout << "Hello world!" << std::endl;

    LiveVideoFeed::videoCodec a("H264");
    std::cout << "code: " << a.getCode() << std::endl;

    throw LiveVideoFeed::SockExceptionHandler("TEST ERROR");

    return 0;
}
