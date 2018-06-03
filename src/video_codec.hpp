/**
 * @file    videoCodec.hpp
 * @brief   videoCodec class declaration.
 * @author  Nick Swaerdens
 * @license See LICENSE
 */

#ifndef VIDEO_CODEC
#define VIDEO_CODEC

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace LiveVideoFeed {
class videoCodec {
  private:
    uint32_t fourcc;
    std::string codeID;

  public:
    /**
     * @brief Create the video codec object.
     *
     * @details
     * This object creates the video codec class. On creation, the fourcc code for the codec must be set. This will then be used by
     * the encode and decode functions.
     *
     * @param[in] The fourcc code in string format for the codec.
     */
    videoCodec(const std::string &code);

    void encode(){};
    void decode(){};

    /**
     * @brief Returns the fourcc code in string format.
     */
    std::string getCode();
};

} // namespace LiveVideoFeed

#endif // VIDEO_CODEC