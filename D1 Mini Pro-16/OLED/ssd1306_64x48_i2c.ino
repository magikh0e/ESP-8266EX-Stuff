// Library supporting 64x48 - https://github.com/squix78/esp8266-oled-ssd1306
// WeMos OLED : 64 x 48  : x, y    x, y : CTR = 64,40  
// flipScreenVertically : 32,16---95,16                  
// flipScreenVertically : 32,63---95,63                  

#include <Wire.h>                                        // with mod SSD1306.cpp
#include "SSD1306.h"                                     // with mod SSD1306.h
extern "C" {
  #include "user_interface.h" 
}
SSD1306 display(0x3c,D2,D1);                             // SDA=GPIO04,SCL=5
float r, x1, z1, y2;                                     //
int f[8][2];                                             // Draw box
int c[8][3];                                             // Cube
 
void setup() {                                           //
  display.init();                                        // OLED
  display.setFont(ArialMT_Plain_10);                     //
  display.setTextAlignment(TEXT_ALIGN_LEFT);             //
  display.flipScreenVertically();                        // OLED
  display.displayOn();                                   // OLED
  display.clear();                                       // OLED
}                                                        //
 
void loop() {                                            //
  for ( int q =  5; q < 10; q = q + 2 ){ cube(q);} // 
  for ( int q = 10; q >  5; q = q - 2 ){ cube(q);}       //
}                                                        //
 
void cube(int q){                                        //
  int c[8][3] = {                                        // Cube
    {-q,-q, q},{q,-q, q},{q,q, q},{-q,q, q},             //
    {-q,-q,-q},{q,-q,-q},{q,q,-q},{-q,q,-q} };           //
  for (int a = 0; a <= 360; a = a + 3 ) {                // 0 to 360 degree
   for (int i = 0; i < 8; i++) {                         //
    r       = a * 0.0174531;                             // 1 degree
    x1      = c[i][2] * sin(r) + c[i][0] * cos(r);       // rotate X
    z1      = c[i][2] * cos(r) - c[i][0] * sin(r);       // rotate Z          
    y2      = c[i][1] * cos(r) - z1      * sin(r);       // rotate Y
    f[i][0] = x1      * cos(r) - y2      * sin(r) + 64;  // X
    f[i][1] = x1      * sin(r) + y2      * cos(r) + 40;  // Y
    f[i][2] = c[i][1] * sin(r) + z1      * cos(r);       // Z
   }                                                     //
  display.clear();                                       //
  display.drawString(32,16,"Hax0r");                   //
  display.drawLine(f[0][0],f[0][1],f[1][0],f[1][1]);     //
  display.drawLine(f[1][0],f[1][1],f[2][0],f[2][1]);     //
  display.drawLine(f[2][0],f[2][1],f[3][0],f[3][1]);     //
  display.drawLine(f[3][0],f[3][1],f[0][0],f[0][1]);     //
  display.drawLine(f[4][0],f[4][1],f[5][0],f[5][1]);     //
  display.drawLine(f[5][0],f[5][1],f[6][0],f[6][1]);     //
  display.drawLine(f[6][0],f[6][1],f[7][0],f[7][1]);     //
  display.drawLine(f[7][0],f[7][1],f[4][0],f[4][1]);     //
  display.drawLine(f[0][0],f[0][1],f[4][0],f[4][1]);     //
  display.drawLine(f[1][0],f[1][1],f[5][0],f[5][1]);     //
  display.drawLine(f[2][0],f[2][1],f[6][0],f[6][1]);     //
  display.drawLine(f[3][0],f[3][1],f[7][0],f[7][1]);     //
  display.drawLine(f[1][0],f[1][1],f[3][0],f[3][1]);     // cross
  display.drawLine(f[0][0],f[0][1],f[2][0],f[2][1]);     // cross
  display.display();                                     //
  delay(1);                                              //
  }                                                      //
}                                                        //

