#define DEBUG 1

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <Wire.h>
#include "DefaultRoutines.h"
#include "CustomRoutines.h"




// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID        "e9459a79-a275-41a0-be30-1d1661e784cc"
#define CHARACTERISTIC_UUID "66495beb-4306-44a1-958d-81681776cbf1"
//for i2c
#define SLAVE_ADDR 9
char message[800];
byte command[6];
bool BLEMessageRecieved = false;
bool BLELEDCommandRecieved = false;
bool sendBufferFilled = false;
byte sendBuffer[3];

//DISPLAY STUFF
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
SSD1306  display(0x3c, 4, 15);

class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string value = pCharacteristic->getValue();
      #ifdef DEBUG
        Serial.print("New BLE message of len: ");
        Serial.println(value.length());
      #endif
      BLEMessageRecieved = true;
      #ifdef DEBUG2
        for (int i = 0; i < value.length(); i++) {
          Serial.print(value[i]);
        }
        Serial.println();
      #endif
      if (value.length() == 3) {
//        BLELEDCommandRecieved = true;
        #ifdef DEBUG
          Serial.println("Sending LED command");
        #endif
        Wire.beginTransmission(SLAVE_ADDR);
        for (int i=0; i<3; i++)
        {
          #ifdef DEBUG
            Serial.print((byte)value[i]);
            Serial.print(" ");
          #endif
          Wire.write(value[i]);  //data bytes are queued in local buffer
        }
        #ifdef DEBUG
          Serial.println();
        #endif
        Wire.endTransmission();
      } else {
        for (int i=0; i < value.length()/3; i++) {
          Wire.beginTransmission(SLAVE_ADDR);
          for (int j=0; j < 3; j++) {
            Wire.write(value[i*3+j]);
            #ifdef DEBUG2
              Serial.print((byte)value[i*3+j]);
              Serial.print(" ");
            #endif
          }
          #ifdef DEBUG2
            Serial.println();
          #endif
          Wire.endTransmission();
        }
      }
    }
};

void setup() {
  Serial.begin(9600);

  BLEDevice::init("KubeKommander");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);

  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setCallbacks(new MyCallbacks());

  pCharacteristic->setValue("Default value karl set");
  pService->start();

  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
  Wire.setClock(400000);
  Wire.begin();
  Wire.setClock(400000);
  Serial.println("Ready to rock baby");
