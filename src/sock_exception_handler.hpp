/**
 * @file    sock_exception_handler.hpp
 * @brief   SockExceptionHandler class declaration.
 * @author  Nick Swaerdens
 * @license See LICENSE
 */

#ifndef SOCK_EXCEPTION_HANDLER
#define SOCK_EXCEPTION_HANDLER
#include <stdexcept>

namespace LiveVideoFeed {
class SockExceptionHandler : public std::exception {
  private:
    std::string errorMsg;

  public:
    /**
     * @brief Create the socket exception handler object.
     *
     * @details
     * This object throws an exception with a custom string.
     *
     * @param[in] errorStr String that while be displayed.
     */
    SockExceptionHandler(const std::string &errorStr) throw();

    /**
     * @brief Returns the error message.
     *
     * @details
     * This method returns the error message that has been set by the constructor.
     *
     * @return Ptr to the error message string.
     */
    const char *what() const throw();
};
} // namespace LiveVideoFeed

#endif // SOCK_EXCEPTION_HANDLER