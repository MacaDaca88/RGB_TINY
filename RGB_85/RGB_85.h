//test

#ifndef RGB_85_h
#define RGB_85_h

#include "Arduino.h"
#include "Pins.h"

class RGB {

public:
  RGB::RGB(int Red, int Green, int Blue, bool common);

  void off();
  void fade(int rgb[3],int fadeAmount, int max );
  void fade(int Red, int Green, int Blue, int fadeAmount, int max);
  void setColor(int rgb[3]);
  void setColor(int Red, int Green, int Blue);

  static int _RED[3];
  static int _GREEN[3];
  static int _BLUE[3];
  static int _MAGENTA[3];
  static int _CYAN[3];
  static int _YELLOW[3];
  static int _WHITE[3];

  static bool COMMON_ANODE;
  static bool COMMON_CATHODE;

private:
  int red, green, blue, _common;


  void color(int Red, int Green, int Blue);
	void fade(int Red, int Green, int Blue, int fadeAmount, int max, bool up);

};

#endif
