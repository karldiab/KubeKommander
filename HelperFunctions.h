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
void sphereAnimationHugeSphereMoving(byte* currentFrame, byte* previousFrame, int delayFactor, int lats, int longs, byte R, byte G, byte B) {
    byte sphereSize = 6;
    clearBytePointArray((byte*)currentFrame);
    calculateSphere(sphereSize, 7,7,7, lats*sphereSize, longs*sphereSize, (byte*)currentFrame);
    drawBytePointArray((byte*)currentFrame, R, G, B);
    copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
    delay(delayFactor);
    for (int i = 6; i >= 0; i--) {
      clearBytePointArray((byte*)currentFrame);
      calculateSphere(sphereSize, i,7,7, lats*sphereSize, longs*sphereSize, (byte*)currentFrame);
      drawBytePointArray((byte*)currentFrame, R, G, B);
      drawBytePointArray((byte*)previousFrame, 0,0,0);
      copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
      delay(delayFactor);
    }
    clean();
    delay(delayFactor);
    for (int i = 6; i >= 0; i--) {
      clearBytePointArray((byte*)currentFrame);
      calculateSphere(sphereSize, 0,i,i, lats*sphereSize, longs*sphereSize, (byte*)currentFrame);
      drawBytePointArray((byte*)currentFrame, R, G, B);
      drawBytePointArray((byte*)previousFrame, 0,0,0);
      copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
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

// FOR RUBIKS

void rubiksCleanup() {
  for (int i = 0; i < 7; i++) {
    LED(0,0,i,0,0,0);
    LED(0,7,i,0,0,0);
    LED(0,i,0,0,0,0);
    LED(0,i,7,0,0,0);
    LED(7,0,i,0,0,0);
    LED(7,7,i,0,0,0);
    LED(7,i,0,0,0,0);
    LED(7,i,7,0,0,0);
    LED(i,0,0,0,0,0);
    LED(i,7,0,0,0,0);
    LED(i,0,7,0,0,0);
    LED(i,7,7,0,0,0);
    if (i > 0)
      for (int j = 1; j < 7; j++) {
        for (int k = 1; k < 7; k++) {
          LED(i,j,k,0,0,0);
        }
      }
  }
}
void displayRubiksCube(int* faceStickers) {
  for (int i = 0; i < 6; i++){
    for (int j=0; j< 3; j++) {
       for (int k=0; k< 3; k++) {
          int LEDPositions[4][4];
          MultiplyIntMatrix((int*)stickerLEDPositions[j][k], (int*)sideDisplayTransforms[i], 4,4,4, (int*)LEDPositions);
          //delay(1000);
          for (int l=0; l < 4; l++) {
            int stickerColor = faceStickers[(9*i)+(3*j)+k];//faceStickers[i][j][k];
            LED(LEDPositions[l][0],LEDPositions[l][1],LEDPositions[l][2],colorTranslator[stickerColor][0],colorTranslator[stickerColor][1],colorTranslator[stickerColor][2]);
            //
          }
       }
    }
  }
}
void rotateCube(int* oldPositions, int* newPositions, int sideToRotate, bool CW) {
  for (int i = 0; i < 54; i++) {
    newPositions[i] = oldPositions[i];
  }
  for (int i =0; i < 21; i++) {
    if (CW)
      newPositions[originalStickersIndex[sideToRotate][i]] = oldPositions[pgm_read_byte_near(&swapIndex[sideToRotate][i])];
     else
      newPositions[pgm_read_byte_near(&swapIndex[sideToRotate][i])] = oldPositions[originalStickersIndex[sideToRotate][i]];
  }
  //precompute frames for animation
  //5 frames for animation, 84 LEDs are moving,4 ints for y,x,z,1
  //converted the middle 3 frame data to bytes to save memory
  byte frames[3][84][4];
  int firstFrame[84][4];
  byte LEDColors[21];
  //21 stickers moving
  for (int i =0; i < 21; i++) {
     int LEDPositions[4][4];
     MultiplyIntMatrix((int*)stickerLEDPositions[(originalStickersIndex[sideToRotate][i]%9)/3][originalStickersIndex[sideToRotate][i]%3], (int*)sideDisplayTransforms[originalStickersIndex[sideToRotate][i]/9], 4,4,4, (int*)LEDPositions);
     for (int j=0;j<4;j++) {
      for (int k = 0; k < 4; k++) {
          firstFrame[i*4+j][k] = LEDPositions[j][k];
      }
        LEDColors[i] = oldPositions[originalStickersIndex[sideToRotate][i]];
     }
  }
  if (!CW) {
    switch (sideToRotate) {
      case 0:
        sideToRotate = 1;
        break;
      case 1:
        sideToRotate = 0;
        break;
      case 2:
        sideToRotate = 3;
        break;
      case 3:
        sideToRotate = 2;
        break;
      case 4:
        sideToRotate = 5;
        break;
      case 5:
        sideToRotate = 4;
        break;
    }
  }
   for (int i=0;i<3;i++) {
    //holder of float values before rounding to int
    float frameData[5][4];
    for (int x = 0; x < 16; x++) {
      MultiplyIntAndFloatMatrixPROGMEM((int*)firstFrame[x*5],(float*)rubiksRotations[sideToRotate][i],5,4,4,(float*)frameData);
      for (int j = x*5; j < (x+1)*5; j++) {
        for (int k = 0; k < 4; k++) {
          //round float to byte
          int voxelPosition = (int)(frameData[j-(x*5)][k] + 0.5);
          frames[i][j][k] = (byte)voxelPosition;
        }
       }
    }
    MultiplyIntAndFloatMatrixPROGMEM((int*)firstFrame[80],(float*)rubiksRotations[sideToRotate][i],5,4,4,(float*)frameData);
    for (int j = 80; j < 84; j++) {
      for (int k = 0; k < 4; k++) {
        //round float to byte
        int voxelPosition = (int)(frameData[j-80][k] + 0.5);
        frames[i][j][k] = (byte)voxelPosition;
      }
     }
   }
   //printMatrix((int*)frames[1],8,4);
    for (int j = 0; j < 84; j++) {
      LED(firstFrame[j][0],firstFrame[j][1],firstFrame[j][2],colorTranslator[LEDColors[j/4]][0],colorTranslator[LEDColors[j/4]][1],colorTranslator[LEDColors[j/4]][2]);
    }
    delay(80);
    for (int i = 0; i < 3; i++) {
      rubiksCleanup();
      for (int j = 0; j < 84; j++) {
        LED(frames[i][j][0],frames[i][j][1],frames[i][j][2],colorTranslator[LEDColors[j/4]][0],colorTranslator[LEDColors[j/4]][1],colorTranslator[LEDColors[j/4]][2]);
      }
      delay(80);
    }
}

//END FUNCTIONS FOR RUBIKS

//FUNCTIONS FOR TEXT ROUTINES

void displaySolidLetter(char c,int R, int G, int B) {
  //LED(int level, int row, int column, byte red, byte green, byte blue)
  char display[8];// = font_data[c];
  int j = 7;
  for (int i = 0; i < 8; i++) {
    //display[0] = 0x00;
    display[i] = pgm_read_word_near(&font_data[c][j]);
    j--;
  }
  for (int level = 0; level < 8; level++) {
    int row = 0;
    //reverseCounter is used to horizonally flip the chars on opposite sides of the cube
    int reverseCounter = 7;
    for (unsigned int mask = 0x80; mask != 0; mask >>= 1) {
        if (display[level] & mask) {
          //bit is 1
            LED(level,row,0,R,G,B);
            LED(level,reverseCounter,7,R,G,B);
            LED(level,0,reverseCounter,R,G,B);
            LED(level,7,row,R,G,B);
        }
        else {
            // bit is 0
            LED(level,row,0,0,0,0);
            LED(level,reverseCounter,7,0,0,0);
            LED(level,0,reverseCounter,0,0,0);
            LED(level,7,row,0,0,0);
        }
        row++;
        reverseCounter--;
    }
  }
 }

 void displaySolidColoredLetter(char c,int colorSet) {
  char display[8];// = font_data[c];
  int j = 7;
  for (int i = 0; i < 8; i++) {
    //display[0] = 0x00;
    display[i] = pgm_read_word_near(&font_data[c][j]);
    j--;
  }
  for (int level = 0; level < 8; level++) {
    int row = 0;
    //reverseCounter is used to horizonally flip the chars on opposite sides of the cube
    int reverseCounter = 7;
    for (unsigned int mask = 0x80; mask != 0; mask >>= 1) {
        if (display[level] & mask) {
          //bit is 1
            LED(level,row,0,pgm_read_word_near(&colorSets[colorSet][level][0]),pgm_read_word_near(&colorSets[colorSet][level][1]),pgm_read_word_near(&colorSets[colorSet][level][2]));
            LED(level,reverseCounter,7,pgm_read_word_near(&colorSets[colorSet][level][0]),pgm_read_word_near(&colorSets[colorSet][level][1]),pgm_read_word_near(&colorSets[colorSet][level][2]));
            LED(level,0,reverseCounter,pgm_read_word_near(&colorSets[colorSet][level][0]),pgm_read_word_near(&colorSets[colorSet][level][1]),pgm_read_word_near(&colorSets[colorSet][level][2]));
            LED(level,7,row,pgm_read_word_near(&colorSets[colorSet][level][0]),pgm_read_word_near(&colorSets[colorSet][level][1]),pgm_read_word_near(&colorSets[colorSet][level][2]));
        }
        else {
            // bit is 0
            LED(level,row,0,0,0,0);
            LED(level,reverseCounter,7,0,0,0);
            LED(level,0,reverseCounter,0,0,0);
            LED(level,7,row,0,0,0);
        }
        row++;
        reverseCounter--;
    }
  }
 }

void displayScrollingLetter(char c, int R, int G, int B) { 
  Serial.println("displaying letteR");
  char letter[8];
  int j = 7;
  for (int i = 0; i < 8; i++) {
    letter[i] = pgm_read_word_near(&font_data[c][j--]);
  }
  int pointCounter = 0;
  //counts how many points this char has
  for (int level = 0; level < 8; level++) {
      for (unsigned int mask = 0x80; mask != 0; mask >>= 1) {
          if (letter[level] & mask) {
            pointCounter++;
          }
      }
    }
    byte pointsArray[pointCounter][4];
    pointCounter = 0;
    for (int level = 0; level < 8; level++) {
        int row = 0;
        for (unsigned int mask = 0x80; mask != 0; mask >>= 1) {
            if (letter[level] & mask) {
                pointsArray[pointCounter][0] = (byte)level;
                pointsArray[pointCounter][1] = (byte)row; 
                pointsArray[pointCounter][2] = (byte)0;
                pointsArray[pointCounter++][3] = (byte)1;
            }
            row++;
        }
      }
      int currentFrame[scrollingTextTransformObjects][pointCounter][4], previousFrame[scrollingTextTransformObjects][pointCounter][4];
      for (int steps = 0; steps < scrollingTextTransformSteps; steps++) {
        for (int transformObjects = 0 ; transformObjects < scrollingTextTransformObjects; transformObjects++) {
        if (steps == 0) {
          MultiplyIntMatrixPROGMEM((int*)pointsArray, (int*)scrollingTextTransform[transformObjects][steps], pointCounter, 4, 4, (int*)currentFrame[transformObjects]);
          CopyIntMatrix((int*)currentFrame[transformObjects], pointCounter, 4, (int*)previousFrame[transformObjects]);   
        } else {
          CopyIntMatrix((int*)currentFrame[transformObjects], pointCounter, 4, (int*)previousFrame[transformObjects]);
          MultiplyIntMatrixPROGMEM((int*)pointsArray, (int*)scrollingTextTransform[transformObjects][steps], pointCounter, 4, 4, (int*)currentFrame[transformObjects]);
        }
        for (int pointNo = 0; pointNo < pointCounter; pointNo++) {
          if (previousFrame[transformObjects][pointNo][0] >= 0 && previousFrame[transformObjects][pointNo][0] < 8 && previousFrame[transformObjects][pointNo][1] >= 0 && previousFrame[transformObjects][pointNo][1] < 8 && previousFrame[transformObjects][pointNo][2] >= 0 && previousFrame[transformObjects][pointNo][2] < 8) {
            LED((int)previousFrame[transformObjects][pointNo][0],(int)previousFrame[transformObjects][pointNo][1],(int)previousFrame[transformObjects][pointNo][2],0,0,0);
          }
        }
        for (int pointNo = 0; pointNo < pointCounter; pointNo++) {
          if (currentFrame[transformObjects][pointNo][0] >= 0 && currentFrame[transformObjects][pointNo][0] < 8 && currentFrame[transformObjects][pointNo][1] >= 0 && currentFrame[transformObjects][pointNo][1] < 8 && currentFrame[transformObjects][pointNo][2] >= 0 && currentFrame[transformObjects][pointNo][2] < 8) {
            LED((int)currentFrame[transformObjects][pointNo][0],(int)currentFrame[transformObjects][pointNo][1],(int)currentFrame[transformObjects][pointNo][2],R,G,B);
          }
        }
      }

      delay(150);
    }
 }
 
 void displayScrollingColoredLetter(char c, int colorSet) { 
  char letter[8];
  int j = 7;
  for (int i = 0; i < 8; i++) {
    letter[i] = pgm_read_word(&font_data[c][j--]);
  }
  int pointCounter = 0;
  //counts how many points this char has
  for (int level = 0; level < 8; level++) {
      for (unsigned int mask = 0x80; mask != 0; mask >>= 1) {
          if (letter[level] & mask) {
            pointCounter++;
          }
      }
    }
    int pointsArray[pointCounter][4];
    pointCounter = 0;
    for (int level = 0; level < 8; level++) {
        int row = 0;
        for (unsigned int mask = 0x80; mask != 0; mask >>= 1) {
            if (letter[level] & mask) {
                pointsArray[pointCounter][0] = level;
                pointsArray[pointCounter][1] = row; 
                pointsArray[pointCounter][2] = 0;
                pointsArray[pointCounter++][3] = 1;
            }
            row++;
        }
      }
      int currentFrame[scrollingTextTransformObjects][pointCounter][4], previousFrame[scrollingTextTransformObjects][pointCounter][4];
      for (int steps = 0; steps < scrollingTextTransformSteps; steps++) {
        for (int transformObjects = 0 ; transformObjects < scrollingTextTransformObjects; transformObjects++) {
          if (steps == 0) {
            MultiplyIntMatrix((int*)pointsArray, (int*)scrollingTextTransform[transformObjects][steps], pointCounter, 4, 4, (int*)currentFrame[transformObjects]);
            CopyIntMatrix((int*)currentFrame[transformObjects], pointCounter, 4, (int*)previousFrame[transformObjects]);
          } else {
            CopyIntMatrix((int*)currentFrame[transformObjects], pointCounter, 4, (int*)previousFrame[transformObjects]);
            MultiplyIntMatrix((int*)pointsArray, (int*)scrollingTextTransform[transformObjects][steps], pointCounter, 4, 4, (int*)currentFrame[transformObjects]);
          }
          for (int pointNo = 0; pointNo < pointCounter; pointNo++) {
            if (previousFrame[transformObjects][pointNo][0] >= 0 && previousFrame[transformObjects][pointNo][0] < 8 && previousFrame[transformObjects][pointNo][1] >= 0 && previousFrame[transformObjects][pointNo][1] < 8 && previousFrame[transformObjects][pointNo][2] >= 0 && previousFrame[transformObjects][pointNo][2] < 8) {
              LED((int)previousFrame[transformObjects][pointNo][0],(int)previousFrame[transformObjects][pointNo][1],(int)previousFrame[transformObjects][pointNo][2],0,0,0);
            }
          }
          for (int pointNo = 0; pointNo < pointCounter; pointNo++) {
            if (currentFrame[transformObjects][pointNo][0] >= 0 && currentFrame[transformObjects][pointNo][0] < 8 && currentFrame[transformObjects][pointNo][1] >= 0 && currentFrame[transformObjects][pointNo][1] < 8 && currentFrame[transformObjects][pointNo][2] >= 0 && currentFrame[transformObjects][pointNo][2] < 8) {
              LED((int)currentFrame[transformObjects][pointNo][0],(int)currentFrame[transformObjects][pointNo][1],(int)currentFrame[transformObjects][pointNo][2],pgm_read_word_near(&colorSets[colorSet][(int)currentFrame[transformObjects][pointNo][0]][0]),pgm_read_word_near(&colorSets[colorSet][(int)currentFrame[transformObjects][pointNo][0]][1]),pgm_read_word_near(&colorSets[colorSet][(int)currentFrame[transformObjects][pointNo][0]][2]));
            }
          }
        
      }
      delay(150);
    }
 }
void displaySolidText(String s, int delayms,int R, int G, int B) {
  for (int i = 0; i < s.length(); i++) {
    displaySolidLetter(s.charAt(i),R,G,B);
    delay(delayms);
  }
  displaySolidLetter(' ',R,G,B);
  delay(delayms);
}
void displaySolidColoredText(String s, int delayms, int colorSet) {
  for (int i = 0; i < s.length(); i++) {
    displaySolidColoredLetter(s.charAt(i),colorSet);
    delay(delayms);
  }
  displaySolidLetter(' ',0,0,0);
  delay(delayms);
}
void displaySingleChar(char c, int delayms,int R, int G, int B) {
  displaySolidLetter(c,R,G,B);
  delay(delayms);
  clean();
}

void displayScrollingText(String s,int R, int G, int B) {
  for (int i = 0; i < s.length(); i++) {
    displayScrollingLetter(s.charAt(i),R,G,B);
  }
}

void displayScrollingColoredText(String s,int colorSet) {
  for (int i = 0; i < s.length(); i++) {
    displayScrollingColoredLetter(s.charAt(i),colorSet);
  }
}

void displayScrollingRandomText() {
  String s = messages[random(numberOfMessages)];
  byte color = random(numberOfColorSets);
  for (int i = 0; i < s.length(); i++) {
    displayScrollingColoredLetter(s.charAt(i),color);
    clean();
  }
}
// END FUNCTIONS FOR TEXT ROUTINE

// MUSIC BASS SPHERE
void drawTinyCenterCube(byte red, byte green, byte blue) {
  LED (3,3,3,red,green,blue);
  LED (3,3,4,red,green,blue);
  LED (3,4,3,red,green,blue);
  LED (3,4,4,red,green,blue);
  LED (4,3,3,red,green,blue);
  LED (4,3,4,red,green,blue);
  LED (4,4,3,red,green,blue);
  LED (4,4,4,red,green,blue);
}
