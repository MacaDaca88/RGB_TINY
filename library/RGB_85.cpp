#include "Arduino.h"

#include "RGB_85.h"
#include "Pins.h"

int RGB::_RED[3] = { 255, 0, 0 };
int RGB::_GREEN[3] = { 0, 255, 0 };
int RGB::_BLUE[3] = { 0, 0, 255 };
int RGB::_MAGENTA[3] = { 255, 0, 255 };
int RGB::_CYAN[3] = { 0, 255, 255 };
int RGB::_YELLOW[3] = { 255, 255, 0 };
int RGB::_WHITE[3] = { 255, 255, 255 };

bool RGB::COMMON_ANODE = true;
bool RGB::COMMON_CATHODE = false;

RGB::RGB(int Red, int Green, int Blue, bool common)
  : red(Red), green(Green), blue(Blue), _common(common) {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}
void RGB::color(int Red, int Green, int Blue) {
  if (red < 0) {
    red = 0;
  }
  if (red > 255) {
    red = 255;
  }

  if (green < 0) {
    green = 0;
  }
  if (green > 255) {
    green = 255;
  }

  if (blue < 0) {
    blue = 0;
  }
  if (blue > 255) {
    blue = 255;
  }
  if (_common == COMMON_ANODE) {
    analogWrite(Red, 255 - red);
    analogWrite(Green, 255 - green);
    analogWrite(Blue, 255 - blue);
  } else {
    analogWrite(Red, red);
    analogWrite(Green, green);
    analogWrite(Blue, blue);
  }
}


void RGB::off() {
  color(0, 0, 0);
}
void RGB::setColor(int rgb[3]) {
  color(rgb[0], rgb[1], rgb[2]);
}
void RGB::setColor(int Red, int Green, int Blue) {
  red = Red;
  green = Green;
  blue = Blue;
  color(red, green, blue);
}
