#ifndef Matrix_Master_h
#define Matrix_Master_h

#include "Arduino.h"

/*
  First Version just for ||2 x (4x4 5x7 Matrix)||
  using 74595 as shift register
  Fikri A. Bachtiar / 03 Feb 2022
*/

class Matrix_Master {
  public:
    Matrix_Master(byte datC, byte laC, byte clkC, byte datR, byte laR, byte clkR);
    void begin();
    void displayNumber(int number);

  private:
    void write595C(byte data1, byte data2, byte data3, byte data4);
    void write595R(byte data1, byte data2);
    void _displayNumber(int Num1, int Num2);

    byte byte1C = 0x00;
    byte byte2C = 0x00;
    byte byte3C = 0x00;
    byte byte4C = 0x00;

    byte dataPinC, latchPinC, clockPinC;
    byte dataPinR, latchPinR, clockPinR;

    byte numberUp[10][10] = {
      {0x03, 0X03, 0x7c, 0x7c, 0x3c, 0x3c, 0x4c, 0x4c, 0x03, 0x03}, //0
      {0x7f, 0X7f, 0x73, 0x73, 0x01, 0x00, 0x7f, 0x7f, 0x7f, 0x7f}, //1
      {0x73, 0X73, 0x7c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x43, 0x43}, //2
      {0x73, 0X73, 0x7c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x43, 0x43}, //3
      {0x3f, 0X3f, 0x4f, 0x4f, 0x73, 0x73, 0x00, 0x00, 0x7f, 0x7f}, //4
      {0x40, 0X40, 0x4c, 0x4c, 0x4c, 0x4c, 0x4c, 0x4c, 0x3c, 0x3c}, //5
      {0x0f, 0X0f, 0x33, 0x33, 0x3c, 0x3c, 0x3c, 0x3c, 0x7f, 0x7f}, //6
      {0x7c, 0X7c, 0x7c, 0x7c, 0x3c, 0x3c, 0x4c, 0x4c, 0x70, 0x70}, //7
      {0x43, 0X43, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x43, 0x43}, //8
      {0x43, 0X43, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x03, 0x03}, //9
    };

    byte numberDown[10][10] = {
      {0x60, 0x60, 0x19, 0x19, 0x1e, 0x1e, 0x1f, 0x1f, 0x60, 0x60}, //0
      {0x7f, 0x7f, 0x1f, 0x1f, 0x00, 0x00, 0x1f, 0x1f, 0x7f, 0x7f}, //1
      {0x07, 0x07, 0x19, 0x19, 0x1e, 0x1e, 0x1e, 0x1e, 0x1f, 0x1f}, //2
      {0x67, 0x67, 0x1f, 0x1f, 0x1e, 0x1e, 0x1e, 0x1e, 0x61, 0x61}, //3
      {0x78, 0x78, 0x79, 0x79, 0x79, 0x79, 0x00, 0x00, 0x79, 0x79}, //4
      {0x67, 0x67, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x60, 0x60}, //5
      {0x60, 0x60, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x61, 0x61}, //6
      {0x7f, 0x7f, 0x01, 0x01, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f}, //7
      {0x61, 0x61, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x61, 0x61}, //8
      {0x7f, 0x7f, 0x1e, 0x1e, 0x1e, 0x1e, 0x66, 0x66, 0x78, 0x78}, //9
    };

    byte charNumUp[20] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                          0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
                         };
    byte charNumDown[20] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
                           };
};

#endif
