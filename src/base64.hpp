/**
 * @file
 * @brief       This file contains a class is a codec for base64.
 * @author      Nick Swaerdens
 * @license     MIT License
 */

#ifndef BASE64_HPP
#define BASE64_HPP

#include "wrap-hwlib.hpp"

/**
 * @brief Class implementation of a base64 codec.
 *
 * This class encodes and decodes a given input.
 * Padding is supported and activated by default.
 *
 */
class Base64 {
  private:
    bool padding;

    /**
     * @brief Encodes 3 bytes.
     *
     * Encodes 3 bytes into 4 '6-bit' bytes.
     * The pointers are incremented in the function.
     * c is incremented 2 times and strBuff 3 times.
     *
     * @param
     * c           The memory location the encoding will start from.
     * strBuff     The memory destination of the encoded data.
     */
    void encodeBitString(const uint8_t *c, uint8_t *strBuff);

  public:
    /**
     * @brief Default constructor
     */
    Base64(const bool &padding = 1);

    /**
     * @brief Encodes a string.
     *
     * This functions encodes an input.
     * The remaining characters are encoded seperatly in this function.
     *
     * @param
     * str          The input to be encoded.
     * strBuffer    A destination for the encoded data.
     * strLength    The length of the input.
     */
    void encode(const uint8_t *str, uint8_t *strBuffer, uint16_t strLength);

    /**
     * @brief Sets the padding to True or False.
     * @param   b   true or false
     */
    void setPadding(const bool &b);

    /**
     * @brief Toggle the padding.
     */
    void togglePadding();

    /**
     * @brief Returns whether padding is on or not.
     */
    bool &getPadding();
};

#endif // BASE64_HPP