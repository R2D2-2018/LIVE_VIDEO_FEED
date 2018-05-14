#include "base64.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    const static uint8_t str[] = "Man is distinguished, not only by his reason, but by this singular passion from other animals, "
                                 "which is a lust of the mind, that by a perseverance of delight in the continued and "
                                 "indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.";

    static const uint8_t str_encoded[] =
        "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbm"
        "ltYW"
        "xzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBp"
        "bmRl"
        "ZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";

    Base64 crypt;
    uint8_t strBuffer[1000];

    auto oldTime = hwlib::now_us();
    crypt.encode(str, strBuffer, sizeof(str));
    auto newTime = hwlib::now_us();

    hwlib::cout << "Time of execution: " << +(newTime - oldTime) << " us.\n\n";

    for (uint16_t i = 0; strBuffer[i] != '\0'; ++i) {
        if (strBuffer[i] != str_encoded[i]) {
            hwlib::cout << "\n\n"
                        << "Fout in encoding.\n\n";
            break;
        }
        hwlib::cout << strBuffer[i];
    }

    return 0;
}
