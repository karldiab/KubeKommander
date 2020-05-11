// For dancing sphere
//points is 65B (512b + and extra byte to easily handle any outofbounds leds that are created) 
//array that represents if each led should be on or off
//does not clear existing array data
void calculateSphere(double r, float zOffset, float xOffset, float yOffset, int lats, int longs, byte* points){
  int i, j;
  for (i = 0; i <= lats; i++) {
    double lat0 = PI * (-0.5 + (double)(i - 1) / lats);
    double z0 = sin(lat0) * r;
    double zr0 = cos(lat0) * r;

    double lat1 = PI * (-0.5 + (double)i / lats);
    double z1 = sin(lat1) * r;
    double zr1 = cos(lat1) * r;

    for (j = 0; j <= longs; j++) {
      double lng = 2 * PI * (double)(j - 1) / longs;
      double x = cos(lng);
      double y = sin(lng);
      //0.5 added for proper float to int rounding
      unsigned int P1 = getLEDNumber((unsigned int)(z0 + zOffset + 0.5),
      (unsigned int)(x * zr0 + xOffset + 0.5),
      (unsigned int)(y * zr0 + yOffset + 0.5));
      unsigned int P2 = getLEDNumber((unsigned int)(z1 + zOffset + 0.5),
      (unsigned int)(x * zr1 + xOffset + 0.5),
      (unsigned int)(y * zr1 + yOffset + 0.5)); // b00000001
      points[P1 >> 3] |= (1 << (P1%8));
      points[P2 >> 3] |= (1 << (P2%8));
    }
  }
}
//points array must be at least 64 bytes long
void drawBytePointArray(byte* points, byte R, byte G, byte B) {
  for (int i = 0; i < 512; i++) {
    if (points[i >> 3] & (1 << (i%8)))
      LEDNo(i,R,G,B);
  }
}
void copyBytePointArray(byte* A, byte* B) {
//  if (arraySize > sizeof(B)/sizeof(B[0])) {
//    Serial.println("In copyByteArray, A and B arrays are not same size, exiting");
//    return;
//  }
  for (int i = 0; i < 64; i++) {
    B[i] = A[i];
  }
}
void clearBytePointArray(byte* points) {
   for (int i =0; i < 64; i++) {
    points[i] = 0;
  }
}
void sphereAnimationShrinkAndGrowFrom1Corner(byte* currentFrame, byte* previousFrame, int delayFactor, int lats, int longs, byte R, byte G, byte B) {
    #ifdef DEBUG2
      unsigned long drawStart = millis();
    #endif
    clearBytePointArray((byte*)currentFrame);
    calculateSphere(13, 0,0,0, lats*13, longs*13, (byte*)currentFrame);
    drawBytePointArray((byte*)currentFrame, R, G, B);
    copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
    #ifdef DEBUG2
      Serial.print("Took ");
      Serial.print(millis() - drawStart);
      Serial.print("ms to draw sphere of size 7");
    #endif
    delay(delayFactor);
    for (int i = 12; i >= 1; i--) {
      #ifdef DEBUG2
        drawStart = millis();
      #endif
      clearBytePointArray((byte*)currentFrame);
      calculateSphere(i, 0,0,0, lats*i, longs*(i), (byte*)currentFrame);
      drawBytePointArray((byte*)currentFrame, R, G, B);
      drawBytePointArray((byte*)previousFrame, 0,0,0);
      copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
    #ifdef DEBUG2
      Serial.print("Took ");
      Serial.print(millis() - drawStart);
      Serial.print("ms to draw spheres of size ");
      Serial.println(i);
    #endif
      delay(delayFactor);
    }
    clean();
    delay(delayFactor);
    for (int i = 2; i < 14; i++) {
      #ifdef DEBUG2
        drawStart = millis();
      #endif
      clearBytePointArray((byte*)currentFrame);
      calculateSphere(i, 0,0,0, lats*i, longs*(i), (byte*)currentFrame);
      drawBytePointArray((byte*)currentFrame, R, G, B);
      drawBytePointArray((byte*)previousFrame, 0,0,0);
      copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
      #ifdef DEBUG2
        Serial.print("Took ");
        Serial.print(millis() - drawStart);
        Serial.print("ms to draw spheres of size ");
        Serial.println(i);
      #endif
      delay(delayFactor);
    }
    clean();
    delay(delayFactor);
}
void sphereAnimationGrowAndShrinkFromCenter(byte* currentFrame, byte* previousFrame, int delayFactor, int lats, int longs, byte R, byte G, byte B) {
    float zOffset = 3.5;
    clearBytePointArray((byte*)currentFrame);
    calculateSphere(1, zOffset,zOffset,zOffset, lats, longs, (byte*)currentFrame);
    drawBytePointArray((byte*)currentFrame, R, G, B);
    copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
    delay(delayFactor);
    for (int i = 2; i < 9; i++) {
      clearBytePointArray((byte*)currentFrame);
      calculateSphere(i, zOffset,zOffset,zOffset, lats*i, longs*(i), (byte*)currentFrame);
      drawBytePointArray((byte*)currentFrame, R, G, B);
      drawBytePointArray((byte*)previousFrame, 0,0,0);
      copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
      delay(delayFactor);
    }
    for (int i = 8; i >= 1; i--) {
      #ifdef DEBUG2
        unsigned long drawStart = millis();
      #endif
      clearBytePointArray((byte*)currentFrame);
      calculateSphere(i, zOffset,zOffset,zOffset, lats*i, longs*(i), (byte*)currentFrame);
      drawBytePointArray((byte*)currentFrame, R, G, B);
      drawBytePointArray((byte*)previousFrame, 0,0,0);
      copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
    #ifdef DEBUG2
      Serial.print("Took ");
      Serial.print(millis() - drawStart);
      Serial.print("ms to draw spheres of size ");
      Serial.println(i);
    #endif
      delay(delayFactor);
    }
    clean();
    delay(delayFactor);
}
void sphereAnimationGrowFrom2Corners(byte* currentFrame, byte* previousFrame, int delayFactor, int lats, int longs, byte R, byte G, byte B) {
  lats--;longs--;
  for (int i = 1; i < 14; i++) {
  #ifdef DEBUG2
    unsigned long drawStart = millis();
  #endif
  calculateSphere(i, 0,7,0, lats*i, longs*(i), (byte*)currentFrame);
  calculateSphere(i, 7,0,7, lats*i, longs*(i), (byte*)currentFrame);
  drawBytePointArray((byte*)currentFrame, R, G, B);
  drawBytePointArray((byte*)previousFrame, 0,0,0);
  copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
  clearBytePointArray((byte*)currentFrame);
  #ifdef DEBUG2
    Serial.print("Took ");
    Serial.print(millis() - drawStart);
    Serial.print("ms to draw spheres of size ");
    Serial.println(i);
  #endif
  delay(delayFactor);
}
clean();
}
void sphereAnimationGrowAndShrinkFrom4Corners(byte* currentFrame, byte* previousFrame, int delayFactor, int lats, int longs, byte R, byte G, byte B) {
    lats--;longs--;
    for (int i = 1; i < 5; i++) {
      #ifdef DEBUG2
        unsigned long drawStart = millis();
      #endif
      calculateSphere(i, 0,7,7, lats*i, longs*(i), (byte*)currentFrame);
      calculateSphere(i, 7,0,7, lats*i, longs*(i), (byte*)currentFrame);
      calculateSphere(i, 0,0,0, lats*i, longs*(i), (byte*)currentFrame);
      calculateSphere(i, 7,7,0, lats*i, longs*(i), (byte*)currentFrame);
      drawBytePointArray((byte*)currentFrame, R, G, B);
      drawBytePointArray((byte*)previousFrame, 0,0,0);
      copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
      clearBytePointArray((byte*)currentFrame);
      #ifdef DEBUG2
        Serial.print("Took ");
        Serial.print(millis() - drawStart);
        Serial.print("ms to draw spheres of size ");
        Serial.println(i);
      #endif
      delay(delayFactor);
    }
    for (int i = 5; i > 0; i--) {
      #ifdef DEBUG2
        unsigned long drawStart = millis();
      #endif
      calculateSphere(i, 0,7,7, lats*i, longs*(i), (byte*)currentFrame);
      calculateSphere(i, 7,0,7, lats*i, longs*(i), (byte*)currentFrame);
      calculateSphere(i, 0,0,0, lats*i, longs*(i), (byte*)currentFrame);
      calculateSphere(i, 7,7,0, lats*i, longs*(i), (byte*)currentFrame);
      drawBytePointArray((byte*)previousFrame, 0,0,0);
      drawBytePointArray((byte*)currentFrame, R, G, B);
      copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
      clearBytePointArray((byte*)currentFrame);
      #ifdef DEBUG2
        Serial.print("Took ");
        Serial.print(millis() - drawStart);
        Serial.print("ms to draw spheres of size ");
        Serial.println(i);
      #endif
      delay(delayFactor);
    }
    clean();
    delay(delayFactor);
}

