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
  if (Red < 0) {
    Red = 0;
  }
  if (Red > 255) {
    Red = 255;
  }

  if (Green < 0) {
    Green = 0;
  }
  if (Green > 255) {
    Green = 255;
  }

  if (Blue < 0) {
    Blue = 0;
  }
  if (Blue > 255) {
    Blue = 255;
  }
  if (_common == COMMON_ANODE) {
    analogWrite(red, 255 - Red);
    analogWrite(green, 255 - Green);
    analogWrite(blue, 255 - Blue);
  } else {
    analogWrite(red, Red);
    analogWrite(green, Green);
    analogWrite(blue, Blue);
  }
}


void RGB::off() {
  color(0, 0, 0);
}
void RGB::setColor(int rgb[3]) {
  color(rgb[0], rgb[1], rgb[2]);
}
void RGB::setColor(int Red, int Green, int Blue) {
  color(Red, Green, Blue);
}

void RGB::fade(int Red, int Green, int Blue, int fadeAmount, int max, bool up) {

  if (max < 0)
    max = 0;
  if (fadeAmount < 1)
    fadeAmount = 1;

  if (up) {
    for (int i = fadeAmount; i >= 0; i--) {
      fade(Red, Green, Blue, fadeAmount, max, i * 255 / fadeAmount, i > 0);
    }
  } else {
    for (int i = 0; i <= fadeAmount; i++) {
      fade(Red, Green, Blue, fadeAmount, max, i * 255 / fadeAmount, i < fadeAmount);
    }
  }
}
