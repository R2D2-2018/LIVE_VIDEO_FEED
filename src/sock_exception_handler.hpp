/**
 * @file    sock_exception_handler.hpp
 * @brief   SockExceptionHandler class declaration.
 * @author  Nick Swaerdens
 * @license See LICENSE
 */

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
     * This
     *
     * @param[in]
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