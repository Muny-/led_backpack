#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include "ColorRGB.h"

/*
// MATRIX DECLARATION:
// Parameter 1 = width of EACH NEOPIXEL MATRIX (not total display)
// Parameter 2 = height of each matrix
// Parameter 3 = number of matrices arranged horizontally
// Parameter 4 = number of matrices arranged vertically
// Parameter 5 = pin number (most are valid)
// Parameter 6 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the FIRST MATRIX; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs WITHIN EACH MATRIX are
//     arranged in horizontal rows or in vertical columns, respectively;
//     pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns WITHIN
//     EACH MATRIX proceed in the same order, or alternate lines reverse
//     direction; pick one.
//   NEO_TILE_TOP, NEO_TILE_BOTTOM, NEO_TILE_LEFT, NEO_TILE_RIGHT:
//     Position of the FIRST MATRIX (tile) in the OVERALL DISPLAY; pick
//     two, e.g. NEO_TILE_TOP + NEO_TILE_LEFT for the top-left corner.
//   NEO_TILE_ROWS, NEO_TILE_COLUMNS: the matrices in the OVERALL DISPLAY
//     are arranged in horizontal rows or in vertical columns, respectively;
//     pick one or the other.
//   NEO_TILE_PROGRESSIVE, NEO_TILE_ZIGZAG: the ROWS/COLUMS OF MATRICES
//     (tiles) in the OVERALL DISPLAY proceed in the same order for every
//     line, or alternate lines reverse direction; pick one.  When using
//     zig-zag order, the orientation of the matrices in alternate rows
//     will be rotated 180 degrees (this is normal -- simplifies wiring).
//   See example below for these values in action.
// Parameter 7 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 pixels)
//   NEO_GRB     Pixels are wired for GRB bitstream (v2 pixels)
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA v1 pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)

// Example with three 10x8 matrices (created using NeoPixel flex strip --
// these grids are not a ready-made product).  In this application we'd
// like to arrange the three matrices side-by-side in a wide display.
// The first matrix (tile) will be at the left, and the first pixel within
// that matrix is at the top left.  The matrices use zig-zag line ordering.
// There's only one row here, so it doesn't matter if we declare it in row
// or column order.  The matrices use 800 KHz (v2) pixels that expect GRB
// color data.

#define MATRIX_PIN 6
#define MATRIX_WIDTH 16
#define MATRIX_HEIGHT 16
#define TILE_X 2
#define TILE_Y 1

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
        MATRIX_HEIGHT, MATRIX_WIDTH, TILE_X, TILE_Y, MATRIX_PIN,
        NEO_MATRIX_BOTTOM + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG + NEO_TILE_TOP + NEO_TILE_LEFT + NEO_TILE_ROWS,
        NEO_GRB + NEO_KHZ800);

#define CIRCLES_PIN 7

const uint16_t NUM_CIRCLES_LEDS = 95;
const uint16_t CIRCLES_MAX_INDEX = NUM_CIRCLES_LEDS - 1;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data inpput
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.*.*/

#define NUM_LEDS_FRONT_STRIPS 68
#define NUM_LEDS_EDGE_STRIP 99
#define NUM_LEDS_STRAP_LEFT 60
#define NUM_LEDS_STRAP_RIGHT 61
#define NUM_LEDS_CIRCLES 95


#define PIN_FRONT_STRIPS 30
#define PIN_EDGE_STRIP 35
#define PIN_MATRIX 6
#define PIN_STRAP_LEFT 29
#define PIN_STRAP_RIGHT 5
#define PIN_CIRCLES 4

