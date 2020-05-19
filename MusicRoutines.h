#define RIGHTSIDE 0
#define LEFTSIDE 1
#define FRONTSIDE 2
#define BACKSIDE 3
#define TOPSIDE 4
#define BOTTOMSIDE 5

int currentBPM = 128;
byte currentMusicRoutine = 3;
unsigned long lastBeatDisplayed = 0;
unsigned long lastBeatSync;
bool newSync = false;
byte musicRedValue = 7;
byte musicGreenValue = 15;
byte musicBlueValue = 15;



// MUSIC ROUTINES
//ALL ROUTINES START OFF BEAT
void flashToBeat() {
  int delayFactor;
  LEDWholeCubeChange(0,0,0);
  if (newSync) {
    newSync = false;
    delayFactor = millis() - lastBeatSync + 60000/currentBPM;
  } else {
    delayFactor = millis() - lastBeatDisplayed + 60000/currentBPM;
  }
  if (delayFactor > 0) {
    delay(delayFactor);
  } 
  LEDWholeCubeChange(musicRedValue,musicGreenValue,musicBlueValue);
  #ifdef DEBUG
    Serial.print("Current display bpm: ");
    Serial.print((int)(60000/(millis() - lastBeatDisplayed) + 0.5));
    Serial.print(". ms from last beat drawn: ");
    Serial.println((int)((millis() - lastBeatDisplayed) + 0.5));
  #endif
  lastBeatDisplayed = millis();
  LEDWholeCubeChange(0,0,0);
}
void bassSphere() {
  int lats = 3;
  int longs = lats;
  byte currentFrame[65];
  byte previousFrame[65];
  int staticDelayFactor = 12;
  int delayFactor;
  drawTinyCenterCube(musicRedValue, musicGreenValue, musicBlueValue);
  clearBytePointArray((byte*)currentFrame);
  calculateSphere(2, 3.5,3.5,3.5, lats*2, longs*2, (byte*)currentFrame);
  //takes about 117 ms to get to beat frame
  if (newSync) {
    newSync = false;
    delayFactor = 60000/currentBPM - (millis() - lastBeatSync) - 117;
  } else {
    delayFactor =  60000/currentBPM - (millis() - lastBeatDisplayed) - 117;
  }
  #ifdef DEBUG2
    Serial.print("delayFactor: ");
    Serial.println(delayFactor);
  #endif
  if (delayFactor > 0) {
    delay(delayFactor);
  } 
  drawBytePointArray((byte*)currentFrame, musicRedValue,musicGreenValue,musicBlueValue);
  drawTinyCenterCube(0,0,0);
  delay(staticDelayFactor);
  for (int i = 3; i < 5; i++) {
    clearBytePointArray((byte*)currentFrame);
    calculateSphere(i, 3.5,3.5,3.5, lats*i, longs*(i), (byte*)currentFrame);
    drawBytePointArray((byte*)currentFrame, musicRedValue,musicGreenValue,musicBlueValue);
    if (i == 4) {
      #ifdef DEBUG
        Serial.print("Current display bpm: ");
        Serial.println((int)(60000/(millis() - lastBeatDisplayed) + 0.5));
      #endif
      lastBeatDisplayed = millis();
    }
    drawBytePointArray((byte*)previousFrame, 0,0,0);
    copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
    delay(staticDelayFactor);
  }
  for (int i = 3; i >= 2; i--) {
    clearBytePointArray((byte*)currentFrame);
    calculateSphere(i, 3.5,3.5,3.5, lats*i, longs*i, (byte*)currentFrame);
    drawBytePointArray((byte*)currentFrame, musicRedValue,musicGreenValue,musicBlueValue);
    drawBytePointArray((byte*)previousFrame, 0,0,0);
    copyBytePointArray((byte*)currentFrame, (byte*)previousFrame);
    delay(staticDelayFactor);
  }
  drawBytePointArray((byte*)previousFrame, 0,0,0);
}
void plainClap(int whichPlain) {
  int delayFactor;
  int staticDelayFactor = 40;
  LEDPlainChange(whichPlain, 0, musicRedValue,musicGreenValue,musicBlueValue);
  LEDPlainChange(whichPlain, 7, musicRedValue,musicGreenValue,musicBlueValue);
  //takes 82 ms to get beat without delayFactor
  if (newSync) {
    newSync = false;
    delayFactor = 60000/currentBPM - (millis() - lastBeatSync) - 82;
  } else {
    delayFactor =  60000/currentBPM - (millis() - lastBeatDisplayed) - 82;
  }
  if (delayFactor > 0) {
    delay(delayFactor);
  } 
  LEDPlainChange(whichPlain, 1, musicRedValue,musicGreenValue,musicBlueValue);
  LEDPlainChange(whichPlain, 6, musicRedValue,musicGreenValue,musicBlueValue);
  delay(staticDelayFactor);
  LEDPlainChange(whichPlain, 2, musicRedValue,musicGreenValue,musicBlueValue);
  LEDPlainChange(whichPlain, 5, musicRedValue,musicGreenValue,musicBlueValue);
  delay(staticDelayFactor);
  LEDPlainChange(whichPlain, 3, musicRedValue,musicGreenValue,musicBlueValue);
  LEDPlainChange(whichPlain, 4, musicRedValue,musicGreenValue,musicBlueValue);
  #ifdef DEBUG
    Serial.print("Current display bpm: ");
    Serial.print((int)(60000/(millis() - lastBeatDisplayed) + 0.5));
    Serial.print(". ms from last beat drawn: ");
    Serial.println((int)((millis() - lastBeatDisplayed) + 0.5));
  #endif
  lastBeatDisplayed = millis();
  delay(staticDelayFactor);
  LEDPlainChange(whichPlain, 3, 0,0,0);
  LEDPlainChange(whichPlain, 4, 0,0,0);
  delay(staticDelayFactor);
  LEDPlainChange(whichPlain, 2, 0,0,0);
  LEDPlainChange(whichPlain, 5, 0,0,0);
  delay(staticDelayFactor);
  LEDPlainChange(whichPlain, 1, 0,0,0);
  LEDPlainChange(whichPlain, 6, 0,0,0);
  delay(staticDelayFactor);
}
void beatClap() {
  int whichPlain = random(1,4);
  for (int i=0;i<9;i++) {
    plainClap(whichPlain);
  }
  clean();
}
void LEDSwap(int y,int x,int z, byte R, byte G, byte B, bool swapY, bool swapX, bool swapZ, bool invertY, bool invertX, bool invertZ, bool doubleShift) {
  if (!swapY && !swapZ && !swapX) {
    LED(abs(y-(invertY*7)),abs(x-(invertX*7)),abs(z-(invertZ*7)),R,G,B);
  } else if (swapY && swapZ && swapX && !doubleShift) {
        //Serial.println("all swap");
    LED(abs(z-(invertY*7)),abs(y-(invertX*7)),abs(x-(invertZ*7)),R,G,B);
  } else if (swapY && swapZ && swapX && doubleShift) {
        //Serial.println("all swap");
    LED(abs(x-(invertY*7)),abs(z-(invertX*7)),abs(y-(invertZ*7)),R,G,B);
  } else if (swapY && swapX) {
        //Serial.println("swap y with x");
    LED(abs(x-(invertY*7)),abs(y-(invertX*7)),abs(z-(invertZ*7)),R,G,B);
  } else if (swapY && swapZ) {
    //Serial.println("swap y with z");
    LED(abs(z-(invertY*7)),abs(x-(invertX*7)),abs(y-(invertZ*7)),R,G,B);
  } else if (swapX && swapZ) {
        //Serial.println("swap x with z");
    LED(abs(y-(invertY*7)),abs(z-(invertX*7)),abs(x-(invertZ*7)),R,G,B);
  } else {
    Serial.println("In LEDSwap got some weird shit, I'm scared and leaving");
  }
  
}
/*LED(y,x,z,r,g,b)
//currentSide 0 = right 1 = left 2 = front 3 = back 4 = top 5 =bottom faces
*/
int musicSlinkyLastStartFace = BOTTOMSIDE;
bool musicSlinkyReverse = false;
void musicSlinky() {
  int staticDelayFactor = 0;
  int delayFactor;
  float slope;
  float b;
  int myPoint[8], myLastPoint[8];
  bool swapX, swapY, swapZ, invertX, invertY, invertZ, doubleShift;
  byte R, G, B;
  if (musicSlinkyReverse) {
    R = musicRedValue, G = musicGreenValue, B = musicBlueValue;
  } else {
    R = 0, G = 0, B = 0;
  }
  int myDirection = random(0,4);
//  int myDirection = 0;
//  int musicSlinkyLastStartFace = TOPSIDE;
  switch(musicSlinkyLastStartFace) {
    case FRONTSIDE: 
      switch(myDirection) {
        case 0:
        //to the right
          swapX = 0, swapY = 1, swapZ = 1, invertX = 0, invertY = 0, invertZ = 1, doubleShift = 0;
          musicSlinkyLastStartFace = 0;
        break;
        case 1:
        //to the left
          swapX = 0, swapY = 1, swapZ = 1, invertX = 1, invertY = 1, invertZ = 1, doubleShift = 0;
          musicSlinkyLastStartFace = 1;
        break;
        case 2:
        //to the top
          swapX = 1, swapY = 1, swapZ = 1, invertX = 0, invertY = 0, invertZ = 1, doubleShift = 1;
          musicSlinkyLastStartFace = 4;
        break;
        case 3:
        //to the bottom
          swapX = 1, swapY = 1, swapZ = 1, invertX = 1, invertY = 1, invertZ = 1, doubleShift = 1;
          musicSlinkyLastStartFace = 5;
        break;
      }
    break;
    case BACKSIDE: 
      switch(myDirection) {
        case 0:
        //to the right
          swapX = 0, swapY = 1, swapZ = 1, invertX = 0, invertY = 0, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 0;
        break;
        case 1:
        //to the left
          swapX = 0, swapY = 1, swapZ = 1, invertX = 1, invertY = 1, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 1;
        break;
        case 2:
        //to the TOP
          swapX = 1, swapY = 1, swapZ = 1, invertX = 0, invertY = 0, invertZ = 0, doubleShift = 1;
          musicSlinkyLastStartFace = 4;
        break;
        case 3:
        //to the bottom
          swapX = 1, swapY = 1, swapZ = 1, invertX = 1, invertY = 1, invertZ = 0, doubleShift = 1;
          musicSlinkyLastStartFace = 5;
        break;
      }
    break;
    case LEFTSIDE: 
      switch(myDirection) {
        case 0:
        //to top
          swapX = 1, swapY = 1, swapZ = 0, invertX = 1, invertY = 0, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 4;
        break;
        case 1:
        //to bottom
          swapX = 1, swapY = 1, swapZ = 0, invertX = 1, invertY = 1, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 5;
        break;
        case 2:
        //to back
          swapX = 1, swapY = 1, swapZ = 1, invertX = 1, invertY = 0, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 3;
        break;
        case 3:
        //to front
          swapX = 1, swapY = 1, swapZ = 1, invertX = 1, invertY = 1, invertZ = 1, doubleShift = 0;
          musicSlinkyLastStartFace = 2;
        break;
      }
    break;
    case RIGHTSIDE: 
      switch(myDirection) {
        case 0:
        //to top
          swapX = 1, swapY = 1, swapZ = 0, invertX = 0, invertY = 0, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 4;
        break;
        case 1:
        //to bottom
          swapX = 1, swapY = 1, swapZ = 0, invertX = 0, invertY = 1, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 5;
        break;
        case 2:
        //to back
          swapX = 1, swapY = 1, swapZ = 1, invertX = 0, invertY = 0, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 3;
        break;
        case 3:
        //to front
          swapX = 1, swapY = 1, swapZ = 1, invertX = 0, invertY = 1, invertZ = 1, doubleShift = 0;
          musicSlinkyLastStartFace = 2;
        break;
      }
    break;
    case TOPSIDE: 
      switch(myDirection) {
        case 0:
        //tp the right
          swapX = 0, swapY = 0, swapZ = 0, invertX = 0, invertY = 0, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 0;
        break;
        case 1:
        //to the left
          swapX = 0, swapY = 0, swapZ = 0, invertX = 1, invertY = 0, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 1;
        break;
        case 2:
        //to the front
          swapX = 1, swapY = 0, swapZ = 1, invertX = 0, invertY = 0, invertZ = 1, doubleShift = 0;
          //musicSlinkyLastStartFace = 2;
        break;
        case 3:
        //to the back
          swapX = 1, swapY = 0, swapZ = 1, invertX = 0, invertY = 0, invertZ = 0, doubleShift = 0;
          //musicSlinkyLastStartFace = 3;
        break;
      }
    break;
    case BOTTOMSIDE: 
      switch(myDirection) {
        case 0:
        //right
          swapX = 0, swapY = 0, swapZ = 0, invertX = 0, invertY = 1, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 0;
        break;
        case 1:
        //left
          swapX = 0, swapY = 0, swapZ = 0, invertX = 1, invertY = 1, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 1;
        break;
        case 2:
        //front
          swapX = 1, swapY = 0, swapZ = 1, invertX = 0, invertY = 1, invertZ = 1, doubleShift = 0;
          musicSlinkyLastStartFace = 2;
        break;
        case 3:
        //back
          swapX = 1, swapY = 0, swapZ = 1, invertX = 0, invertY = 1, invertZ = 0, doubleShift = 0;
          musicSlinkyLastStartFace = 3;
        break;
      }
    break;
  }
  //takes about 190 ms to get to beat frame
  if (newSync) {
    newSync = false;
    delayFactor = 60000/currentBPM - (millis() - lastBeatSync) - 190;
  } else {
    delayFactor =  60000/currentBPM - (millis() - lastBeatDisplayed) - 190;
  }
  #ifdef DEBUG2
    Serial.print("delayFactor: ");
    Serial.println(delayFactor);
  #endif
  if (delayFactor > 0) {
    delay(delayFactor);
  } 
  unsigned long startTime = millis();
  for (int i = 7; i >= 0; i--) {
    slope = (7.0 - i)/7.0;
    b = i;
    for (int x = 0; x < 8; x++) {
      myLastPoint[x] = myPoint[x];
      myPoint[x] = (slope*x + b + 0.5);
      for (int z = 0; z < 8; z++) {
        if (!musicSlinkyReverse && x == 7)
          continue;
        LEDSwap(myPoint[x],x,z,R,G,B,swapY, swapX, swapZ, invertY, invertX, invertZ, doubleShift);
      }
    }
    delay(staticDelayFactor);
  }
  //second check to ensure we're not too fast
  if (newSync) {
    newSync = false;
    delayFactor = 60000/currentBPM - (millis() - lastBeatSync);
  } else {
    delayFactor =  60000/currentBPM - (millis() - lastBeatDisplayed);
  }
  #ifdef DEBUG2
    Serial.print("delayFactor: ");
    Serial.println(delayFactor);
  #endif
  if (delayFactor > 0) {
    delay(delayFactor);
  } 
  #ifdef DEBUG
    Serial.print("Current on beat display bpm: ");
    Serial.println((int)(60000/(millis() - lastBeatDisplayed) + 0.5));
  #endif
  lastBeatDisplayed = millis();
  for (int i = 0; i < 8; i++) {
    slope = (7.0)/(7.0 - i);
    b = 7 - slope*7;
    for (int y = 0; y < 8; y++) {
      myLastPoint[y] = myPoint[y];
      //check if vertical line
      if ((7.0 - i) != 0) {
        myPoint[y] = ((y - b)/slope + 0.5);
      } else {
        myPoint[y] = i;
      }
      for (int z = 0; z < 8; z++) {
        if (!musicSlinkyReverse && myPoint[y] == 7)
          continue;
        LEDSwap(y,myPoint[y],z,R,G,B,swapY, swapX, swapZ, invertY, invertX, invertZ, doubleShift);
      }
    }
    delay(staticDelayFactor);
  }
  musicSlinkyReverse = !musicSlinkyReverse;
}

#define MUSICROUTINES 4
void (*musicRoutines[MUSICROUTINES])() = {
  flashToBeat,
  bassSphere,
  beatClap,
  musicSlinky
};
void musicModeLoop() {
  while (displayMode == MUSICMODE) {
    (*musicRoutines[currentMusicRoutine])();
  }
}

