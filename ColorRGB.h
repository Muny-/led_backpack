#include <Arduino.h>

class ColorRGB
{

  public:
    ColorRGB(uint8_t r, uint8_t g, uint8_t b);

    uint8_t
        red,
        green,
        blue;

    void
    updateValues(uint8_t r, uint8_t g, uint8_t b);

    uint32_t
    combine();
};