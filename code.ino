#include "BluetoothSerial.h"
#include <Arduino.h>

BluetoothSerial serialBT;


char btSignal;


int Speed = 100;


int R1PWM = 19;
int R2PWM = 21;


int L1PWM = 23;
int L2PWM = 22;


#define R1 0
#define R2 1
#define L1 2
#define L2 3

void setup() {
  Serial.begin(115200);

  
  serialBT.begin("CUBIT 1.9");

  
  pinMode(R1PWM, OUTPUT);
  pinMode(R2PWM, OUTPUT);
  pinMode(L1PWM, OUTPUT);
  pinMode(L2PWM, OUTPUT);

 
  ledcSetup(R1, 5000, 8);  
  ledcAttachPin(R1PWM, R1);
  ledcSetup(R2, 5000, 8);  
  ledcAttachPin(R2PWM, R2);
  ledcSetup(L1, 5000, 8);  
  ledcAttachPin(L1PWM, L1);
  ledcSetup(L2, 5000, 8);  
  ledcAttachPin(L2PWM, L2);
}

void loop() {

  while (serialBT.available()) {
    btSignal = serialBT.read();
    

    if (btSignal == '0') Speed = 100;
    if (btSignal == '1') Speed = 110;
    if (btSignal == '2') Speed = 120;
    if (btSignal == '3') Speed = 130;
    if (btSignal == '4') Speed = 140;
    if (btSignal == '5') Speed = 150;
    if (btSignal == '6') Speed = 180;
    if (btSignal == '7') Speed = 200;
    if (btSignal == '8') Speed = 220;
    if (btSignal == '9') Speed = 240;
    if (btSignal == 'q') Speed = 255;

    if (btSignal == 'F')  
    {
      ledcWrite(R1, Speed);
      ledcWrite(R2, 0);
      ledcWrite(L1, Speed);
      ledcWrite(L2, 0);
    }

    else if (btSignal == 'B')  
    {
      ledcWrite(R1, 0);
      ledcWrite(R2, Speed);

      ledcWrite(L1, 0);
      ledcWrite(L2, Speed);

    }

    else if (btSignal == 'L')  
    {

      ledcWrite(R1, 0);
      ledcWrite(R2, Speed);

      ledcWrite(L1, Speed);
      ledcWrite(L2, 0);
    }

    else if (btSignal == 'R') 
    {
      ledcWrite(R1, Speed);
      ledcWrite(L1, 0);

      ledcWrite(R2, 0);
      ledcWrite(L2, Speed);
    }

    else if (btSignal == 'S')  
    {
      ledcWrite(R1, 0);
      ledcWrite(L1, 0);

      ledcWrite(R2, 0);
      ledcWrite(L2, 0);
    }

    else if (btSignal == 'I')  
    {
      ledcWrite(R1, Speed);
      ledcWrite(R2, 0);

      ledcWrite(L1, 0);
      ledcWrite(L2, 0);
    }

    else if (btSignal == 'J') 
    {
      ledcWrite(R1, 0);
      ledcWrite(R2, Speed);

      ledcWrite(L1, 0);
      ledcWrite(L2, 0);
    }

    else if (btSignal == 'G')  
    {
      ledcWrite(R1, 0);
      ledcWrite(R2, 0);

      ledcWrite(L1, Speed);
      ledcWrite(L2, 0);
    }

    else if (btSignal == 'H')  
    {
      ledcWrite(R1, 0);
      ledcWrite(R2, 0);

      ledcWrite(L1, 0);
      ledcWrite(L2, Speed);
    }
  }
}