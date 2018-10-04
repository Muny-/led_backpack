#include "ColorRGB.h"

ColorRGB::ColorRGB(uint8_t r, uint8_t g, uint8_t b)
{
    red = r;
    green = g;
    blue = b;
}

void ColorRGB::updateValues(uint8_t r, uint8_t g, uint8_t b)
{
    red = r;
    green = g;
    blue = b;
}

uint32_t ColorRGB::combine()
{
    return ((uint32_t)red << 16) | ((uint32_t)green << 8) | blue;
}