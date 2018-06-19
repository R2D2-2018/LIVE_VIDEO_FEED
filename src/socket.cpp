#include "socket.hpp"

// Socket includes for different OS.
#if defined(__linux) || defined(__linux__) || defined(linux)
#define __LINUX__

namespace LiveVideoFeed {

Socket::Socket() {
}

int Socket::Send(const char *msg, size_t size) {
}

int Socket::Receive(char *msg, size_t max_size) {
}

void Socket::close() {
}
} // namespace LiveVideoFeed

#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64)
namespace LiveVideoFeed {

Socket::Socket() {
}

int Socket::Send(const char *msg, size_t size) {
}

int Socket::Receive(char *msg, size_t max_size) {
}

void Socket::close() {
}
} // namespace LiveVideoFeed
#endif