#include "Arduino.h"
#include "Matrix_Master.h"

Matrix_Master::Matrix_Master(byte datC, byte laC, byte clkC, byte datR, byte laR, byte clkR) {
  dataPinC = datC;
  latchPinC = laC;
  clockPinC = clkC;

  dataPinR = datR;
  latchPinR = laR;
  clockPinR = clkR;
}

void Matrix_Master::begin() {
  pinMode(dataPinR, OUTPUT);
  pinMode(latchPinR, OUTPUT);
  pinMode(clockPinR, OUTPUT);

  pinMode(dataPinC, OUTPUT);
  pinMode(latchPinC, OUTPUT);
  pinMode(clockPinC, OUTPUT);
}

void Matrix_Master::displayNumber(int number) {
  int n1, n2;
  
  n1 = number/10;
  n2 = number%10;
  _displayNumber(n1, n2);
  
  byte1C = 0x01;
  for (int coloumn = 0; coloumn < 20; coloumn++) {
    write595R(0xff, 0xff);
    write595C(byte1C, byte2C, byte3C, byte4C);

    write595R(charNumUp[coloumn], charNumDown[coloumn]);
    delay(1);
    write595C(0x00, 0x00, 0x00, 0x00);

    byte1C = byte1C << 1;
    byte2C = byte2C << 1;
    byte3C = byte3C << 1;
    byte4C = byte4C << 1;

    if (byte1C > 0x10) {
      byte1C = 0x00;
      byte2C = 0x01;
    }

    if (byte2C > 0x10) {
      byte2C = 0x00;
      byte3C = 0x01;
    }

    if (byte3C > 0x10) {
      byte3C = 0x00;
      byte4C = 0x01;
    }
    if (byte4C > 0x10) {
      byte4C = 0x00;
    }
  }
}

void Matrix_Master::write595C(byte data1, byte data2, byte data3, byte data4) {
  digitalWrite(latchPinC, LOW); //Pull latch LOW to start sending data
  shiftOut(dataPinC, clockPinC, MSBFIRST, data1); //Send the data byte 1
  shiftOut(dataPinC, clockPinC, MSBFIRST, data2); //Send the data byte 2
  shiftOut(dataPinC, clockPinC, MSBFIRST, data3); //Send the data byte 3
  shiftOut(dataPinC, clockPinC, MSBFIRST, data4); //Send the data byte 4
  digitalWrite(latchPinC, HIGH); //Pull latch HIGH to stop sending data
}

void Matrix_Master::write595R(byte data1, byte data2) {
  digitalWrite(latchPinR, LOW); //Pull latch LOW to start sending data
  shiftOut(dataPinR, clockPinR, MSBFIRST, data1); //Send the data byte 1
  shiftOut(dataPinR, clockPinR, MSBFIRST, data2); //Send the data byte 2
  digitalWrite(latchPinR, HIGH); //Pull latch HIGH to stop sending data
}

void Matrix_Master::_displayNumber(int Num1, int Num2) {
  //number 1
  for (int i = 0; i < 10; i++) {
    charNumUp[i] = numberUp[Num1][i];
  }
  for (int i = 0; i < 10; i++) {
    charNumDown[i] = numberDown[Num1][i];
  }
  //number 2
  for (int i = 0; i < 10; i++) {
    charNumUp[i + 10] = numberUp[Num2][i];
  }
  for (int i = 0; i < 10; i++) {
    charNumDown[i + 10] = numberDown[Num2][i];
  }
}