//  // Initialising the UI will init the display too.
//  pinMode(16,OUTPUT);
//  digitalWrite(16, LOW);    // set GPIO16 low to reset OLED
//  delay(50); 
//  digitalWrite(16, HIGH); // while OLED is running, must set GPIO16 in high
//  display.init();
//
//  display.flipScreenVertically();
//  display.setFont(ArialMT_Plain_10);
}
void loop() {

  sinwaveTwo();
  folder();
  fireworks();
  color_wheelTWO();
  harlem_shake();
  bouncyvTwo();
  wipe_out();
  rain();
  spirals();
  tesseract();
  glowingCube();
  rubiksCube();
  dancingCube();
  displayTextRoutine();
  dancingSphere();
}
/*Function that sends an LED change to the cube
each message is 3 bytes long and looks like this
RRRRGGGG BBBBXXXNz NzNzNxNxNxNyNyNy
RGB are the color bits, X is extra data, N is the 9 bits for 0-511 LEDnumber
XXX = B001 is a special command meaning whole cube this color
*/
unsigned long sendTimer = millis();
unsigned int commandCount = 0;
void LED(int z,int x,int y, byte R, byte G, byte B) {
//  Serial.print("{");
//  Serial.print(z);
//  Serial.print(",");
//  Serial.print(x);
//  Serial.print(",");
//  Serial.print(y);
//  Serial.println(",1},");
  //delay to slow down the send rate to prevent errors
  delayMicroseconds(75);
   //Serial.println("counter = ");
   //Serial.println(counter);
    commandCount++;
    if (millis() - sendTimer > 1000) {
      Serial.print("Commands per second: ");
      Serial.println(commandCount);
      commandCount = 0;
      sendTimer = millis();
    }
    // First, check and make sure nothing went beyond the limits, just clamp things at either 0 or 7 for location, and 0 or 15 for brightness
    if(z<0)
      z=0;
    if(z>7)
      z=7;
    if(x<0)
      x=0;
    if(x>7)
      x=7;
    if(y<0)
      y=0;
    if(y>7)
      y=7;  
    if(R<0)
      R=0;
    if(R>15)
      R=15;
    if(G<0)
      G=0;
    if(G>15)
      G=15;
    if(B<0)
      B=0;
    if(B>15)
      B=15;  
    unsigned int LEDNumber = (z << 6) + (x << 3) + y;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write((R << 4) + G);
    Wire.write((B << 4) + (LEDNumber >> 8));
    Wire.write(LEDNumber);
    Wire.endTransmission();
}
unsigned long truncsendTimer = millis();
unsigned int trunccommandCount = 0;
void LEDTruncate(int z,int x,int y, byte R, byte G, byte B) {
//  Serial.print("{");
//  Serial.print(z);
//  Serial.print(",");
//  Serial.print(x);
//  Serial.print(",");
//  Serial.print(y);
//  Serial.println(",1},");
    // First, check and make sure nothing went beyond the limits, just clamp things at either 0 or 7 for location, and 0 or 15 for brightness
    if(z<0 || z>7 || x<0 || x>7 || y<0 || y>7)
      return;
    if(R<0)
      R=0;
    if(R>15)
      R=15;
    if(G<0)
      G=0;
    if(G>15)
      G=15;
    if(B<0)
      B=0;
    if(B>15)
      B=15; 
  //delay to slow down the send rate to prevent errors
  delayMicroseconds(75);
  trunccommandCount++;
  if (millis() - truncsendTimer > 1000) {
    Serial.print("Commands per second: ");
    Serial.println(trunccommandCount);
    trunccommandCount = 0;
    truncsendTimer = millis();
  } 
    unsigned int LEDNumber = (z << 6) + (x << 3) + y;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write((R << 4) + G);
    Wire.write((B << 4) + (LEDNumber >> 8));
    Wire.write(LEDNumber);
    Wire.endTransmission();
}
unsigned long LEDNosendTimer = millis();
unsigned int LEDNocommandCount = 0;
void LEDNo(int LEDNumber, byte R, byte G, byte B) {
  delayMicroseconds(75);
 //Serial.println("counter = ");
 //Serial.println(counter);
  LEDNocommandCount++;
  if (millis() - LEDNosendTimer > 1000) {
    Serial.print("Commands per second: ");
    Serial.println(LEDNocommandCount);
    LEDNocommandCount = 0;
    LEDNosendTimer = millis();
  }
  if(LEDNumber<0)
    LEDNumber=0;
  if(LEDNumber>512)
    LEDNumber=512;
  if(R<0)
    R=0;
  if(R>15)
    R=15;
  if(G<0)
    G=0;
  if(G>15)
    G=15;
  if(B<0)
    B=0;
  if(B>15)
    B=15;  
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write((R << 4) + G);
  Wire.write((B << 4) + (LEDNumber >> 8));
  Wire.write(LEDNumber);
  Wire.endTransmission();
}
unsigned long WCCsendTimer = millis();
unsigned int WCCcommandCount = 0;
void LEDWholeCubeChange(byte R, byte G, byte B) {
  #ifdef DEBUG
    Serial.print("RGB of whole cube: ");
    Serial.print(R);
    Serial.print(", ");
    Serial.print(G);
    Serial.print(", ");
    Serial.println(B);
  #endif
  delayMicroseconds(75);
   if (millis() - WCCsendTimer > 1000) {
    Serial.print("WCC Commands per second: ");
    Serial.println(WCCcommandCount);
    WCCcommandCount = 0;
    WCCsendTimer = millis();
  }
  if(R<0)
    R=0;
  if(R>15)
    R=15;
  if(G<0)
    G=0;
  if(G>15)
    G=15;
  if(B<0)
    B=0;
  if(B>15)
    B=15; 
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write((R << 4) + G);
  Wire.write((B << 4) | B00000010);
  Wire.write(0);
  Wire.endTransmission();
}
//return 512 if x y or z out of bounds
unsigned int getLEDNumber(unsigned int z, unsigned int x, unsigned int y) {
  if(z<0 || z>7 || x<0 || x>7 || y<0 || y>7)
    return 512;
  return (z << 6) + (x << 3) + y;
}
void clean() {
  LEDWholeCubeChange(0,0,0);
}

