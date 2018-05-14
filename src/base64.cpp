#include "base64.hpp"

const static uint8_t Base64LUT[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void Base64::encodeBitString(const uint8_t *c, uint8_t *strBuff) {
    strBuff[0] = Base64LUT[(*c >> 2 & 0x3F)];
    strBuff[1] = Base64LUT[(*c << 4 & 0x30) + (*(++c) >> 4 & 0x0F)];
    strBuff[2] = Base64LUT[(*c << 2 & 0x3C) + (*(++c) >> 6 & 0x03)];
    strBuff[3] = Base64LUT[(*c & 0x3F)];
}

Base64::Base64(const bool &padding) : padding(padding) {
}

void Base64::encode(const uint8_t *str, uint8_t *strBuffer, uint16_t strLength) {
    --strLength;
    uint16_t remChars = strLength % 3;
    uint16_t numLoops = (strLength - remChars) / 3;

    while (numLoops > 0) {
        encodeBitString(str, strBuffer);
        str += 3;
        strBuffer += 4;
        --numLoops;
    }

    ///< Encode remaining character(s).
    if (remChars == 1) {
        *strBuffer = Base64LUT[(*str >> 2 & 0x3F)];
        *(++strBuffer) = Base64LUT[(*str << 4 & 0x30)];
        if (padding) {
            *(++strBuffer) = '=';
            *(++strBuffer) = '=';
        }
        ++strBuffer;
    } else if (remChars == 2) {
        *strBuffer = Base64LUT[(*str >> 2 & 0x3F)];
        *(++strBuffer) = Base64LUT[(*str << 4 & 0x30) + (*(++str) >> 4 & 0x0F)];
        *(++strBuffer) = Base64LUT[(*str << 2 & 0x3C)];
        if (padding) {
            *(++strBuffer) = '=';
        }
        ++strBuffer;
    }

    *(strBuffer) = '\0';
}

void Base64::setPadding(const bool &b) {
    padding = b;
}

void Base64::togglePadding() {
    padding = !padding;
}

bool &Base64::getPadding() {
    return padding;
}