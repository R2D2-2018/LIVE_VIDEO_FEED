#include "sock_exception_handler.hpp"

LiveVideoFeed::SockExceptionHandler::SockExceptionHandler(const std::string &errorStr) throw() : errorMsg{errorStr} {
}

const char *LiveVideoFeed::SockExceptionHandler::what() const throw() {
    return errorMsg.c_str();
}