Adafruit_NeoPixel strips_front = Adafruit_NeoPixel(NUM_LEDS_FRONT_STRIPS, PIN_FRONT_STRIPS, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_edge = Adafruit_NeoPixel(NUM_LEDS_EDGE_STRIP, PIN_EDGE_STRIP, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_strap_left = Adafruit_NeoPixel(NUM_LEDS_STRAP_LEFT, PIN_STRAP_LEFT, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_strap_right = Adafruit_NeoPixel(NUM_LEDS_STRAP_RIGHT, PIN_STRAP_RIGHT, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_circles = Adafruit_NeoPixel(NUM_LEDS_CIRCLES, PIN_CIRCLES, NEO_GRB + NEO_KHZ800);

#define MATRIX_WIDTH 16
#define MATRIX_HEIGHT 16
#define TILE_X 2
#define TILE_Y 1

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
    MATRIX_HEIGHT, MATRIX_WIDTH, TILE_X, TILE_Y, PIN_MATRIX,
    NEO_MATRIX_BOTTOM + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG + NEO_TILE_TOP + NEO_TILE_LEFT + NEO_TILE_ROWS,
    NEO_GRB + NEO_KHZ800);

#define NUM_STRIPS 6

Adafruit_NeoPixel* strips[NUM_STRIPS] = {&strips_front, &strip_edge, &strip_strap_left, &strip_strap_right, &strip_circles, &matrix};



// 190 seems most stable brightest
// 10 is reasonable indoors
#define MASTER_BRIGHTNESS 10

void setup()
{
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);

    analogReadResolution(13);

    strips_front.begin();
    strips_front.show();
    strips_front.setBrightness(MASTER_BRIGHTNESS);

    strip_edge.begin();
    strip_edge.show();
    strip_edge.setBrightness(MASTER_BRIGHTNESS);

    strip_strap_left.begin();
    strip_strap_left.show();
    strip_strap_left.setBrightness(MASTER_BRIGHTNESS);

    strip_strap_right.begin();
    strip_strap_right.show();
    strip_strap_right.setBrightness(MASTER_BRIGHTNESS);

    strip_circles.begin();
    strip_circles.show();
    strip_circles.setBrightness(MASTER_BRIGHTNESS);

    matrix.begin();
    matrix.setTextWrap(false);
    matrix.setBrightness(MASTER_BRIGHTNESS);
    matrix.show();

    Serial.begin(4000000);

    //fillStrips(new ColorRGB(255, 255, 255));
}

unsigned long lastCurrSerial = 0;

union ArrayToInteger {
    byte array[4];
    uint32_t integer;
};

bool haveEverGottenPixels = false;

uint16_t rainbow_i = 0;


// Placeholder modes:
// 0 == Rainbow
// 1 == Turn Right (flashing)
// 2 == Turn Left (flashing)
uint8_t PLACEHOLDER_DISPLAY_MODE = 0;

unsigned long lastPlaceholderDisplayChange = 0;

bool hasSetWhite = false;

void loop()
{

    /*uint16_t adcVal_curr1 = curr1_runningAverage(analogRead(A5));
    uint16_t adcVal_curr2 = curr2_runningAverage(analogRead(A6));

    unsigned long now = millis();

    if (now - lastCurrSerial > 500)
    {
        // 120W  |  7.4A @ 12V  |  19.5A @ 5V
        Serial.print("Buck1: ");
        printPowerInfo(VtoCurr(adcValToV(adcVal_curr1)));

        Serial.print("Buck2: ");
        printPowerInfo(VtoCurr(adcValToV(adcVal_curr2)));

        Serial.println("");

        lastCurrSerial = now;
    }*/

    if (Serial.available())
    {
        byte magic_buff[10];

        if (Serial.readBytes((char*)magic_buff, 10) != 0)
        {
            bool isMagic = true;

            for (uint8_t i = 0; i < 10; i++)
            {
                if (magic_buff[i] != i)
                {
                    isMagic = false;
                    break;
                }
            }

            if (isMagic)
            {
                //Serial.println("got magic series");

                fillBrightnessFromSerial();

                fillStripFromSerial(&strips_front);      // 204 bytes
                fillStripFromSerial(&strip_edge);        // 297 bytes
                fillStripFromSerial(&strip_strap_left);  // 180 bytes
                fillStripFromSerial(&strip_strap_right); // 183 bytes
                fillStripFromSerial(&strip_circles);     // 285 bytes

                fillStripFromSerial(&matrix);            // 1536 bytes

                haveEverGottenPixels = true;
            }
        }
    }

    // if we've never gotten anything, show a rainbow as a placeholder effect
    if (!haveEverGottenPixels)
    {
        unsigned long now = millis();

        if (now - lastPlaceholderDisplayChange > 5000)
        {
            PLACEHOLDER_DISPLAY_MODE++;
            if (PLACEHOLDER_DISPLAY_MODE > 3)
                PLACEHOLDER_DISPLAY_MODE = 0;

            hasSetWhite = false;

            lastPlaceholderDisplayChange = now;
        }

        /*placeholder_Rainbow(now);

        placeholder_WelcomeText(now);*/

        switch (PLACEHOLDER_DISPLAY_MODE)
        {
        case 0:
            placeholder_Rainbow(now);
            placeholder_WelcomeText(now);
            break;
        case 1:
            placeholder_TurnRight(now);
            break;
        case 2:
            placeholder_TurnLeft(now);
            break;
        case 3:
            placeholder_White(now);
            break;
        }
    }
}

void placeholder_Rainbow(unsigned long now)
{
    if (rainbow_i == 256)
        rainbow_i = 0;

    rainbowStrip(&strips_front);
    rainbowStrip(&strip_edge);
    rainbowStrip(&strip_strap_left);
    rainbowStrip(&strip_strap_right);
    rainbowStrip(&strip_circles);

    //rainbowStrip(&matrix);

    rainbow_i++;
}

int16_t welcomeTextScroll = -8;

bool welcomeTextDirection = true;

void placeholder_WelcomeText(unsigned long now)
{
    matrix.fillScreen(0);
    matrix.setTextColor(MatrixWheel(now % 256));
    matrix.setCursor(welcomeTextScroll, 4);
    matrix.print("Welcome!");
    matrix.show();

    if (welcomeTextDirection)
        welcomeTextScroll++;
    else
        welcomeTextScroll--;

    if (welcomeTextScroll > 8 || welcomeTextScroll < -18)
        welcomeTextDirection = !welcomeTextDirection;
}

uint16_t arrowColor = matrix.Color(255, 157, 0);

unsigned long lastArrowStateToggle = 0;
bool arrowState = false;

void placeholder_TurnRight(unsigned long now)
{
    if (now - lastArrowStateToggle > 100)
    {
        arrowState = !arrowState;
        lastArrowStateToggle = now;

        if (arrowState)
        {
            matrix.drawFastHLine(17, 8, 16, arrowColor);
            matrix.drawLine(24, 0, 32, 8, arrowColor);
            matrix.drawLine(24, 16, 32, 8, arrowColor);
        }
        else
        {
            matrix.fillScreen(0);

            clearStrip(&strips_front);
            clearStrip(&strip_edge);
            clearStrip(&strip_strap_left);
            clearStrip(&strip_strap_right);
            clearStrip(&strip_circles);
        }

        matrix.show();
    }
}

void placeholder_TurnLeft(unsigned long now)
{
    if (now - lastArrowStateToggle > 100)
    {
        arrowState = !arrowState;
        lastArrowStateToggle = now;

        if (arrowState)
        {
            matrix.drawFastHLine(0, 8, 16, arrowColor);
            matrix.drawLine(0, 8, 8, 0, arrowColor);
            matrix.drawLine(0, 8, 8, 16, arrowColor);
        }
        else
        {
            matrix.fillScreen(0);

            clearStrip(&strips_front);
            clearStrip(&strip_edge);
            clearStrip(&strip_strap_left);
            clearStrip(&strip_strap_right);
            clearStrip(&strip_circles);
        }

        matrix.show();
    }
}

void placeholder_White(unsigned long now)
{
    if (!hasSetWhite)
    {
        hasSetWhite = true;
        fillStrips(new ColorRGB(255, 255, 255));
    }
}

void rainbowStrip(Adafruit_NeoPixel *strip)
{
    for (uint16_t i = 0; i < strip->numPixels(); i++)
    {
        strip->setPixelColor(i, Wheel((i + rainbow_i) % 256));
    }

    strip->show();
}

void fillStripFromSerial(Adafruit_NeoPixel *strip)
{
    byte buff[3 * strip->numPixels()] = {0};

    if (Serial.readBytes((char *)buff, 3 * strip->numPixels()) != 0)
    {
        for (uint16_t i = 0; i < strip->numPixels(); i++)
        {
            strip->setPixelColor(i, strip->Color(buff[(3 * i)], buff[(3 * i) + 1], buff[(3 * i) + 2]));
        }

        strip->show();
    }
}

void fillBrightnessFromSerial()
{
    byte buff[NUM_STRIPS] = {0};

    if (Serial.readBytes((char *)buff, NUM_STRIPS) == NUM_STRIPS)
    {
        for (size_t i = 0; i < NUM_STRIPS; i++)
        {
            strips[i]->setBrightness(buff[i]);
        }
    }
}

void clearStrip(Adafruit_NeoPixel *strip)
{
    strip->clear();
    strip->show();
}

/*void fillMatrixFromSerial(Adafruit_NeoMatrix *neoMat)
{
    byte buff[3 * 512] = {0};

    if (Serial.readBytes((char *)buff, 3 * 512) != 0)
    {
        for (uint16_t i = 0; i < 512; i++)
        {
            neoMat->drawPixel(i, neoMat->Color(buff[(3 * i)], buff[(3 * i) + 1], buff[(3 * i) + 2]));
        }

        neoMat->show();
    }
}*/

void printPowerInfo(double amps_12v)
{
    Serial.print(12.0*amps_12v);
    Serial.print("W  |  ");
    Serial.print(amps_12v);
    Serial.print("A @ 12V  |  ");
    Serial.print(2.4*amps_12v);
    Serial.println("A @ 5V");
}

double VtoCurr(double v)
{
    return (v - 2.7) / 0.1;
}

double adcValToV(uint16_t adcVal)
{
    return (adcVal / 8192.0) * 5.445;
}

long curr1_runningAverage(int M)
{
#define LM_SIZE 10
    static int LM[LM_SIZE]; // LastMeasurements
    static byte index = 0;
    static long sum = 0;
    static byte count = 0;

    // keep sum updated to improve speed.
    sum -= LM[index];
    LM[index] = M;
    sum += LM[index];
    index++;
    index = index % LM_SIZE;
    if (count < LM_SIZE)
        count++;

    return sum / count;
}

long curr2_runningAverage(int M)
{
#define LM_SIZE 10
    static int LM[LM_SIZE]; // LastMeasurements
    static byte index = 0;
    static long sum = 0;
    static byte count = 0;

    // keep sum updated to improve speed.
    sum -= LM[index];
    LM[index] = M;
    sum += LM[index];
    index++;
    index = index % LM_SIZE;
    if (count < LM_SIZE)
        count++;

    return sum / count;
}

int16_t Color333(uint8_t r, uint8_t g, uint8_t b)
{
    // RRRrrGGGgggBBBbb
    return ((r & 0x7) << 13) | ((r & 0x6) << 10) |
           ((g & 0x7) << 8) | ((g & 0x7) << 5) |
           ((b & 0x7) << 2) | ((b & 0x6) >> 1);
}

void fillStrips(ColorRGB *color)
{
    for (size_t i = 0; i < NUM_STRIPS; i++)
    {
        for (uint16_t x = 0; x < strips[i]->numPixels(); x++)
        {
            strips[i]->setPixelColor(x, color->combine());
        }

        strips[i]->show();
    }
}

void fillStrip(Adafruit_NeoPixel *strip, uint32_t color)
{
    for (uint16_t i = 0; i < strip->numPixels(); i++)
    {
        strip->setPixelColor(i, color);
    }

    strip->show();
}

/*FadedPixel color1_arr[NUM_CIRCLES_LEDS];
FadedPixel color2_arr[NUM_CIRCLES_LEDS];
FadedPixel color3_arr[NUM_CIRCLES_LEDS];
FadedPixel color4_arr[NUM_CIRCLES_LEDS];

FadedPixel merged_array[NUM_CIRCLES_LEDS];

void chaser(uint32_t color1, uint32_t color2, uint8_t wait)
{

    // for(int8_t rotate = 0; rotate < 60; rotate+= 2)
    // {
    //     for(int8_t i = 0; i < 60; i++)
    //     {
    //         populateFadedArray(2*(i+rotate), 255, 0, 0, 255, 20, color1_arr);
    //         populateFadedArray(2*(60-i), 0, 255, 0, 255, 20, color2_arr);
    //         populateFadedArray(i+30, 0, 0, 255, 255, 20, color3_arr);
    //         populateFadedArray((60-i)+30, 255, 0, 255, 255, 20, color4_arr);

    //         mergeArrays(color1_arr, color2_arr, color3_arr, color4_arr);
        
    //         displayArray(merged_array);

    //         delay(wait);
    //     }
    // }

    // for(uint8_t rotate = 0; rotate < 60; rotate++) {


    //     for(uint8_t i = 0; i < 60; i++) {
            
    //         populateFadedArray((i+rotate), 255, 0, 0, 255, 30, color1_arr);
    //         populateFadedArray((60-i), 0, 0, 255, 255, 30, color2_arr);

    //         mergeArrays(color1_arr, color2_arr);

    //         displayArray(merged_array);

    //         delay(wait);
    //     }

    // }

    // for(float i = 0; i < 60; i++) {
        
    //     populateFadedArray(i, 255, 0, 0, 255, 10, color1_arr);
    //     populateFadedArray((60-i), 0, 0, 255, 255, 10, color2_arr);

    //     populateFadedArray(i+30, 0, 255, 0, 255, 5, color3_arr);
    //     populateFadedArray((60-(i+30)), 0, 255, 0, 255, 5, color4_arr);

    //     mergeArrays(color1_arr, color2_arr, color3_arr, color4_arr);

    //     displayArray(merged_array);

    //     delay(wait);
    // }

    // populateFadedArray(0, 255, 0, 0, 255, 29, color1_arr);

    // populateFadedArray(30, 0, 0, 255, 255, 29, color2_arr);

    // displayArray(mergeArrays(color1_arr, color2_arr));

    //police();

    //fillStrip(blue);

    //delay(1000);
    
}

int16_t scaleIndex(int16_t unscaled)
{
    if (unscaled > CIRCLES_MAX_INDEX)
    {
        return scaleIndex((unscaled - CIRCLES_MAX_INDEX) - 1);
    }
    else if (unscaled < 0)
    {
        return scaleIndex((CIRCLES_MAX_INDEX + unscaled) + 1);
    }
    else
        return unscaled;
}

void displayArray(FadedPixel *arr)
{

    for (uint8_t i = 0; i < NUM_CIRCLES_LEDS; i++)
    {
        circles_strip.setPixelColor(i, arr[i].redS(), arr[i].greenS(), arr[i].blueS());
    }

    circles_strip.show();
}

void mergeArrays(FadedPixel *arr1, FadedPixel *arr2)
{
    // let's hope both arrays are the same size...

    for (uint8_t i = 0; i < NUM_CIRCLES_LEDS; i++)
    {
        uint8_t merged_red = (arr1[i].redS() + arr2[i].redS()) / 2;
        uint8_t merged_green = (arr1[i].greenS() + arr2[i].greenS()) / 2;
        uint8_t merged_blue = (arr1[i].blueS() + arr2[i].blueS()) / 2;
        uint8_t merged_alpha = (arr1[i].alpha + arr2[i].alpha) / 2;

        merged_array[i].updateValues(merged_red, merged_green, merged_blue, merged_alpha);
    }
}

void mergeArrays(FadedPixel *arr1, FadedPixel *arr2, FadedPixel *arr3)
{
    // let's hope arrays are the same size...

    for (uint8_t i = 0; i < NUM_CIRCLES_LEDS; i++)
    {
        uint8_t merged_red = (arr1[i].redS() + arr2[i].redS() + arr3[i].redS()) / 3;
        uint8_t merged_green = (arr1[i].greenS() + arr2[i].greenS() + arr3[i].greenS()) / 3;
        uint8_t merged_blue = (arr1[i].blueS() + arr2[i].blueS() + arr3[i].blueS()) / 3;
        uint8_t merged_alpha = (arr1[i].alpha + arr2[i].alpha + arr3[i].alpha) / 3;

        merged_array[i].updateValues(merged_red, merged_green, merged_blue, merged_alpha);
    }
}

void mergeArrays(FadedPixel *arr1, FadedPixel *arr2, FadedPixel *arr3, FadedPixel *arr4)
{
    // let's hope arrays are the same size...

    for (uint8_t i = 0; i < NUM_CIRCLES_LEDS; i++)
    {
        uint8_t merged_red = (arr1[i].redS() + arr2[i].redS() + arr3[i].redS() + arr4[i].redS()) / 4;
        uint8_t merged_green = (arr1[i].greenS() + arr2[i].greenS() + arr3[i].greenS() + arr4[i].greenS()) / 4;
        uint8_t merged_blue = (arr1[i].blueS() + arr2[i].blueS() + arr3[i].blueS() + arr4[i].blueS()) / 4;
        uint8_t merged_alpha = (arr1[i].alpha + arr2[i].alpha + arr3[i].alpha + arr4[i].alpha) / 4;

        merged_array[i].updateValues(merged_red, merged_green, merged_blue, merged_alpha);
    }
}

void populateFadedArray(int16_t index, uint8_t r, uint8_t g, uint8_t b, uint8_t a, uint8_t fadeLength, FadedPixel *arr)
{

    index = scaleIndex(index);

    for (uint16_t i = 0; i < NUM_CIRCLES_LEDS; i++)
    {
        arr[i].updateValues(0, 0, 0, 0);
    }

    //uint8_t fade_magnitude = a/fadeLength;

    for (uint8_t delta = 0; delta <= fadeLength; delta++)
    {

        uint8_t n_alpha = a * pow(M_E, -2 * M_E * (float)delta / (fadeLength * 2.4));
        //uint8_t n_alpha = delta;

        // len   = 7
        // len-1 = 6
        // [0, 1, 2, 3, 4, 5, 6]

        // leading pixels

        uint16_t leading_index = scaleIndex(index + delta);

        arr[leading_index].updateValues(r, g, b, n_alpha);

        // trailing pixels

        int16_t trailing_index = scaleIndex(index - delta);

        arr[trailing_index].updateValues(r, g, b, n_alpha);
    }
}*/

/*uint8_t parr_len(FadedPixel *arr) {
    //return sizeof(arr)/sizeof(arr[0]);
    return 60;
}*/

/*void changingStrobe(uint32_t on_color, uint32_t off_color)
{

    strobe(on_color, off_color, 1000, 15, 100);

    // for(uint16_t on_time = 250; on_time > 1; on_time--) {
    //     uint16_t off_time = 250-on_time;

    //     uint16_t num_flashes = off_time;

    //     strobe(on_color, off_color, num_flashes, on_time, off_time); 
    // }
}*/

void police(Adafruit_NeoPixel *strip)
{
    strobe(strip, RGB(255, 0, 0), 0, 3, 50, 100);

    strobe(strip, RGB(255, 255, 255), 0, 2, 10, 35);

    strobe(strip, RGB(0, 0, 255), 0, 3, 50, 100);
}

void police()
{
    strobe(new ColorRGB(255, 0, 0), 0, 3, 50, 100);

    strobe(new ColorRGB(255, 255, 255), 0, 2, 10, 35);

    strobe(new ColorRGB(0, 0, 255), 0, 3, 50, 100);
}

void strobe(ColorRGB *on_color, ColorRGB *off_color, uint16_t num_flashes, uint16_t on_time, uint16_t off_time)
{
    for (uint16_t i = 0; i < num_flashes; i++)
    {
        fillStrips(on_color);
        delay(on_time);
        fillStrips(off_color);
        delay(off_time);
    }
}

void strobe(Adafruit_NeoPixel *strip, uint32_t on_color, uint32_t off_color, uint16_t num_flashes, uint16_t on_time, uint16_t off_time)
{
    for (uint16_t i = 0; i < num_flashes; i++)
    {
        fillStrip(strip, on_color);
        delay(on_time);
        fillStrip(strip, off_color);
        delay(off_time);
    }
}



// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait)
{
    for (uint16_t i = 0; i < strip_circles.numPixels(); i++)
    {
        strip_circles.setPixelColor(i, c);
        strip_circles.show();
        delay(wait);
    }
}

void rainbow(uint8_t wait)
{
    uint16_t i, j;

    for (j = 0; j < 256; j++)
    {
        for (i = 0; i < strip_circles.numPixels(); i++)
        {
            strip_circles.setPixelColor(i, Wheel((i + j) & 255));
        }
        strip_circles.show();
        delay(wait);
    }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait)
{
    uint16_t i, j;

    for (j = 0; j < 256 * 5; j++)
    { // 5 cycles of all colors on wheel
        for (i = 0; i < strip_circles.numPixels(); i++)
        {
            strip_circles.setPixelColor(i, Wheel(((i * 256 / strip_circles.numPixels()) + j) & 255));
        }
        strip_circles.show();
        delay(wait);
    }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait)
{
    for (int j = 0; j < 10; j++)
    { //do 10 cycles of chasing
        for (int q = 0; q < 3; q++)
        {
            for (uint16_t i = 0; i < strip_circles.numPixels(); i = i + 3)
            {
                strip_circles.setPixelColor(i + q, c); //turn every third pixel on
            }
            strip_circles.show();

            delay(wait);

            for (uint16_t i = 0; i < strip_circles.numPixels(); i = i + 3)
            {
                strip_circles.setPixelColor(i + q, 0); //turn every third pixel off
            }
        }
    }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait)
{
    for (int j = 0; j < 256; j++)
    { // cycle all 256 colors in the wheel
        for (int q = 0; q < 3; q++)
        {
            for (uint16_t i = 0; i < strip_circles.numPixels(); i = i + 3)
            {
                strip_circles.setPixelColor(i + q, Wheel((i + j) % 255)); //turn every third pixel on
            }
            strip_circles.show();

            delay(wait);

            for (uint16_t i = 0; i < strip_circles.numPixels(); i = i + 3)
            {
                strip_circles.setPixelColor(i + q, 0); //turn every third pixel off
            }
        }
    }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85)
    {
        return strip_circles.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if (WheelPos < 170)
    {
        WheelPos -= 85;
        return strip_circles.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return strip_circles.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint16_t MatrixWheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85)
    {
        return matrix.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if (WheelPos < 170)
    {
        WheelPos -= 85;
        return matrix.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return matrix.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

uint32_t RGB(uint8_t r, uint8_t g, uint8_t b)
{
    return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}