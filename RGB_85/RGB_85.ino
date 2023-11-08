

#include "RGB_85.h"
#include "Pins.h"

RGB RGB(RED, GREEN, BLUE, RGB::COMMON_CATHODE);

void setup() {
}

void test(){
  RGB.off();
  delay(100);
  RGB.setColor(0,0,0);
  delay(500);
  RGB.off();

}
void loop() {
test();
}
