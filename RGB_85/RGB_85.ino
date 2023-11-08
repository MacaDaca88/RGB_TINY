#include "Pins.h"
#include "RGB_85.h"


RGB RGB(RED, GREEN, BLUE, RGB::COMMON_ANODE);

void setup() {
}


void loop() {
  RGB.setColor(0, 0, 5);

  delay(500);

  RGB.setColor(RGB::_RED);
  delay(1000);
}
