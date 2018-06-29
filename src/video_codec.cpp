#include "video_codec.hpp"
#include <iostream>
LiveVideoFeed::videoCodec::videoCodec(const std::string &code) {
    if (code.length() == 4) {
        codeID = std::copy(code);
        fourcc = (static_cast<uint32_t>(((code[3]) << 24) | ((code[2]) << 16) | ((code[1]) << 8) | (code[0])));
    }
}

std::string LiveVideoFeed::videoCodec::getCode() {
    return codeID;
}