#include "RoutineData.h"
#include "MatrixMathFunctions.h"
#include "HelperFunctions.h"

void spirals() {
  int delayFactor = 17;
  int iterationSeed = 2;
  int iterations = iterationSeed;
  for (int runNumber = 0; runNumber < iterations; runNumber++) {
    int colorSet = random(numberOfColorSets);
    //LED(Y,X,Z,R,G,B);
    //start by making all faces light up by spiraling in from the outside. Each run through this has a color set chosen randomly (colorSet) which is a random index for the array of color sets, each set has 8 colors
    //I created above (colorSets array). Each LED's color depends on it's y position. eg if the rainbow color set is chosen, all bottom LEDS will be red, then the next ones up will be orange, etc. till we get to purple up top
    for (int i = 0; i < 8; i++) {//start outer square
      LED(0,i,0,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));//front face
      LED(0,i,7,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));//back face
      LED(0,0,i,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));//left face
      LED(0,7,i,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));//right face
      delay(delayFactor);
    }
    for (int i = 1; i < 8; i++) {
      LED(i,7,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,7,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,0,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,7,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      delay(delayFactor);
    }
    for (int i = 6; i >= 1; i--) {
      LED(7,i,0,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
      LED(7,i,7,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
      LED(7,0,i,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
      LED(7,7,i,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
      delay(delayFactor);
    }
    for (int i = 7; i >= 1; i--) {//end outer square
      LED(i,0,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,0,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,0,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,7,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      delay(delayFactor);
    }
    for (int i = 1; i < 7; i++) {//start first inner square
      LED(1,i,0,pgm_read_word_near(&colorSets[colorSet][1][0]),pgm_read_word_near(&colorSets[colorSet][1][1]),pgm_read_word_near(&colorSets[colorSet][1][2]));//front face
      LED(1,i,7,pgm_read_word_near(&colorSets[colorSet][1][0]),pgm_read_word_near(&colorSets[colorSet][1][1]),pgm_read_word_near(&colorSets[colorSet][1][2]));//back face
      LED(1,0,i,pgm_read_word_near(&colorSets[colorSet][1][0]),pgm_read_word_near(&colorSets[colorSet][1][1]),pgm_read_word_near(&colorSets[colorSet][1][2]));//left face
      LED(1,7,i,pgm_read_word_near(&colorSets[colorSet][1][0]),pgm_read_word_near(&colorSets[colorSet][1][1]),pgm_read_word_near(&colorSets[colorSet][1][2]));//right face
      LED(0,i,1,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));//bottom face
      LED(7,i,1,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));//top face
      delay(delayFactor);
    }
    for (int i = 1; i < 7; i++) {
      LED(i,6,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,6,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,0,6,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,7,6,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(0,6,i,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
      LED(7,6,i,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
      delay(delayFactor);
    }
    for (int i = 6; i > 1; i--) {
      LED(6,i,0,pgm_read_word_near(&colorSets[colorSet][6][0]),pgm_read_word_near(&colorSets[colorSet][6][1]),pgm_read_word_near(&colorSets[colorSet][6][2]));
      LED(6,i,7,pgm_read_word_near(&colorSets[colorSet][6][0]),pgm_read_word_near(&colorSets[colorSet][6][1]),pgm_read_word_near(&colorSets[colorSet][6][2]));
      LED(6,0,i,pgm_read_word_near(&colorSets[colorSet][6][0]),pgm_read_word_near(&colorSets[colorSet][6][1]),pgm_read_word_near(&colorSets[colorSet][6][2]));
      LED(6,7,i,pgm_read_word_near(&colorSets[colorSet][6][0]),pgm_read_word_near(&colorSets[colorSet][6][1]),pgm_read_word_near(&colorSets[colorSet][6][2]));
      LED(0,i,6,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
      LED(7,i,6,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
      delay(delayFactor);
    }
    for (int i = 6; i > 1; i--) {//end first inner square
      LED(i,1,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,1,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,0,1,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,7,1,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(0,1,i,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
      LED(7,1,i,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
      delay(delayFactor);
    }
    for (int i = 2; i < 6; i++) {//start second inner square
      LED(2,i,0,pgm_read_word_near(&colorSets[colorSet][2][0]),pgm_read_word_near(&colorSets[colorSet][2][1]),pgm_read_word_near(&colorSets[colorSet][2][2]));
      LED(2,i,7,pgm_read_word_near(&colorSets[colorSet][2][0]),pgm_read_word_near(&colorSets[colorSet][2][1]),pgm_read_word_near(&colorSets[colorSet][2][2]));
      LED(2,0,i,pgm_read_word_near(&colorSets[colorSet][2][0]),pgm_read_word_near(&colorSets[colorSet][2][1]),pgm_read_word_near(&colorSets[colorSet][2][2]));
      LED(2,7,i,pgm_read_word_near(&colorSets[colorSet][2][0]),pgm_read_word_near(&colorSets[colorSet][2][1]),pgm_read_word_near(&colorSets[colorSet][2][2]));  
      LED(0,i,2,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
      LED(7,i,2,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));  
      delay(delayFactor);
    }
    for (int i = 2; i < 6; i++) {
      LED(i,5,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,5,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,0,5,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,7,5,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(0,5,i,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
      LED(7,5,i,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
      delay(delayFactor);
    }
    for (int i = 5; i > 2; i--) {
      LED(5,i,0,pgm_read_word_near(&colorSets[colorSet][5][0]),pgm_read_word_near(&colorSets[colorSet][5][1]),pgm_read_word_near(&colorSets[colorSet][5][2]));
      LED(5,i,7,pgm_read_word_near(&colorSets[colorSet][5][0]),pgm_read_word_near(&colorSets[colorSet][5][1]),pgm_read_word_near(&colorSets[colorSet][5][2]));
      LED(5,0,i,pgm_read_word_near(&colorSets[colorSet][5][0]),pgm_read_word_near(&colorSets[colorSet][5][1]),pgm_read_word_near(&colorSets[colorSet][5][2]));
      LED(5,7,i,pgm_read_word_near(&colorSets[colorSet][5][0]),pgm_read_word_near(&colorSets[colorSet][5][1]),pgm_read_word_near(&colorSets[colorSet][5][2]));
      LED(0,i,5,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
      LED(7,i,5,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
      delay(delayFactor);
    }
    for (int i = 5; i > 2; i--) {//end second inner square
      LED(i,2,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,2,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,0,2,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(i,7,2,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
      LED(0,2,i,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
      LED(7,2,i,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
      delay(delayFactor);
    }
    LED(3,3,0,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));//start third inner square
    LED(3,3,7,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
    LED(3,0,3,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
    LED(3,7,3,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
    LED(0,3,3,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
    LED(7,3,3,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
    delay(delayFactor);
    LED(3,4,0,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
    LED(3,4,7,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
    LED(3,0,4,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
    LED(3,7,4,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
    LED(0,4,3,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
    LED(7,4,3,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
    delay(delayFactor);
    LED(4,4,0,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
    LED(4,4,7,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
    LED(4,0,4,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
    LED(4,7,4,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
    LED(0,4,4,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
    LED(7,4,4,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
    
    delay(delayFactor);
    LED(4,3,0,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
    LED(4,3,7,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
    LED(4,0,3,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
    LED(4,7,3,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
    LED(0,3,4,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
    LED(7,3,4,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));//end third inner square
    delay(delayFactor);
    //Cool beans, now do the spiral thing again in reverse but change LED colors to 0,0,0 to turn them off. This will make the spiral undo itself from the inside
    LED(4,3,0,0,0,0);
    LED(4,3,7,0,0,0);
    LED(4,0,3,0,0,0);
    LED(4,7,3,0,0,0);
    LED(0,3,4,0,0,0);
    LED(7,3,4,0,0,0);
    delay(delayFactor);
    LED(4,4,0,0,0,0);
    LED(4,4,7,0,0,0);
    LED(4,0,4,0,0,0);
    LED(4,7,4,0,0,0);
    LED(0,4,4,0,0,0);
    LED(7,4,4,0,0,0);
    delay(delayFactor);
    LED(3,4,0,0,0,0);
    LED(3,4,7,0,0,0);
    LED(3,0,4,0,0,0);
    LED(3,7,4,0,0,0);
    LED(0,4,3,0,0,0);
    LED(7,4,3,0,0,0);
    delay(delayFactor);
    LED(3,3,0,0,0,0);
    LED(3,3,7,0,0,0);
    LED(3,0,3,0,0,0);
    LED(3,7,3,0,0,0);
    LED(0,3,3,0,0,0);
    LED(7,3,3,0,0,0);
    delay(delayFactor);
    for (int i = 3; i <= 5; i++) {
      LED(i,2,0,0,0,0);
      LED(i,2,7,0,0,0);
      LED(i,0,2,0,0,0);
      LED(i,7,2,0,0,0);
      LED(0,2,i,0,0,0);
      LED(7,2,i,0,0,0);
      delay(delayFactor);
    }
    for (int i = 2; i <= 5; i++) {
      LED(5,i,0,0,0,0);
      LED(5,i,7,0,0,0);
      LED(5,0,i,0,0,0);
      LED(5,7,i,0,0,0);
      LED(0,i,5,0,0,0);
      LED(7,i,5,0,0,0);
      delay(delayFactor);
    }
    for (int i = 5; i > 2; i--) {
      LED(i,5,0,0,0,0);
      LED(i,5,7,0,0,0);
      LED(i,0,5,0,0,0);
      LED(i,7,5,0,0,0);
      LED(0,5,i,0,0,0);
      LED(7,5,i,0,0,0);
      delay(delayFactor);
    }
    for (int i = 5; i > 1; i--) {
      LED(2,i,0,0,0,0);
      LED(2,i,7,0,0,0);
      LED(2,0,i,0,0,0);
      LED(2,7,i,0,0,0);  
      LED(0,i,2,0,0,0);
      LED(7,i,2,0,0,0);  
      delay(delayFactor);
    }
    for (int i = 2; i <= 5; i++) {
      LED(i,1,0,0,0,0);
      LED(i,1,7,0,0,0);
      LED(i,0,1,0,0,0);
      LED(i,7,1,0,0,0);
      LED(0,1,i,0,0,0);
      LED(7,1,i,0,0,0);
      delay(delayFactor);
    }
      for (int i = 1; i <= 5; i++) {
      LED(6,i,0,0,0,0);
      LED(6,i,7,0,0,0);
      LED(6,0,i,0,0,0);
      LED(6,7,i,0,0,0);
      LED(0,i,6,0,0,0);
      LED(7,i,6,0,0,0);
      delay(delayFactor);
    }
      for (int i = 7; i > 1; i--) {//d
      LED(i,6,0,0,0,0);
      LED(i,6,7,0,0,0);
      LED(i,0,6,0,0,0);
      LED(i,7,6,0,0,0);
      LED(0,6,i,0,0,0);
      LED(7,6,i,0,0,0);
      delay(delayFactor);
    }
     for (int i = 6; i > 0; i--) {//d
      LED(1,i,0,0,0,0);
      LED(1,i,7,0,0,0);
      LED(1,0,i,0,0,0);
      LED(1,7,i,0,0,0);
      LED(0,i,1,0,0,0);
      LED(7,i,1,0,0,0);
      delay(delayFactor);
    }
      for (int i = 1; i <= 7; i++) {
      LED(i,0,0,0,0,0);
      LED(i,0,7,0,0,0);
      LED(i,0,0,0,0,0);
      LED(i,7,7,0,0,0);
      delay(delayFactor);
    }
      for (int i = 1; i <= 7; i++) {
      LED(7,i,0,0,0,0);
      LED(7,i,7,0,0,0);
      LED(7,0,i,0,0,0);
      LED(7,7,i,0,0,0);
      delay(delayFactor);
    }
      for (int i = 7; i > 0; i--) {
      LED(i,7,0,0,0,0);
      LED(i,7,7,0,0,0);
      LED(i,0,7,0,0,0);
      LED(i,7,7,0,0,0);
      delay(delayFactor);
    }
      for (int i = 7; i > 0; i--) {
      LED(0,i,0,0,0,0);
      LED(0,i,7,0,0,0);
      LED(0,0,i,0,0,0);
      LED(0,7,i,0,0,0);
      delay(delayFactor);
    }
  }
  clean();
} //spirals

void tesseract() { 
  clean();
  bool firstRun = true;
  byte startingColor[3];
  byte oldStartingColor[3];
  int duration = 4;
  for (int runs = 0; runs < duration; runs++) {
    //0 = y 1 = x 2 = z
    byte colorShiftDirection = random(3);
    byte colorSet = random(numberOfColorSets);
    bool colorDirection = random(1);
    startingColor[0] = pgm_read_word_near(&colorSets[colorSet][colorDirection? 7 : 0][0]);
    startingColor[1] = pgm_read_word_near(&colorSets[colorSet][colorDirection? 7 : 0][1]);
    startingColor[2] = pgm_read_word_near(&colorSets[colorSet][colorDirection? 7 : 0][2]);
    if (!firstRun) {
      for (int frame = 0; frame < 6; frame++) {
        int R = map(frame,0,6,oldStartingColor[0],startingColor[0]);
        int G = map(frame,0,6,oldStartingColor[1],startingColor[1]);
        int B = map(frame,0,6,oldStartingColor[2],startingColor[2]);
        for (int i = 0; i < 120; i++) {
            LED(pgm_read_byte_near(&tesseractPoints[i][0]),pgm_read_byte_near(&tesseractPoints[i][1]),pgm_read_byte_near(&tesseractPoints[i][2]),R,G,B);
        }
        delay(150);
      }
    } else {
      for (int i = 0; i < 120; i++) {
          LED(pgm_read_byte_near(&tesseractPoints[i][0]),pgm_read_byte_near(&tesseractPoints[i][1]),pgm_read_byte_near(&tesseractPoints[i][2]),startingColor[0],startingColor[1],startingColor[2]);
      }
    }
    firstRun = false;
    int yShift;
    delay(150*random(1,4));
    for (int frame = 7; frame > -8; frame--) {
      for (int i = 0; i < 120; i++) {
        int xyzPosition = pgm_read_byte_near(&tesseractPoints[i][colorShiftDirection]);
        if (colorDirection) {
          yShift = xyzPosition + frame > 7 ? 7 : xyzPosition + frame;
        } else {
          yShift = xyzPosition - frame > 7 ? 7 : xyzPosition - frame;
        }
          yShift = yShift < 0 ? 0 : yShift;
          LED(pgm_read_byte_near(&tesseractPoints[i][0]),pgm_read_byte_near(&tesseractPoints[i][1]),pgm_read_byte_near(&tesseractPoints[i][2]),pgm_read_word_near(&colorSets[colorSet][yShift][0]),pgm_read_word_near(&colorSets[colorSet][yShift][1]),pgm_read_word_near(&colorSets[colorSet][yShift][2]));
      }
      delay(150);
      if (frame == -7) {
        startingColor[0] = pgm_read_word_near(&colorSets[colorSet][yShift][0]);
        startingColor[1] = pgm_read_word_near(&colorSets[colorSet][yShift][1]);
        startingColor[2] = pgm_read_word_near(&colorSets[colorSet][yShift][2]);
      }
    }
    delay(150*random(1,4));
    oldStartingColor[0] = startingColor[0];
    oldStartingColor[1] = startingColor[1];
    oldStartingColor[2] = startingColor[2];
    if (random(1000) < 30) {
      for (int runs = 0; runs < 300; runs++) {
        for (int i = 0; i < 120; i++) {
            LED(pgm_read_byte_near(&tesseractPoints[i][0]),pgm_read_byte_near(&tesseractPoints[i][1]),pgm_read_byte_near(&tesseractPoints[i][2]),random(13),random(16),random(16));
        }
      }
    }
  }
  clean();
} //tesserect

void glowingCube() {
  clean();
  int upOrDown;
  int iterations = 20 * pow(2,3);
  int numberOfFrames = 17;
  bool edgeCurrentlyGlowing[numberOfFrames] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  //first 3 items are xyz of current glow location, 4th item indicates whether its x y or z that changes, 5th is which frame edge is currently on, 6th is direction of travel
  int edgeCurrentFrame[numberOfFrames][6] = {
    {0,0,0,2,0,1},
    {0,0,7,1,0,1},
    {0,7,7,2,0,-1},
    {0,7,0,1,0,-1},
    {0,0,0,0,0,1},
    {7,0,0,1,0,1},
    {7,7,0,2,0,1},
    {7,7,7,1,0,-1},
    {7,0,7,0,0,-1},
    {0,0,7,1,0,1},
    {0,7,7,0,0,1},
    {7,7,7,1,0,-1},
    {7,0,7,2,0,-1},
    {7,0,0,1,0,1},
    {7,7,0,0,0,-1},
    {0,7,0,1,0,-1},
    {0,0,0,2,0,1}};
  for (int i = 0; i < iterations; i++) {
    for (int j = 0; j < numberOfFrames; j++) {
      if (edgeCurrentlyGlowing[j] != 0) {
        if (edgeCurrentFrame[j][4] == 8) {
          LED(edgeCurrentFrame[j][0],edgeCurrentFrame[j][1],edgeCurrentFrame[j][2],0,0,0);
          edgeCurrentFrame[j][4] = 0;
          edgeCurrentlyGlowing[j] = 0;
          if (edgeCurrentFrame[j][5] == 1) {
            edgeCurrentFrame[j][edgeCurrentFrame[j][3]] = 0;
          } else {
            edgeCurrentFrame[j][edgeCurrentFrame[j][3]] = 7;
          }
          if (j != numberOfFrames-1) {
            edgeCurrentlyGlowing[j+1] = true;
            //edgeCurrentFrame[j+1][edgeCurrentFrame[j+1][3]] = 1;
          }
          break;
        }
        if (edgeCurrentFrame[j][4] == 0) {
          LED(edgeCurrentFrame[j][0],edgeCurrentFrame[j][1],edgeCurrentFrame[j][2],random(16),random(16),random(16));
        } else {
          LED(edgeCurrentFrame[j][0],edgeCurrentFrame[j][1],edgeCurrentFrame[j][2],0,0,0);
          edgeCurrentFrame[j][edgeCurrentFrame[j][3]] += edgeCurrentFrame[j][5];
          LED(edgeCurrentFrame[j][0],edgeCurrentFrame[j][1],edgeCurrentFrame[j][2],random(16),random(16),random(16));

        }
        edgeCurrentFrame[j][4]++;
      } else {
        if (random(240) >= 243 - 6) {
            edgeCurrentlyGlowing[j] = true;
        }
      }
    }
    delay(50);
  }
  clean();
} //glowing cube

void rain(){//****rainVersionTwo****rainVersionTwo****rainVersionTwo****rainVersionTwo****rainVersionTwo
  int x[64], y[64], z[64], addr, leds=64*0.1*(6+4), bright=1, ledcolor, colowheel;
  int xx[64], yy[64], zz[64], xold[64], yold[64], zold[64], slowdown;
  int delayFactor = 15 * (64/leds);
  
  for(addr=0; addr<64; addr++){
    x[addr]=random(8);
    y[addr]=random(8);
    z[addr]=random(8);
    xx[addr]=random(16);
    yy[addr]=random(16);
    zz[addr]=random(16);     
  }
  start=millis();
  while(millis()-start<(2000*pow(2,3))){
  //wipe_out();
  //for(addr=0; addr<leds; addr++)
  //LED(zold[addr], xold[addr], yold[addr], 0, 0, 0);
if(ledcolor<200){
  for(addr=0; addr<leds; addr++){
    LED(zold[addr], xold[addr], yold[addr], 0, 0, 0);
//  Serial.println(z[addr]);
//  Serial.println(x[addr]);
//  Serial.println(y[addr]);
//  Serial.println();
  if(z[addr]>=7)
  LED(z[addr], x[addr], y[addr], 0, 5, 15);
  if(z[addr]==6)
  LED(z[addr], x[addr], y[addr], 0, 1, 9);
   if(z[addr]==5)
  LED(z[addr], x[addr], y[addr], 0, 0, 10);
   if(z[addr]==4)
  LED(z[addr], x[addr], y[addr], 1, 0, 11); 
    if(z[addr]==3)
  LED(z[addr], x[addr], y[addr], 3, 0, 12);
    if(z[addr]==2)
  LED(z[addr], x[addr], y[addr], 10, 0, 15);
    if(z[addr]==1)
  LED(z[addr], x[addr], y[addr], 10, 0, 10);
    if(z[addr]<=0)
  LED(z[addr], x[addr], y[addr], 10, 0, 1);
}}//200

  else if(ledcolor>=200&&ledcolor<300){
  for(addr=0; addr<leds; addr++){
    LED(zold[addr], xold[addr], yold[addr], 0, 0, 0);
  if(z[addr]>=7)
  LED(z[addr], x[addr], y[addr], 15, 15, 0);
  if(z[addr]==6)
  LED(z[addr], x[addr], y[addr], 10, 10, 0);
   if(z[addr]==5)
  LED(z[addr], x[addr], y[addr], 15, 5, 0);
   if(z[addr]==4)
  LED(z[addr], x[addr], y[addr], 15, 2, 0); 
    if(z[addr]==3)
  LED(z[addr], x[addr], y[addr], 15, 1, 0);
    if(z[addr]==2)
  LED(z[addr], x[addr], y[addr], 15, 0, 0);
    if(z[addr]==1)
  LED(z[addr], x[addr], y[addr], 12, 0, 0);
    if(z[addr]<=0)
  LED(z[addr], x[addr], y[addr], 10, 0, 0);
}}//300

    else if(ledcolor>=300&&ledcolor<400){
    for(addr=0; addr<leds; addr++){
      //{{15, 0, 0},{15, 6, 0},{15, 15, 0},{9, 14, 0},{0, 15, 0},{0, 15, 15},{0, 0, 15},{6, 3, 15}}
    LED(zold[addr], xold[addr], yold[addr], 0, 0, 0);
    if(z[addr]>=7)
    LED(z[addr], x[addr], y[addr], 15, 0, 0);
    if(z[addr]==6)
    LED(z[addr], x[addr], y[addr], 15, 6, 0);
     if(z[addr]==5)
    LED(z[addr], x[addr], y[addr], 15, 15, 0);
     if(z[addr]==4)
    LED(z[addr], x[addr], y[addr], 9, 14, 0); 
      if(z[addr]==3)
    LED(z[addr], x[addr], y[addr], 0, 15, 0);
      if(z[addr]==2)
    LED(z[addr], x[addr], y[addr], 0, 15, 15);
      if(z[addr]==1)
    LED(z[addr], x[addr], y[addr], 0, 0, 15);
      if(z[addr]<=0)
    LED(z[addr], x[addr], y[addr], 6, 3, 15);
    }}
     if(ledcolor>=500&&ledcolor<600){

}
  
  
  ledcolor+= 3;
if(ledcolor>=400)
ledcolor=0;
  
    for(addr=0; addr<leds; addr++){
    xold[addr]=x[addr];
    yold[addr]=y[addr];
    zold[addr]=z[addr];
   } 
  
  
  delay(delayFactor);
  
  //for(addr=0; addr<leds; addr++)
  //LED(z[addr], x[addr], y[addr], 0, 0, 0);
    for(addr=0; addr<leds; addr++){
      
      //slowdown = random(2);
      //if(bitRead(z[addr],0))
  z[addr] = z[addr]-1;
  
 // x[addr] = x[addr]+1;
 // y[addr] = y[addr]+1;
  if(z[addr]<random(-100,0)){
    x[addr]=random(8);
    y[addr]=random(8);
    int select=random(3);
    if(select==0){
    xx[addr]=0;
    zz[addr]=random(16);
    yy[addr]=random(16);
    //zz[addr]=0;
    }
    if(select==1){
    xx[addr]=random(16);
    zz[addr]=0;
    yy[addr]=random(16);
    //yy[addr]=0;
    }
    if(select==2){
    xx[addr]=random(16);
    zz[addr]=random(16);
    yy[addr]=0;
    
    
    }    
   z[addr]=7; 
   
  }//-check
  }//add

  
  }//while
 clean();
}//rain

/* RUBIKS */
void rubiksCube() {
  //0 = right 1 = left 2 = front 3 = back 4 = top 5 =bottom faces
  int faceStickers[6][3][3];
  for (int i = 0; i < 6; i++){
    for (int j=0; j< 3; j++) {
       for (int k=0; k< 3; k++) {
      faceStickers[i][j][k] = i;
       }
    }
  }
  displayRubiksCube((int*)faceStickers);
  delay(2000);
  int newStickers[6][3][3];
  byte iterations = 18;
  int rotations[40];
  bool directions[40];
  for (int x = 0; x < 1; x++) {
    //iterations = random(20);
  int rotations[40];
  for (int i = 0; i < iterations; i++) {
    rotations[i] = random(6);
    directions[i] = random(1);
    rotateCube((int*)faceStickers, (int*) newStickers, rotations[i], directions[i]);
    for (int i=0; i< 6; i++) {
      for (int j = 0; j < 3;j++) {
        for (int k = 0; k < 3; k++) {
          faceStickers[i][j][k] = newStickers[i][j][k];
        }
      }
    }
    rubiksCleanup();
    displayRubiksCube((int*)newStickers);
  }
  for (int i = 0; i < iterations; i++) {
    rotateCube((int*)faceStickers, (int*) newStickers, rotations[iterations-1-i], !directions[iterations-1-i]);
    for (int i=0; i< 6; i++) {
      for (int j = 0; j < 3;j++) {
        for (int k = 0; k < 3; k++) {
          faceStickers[i][j][k] = newStickers[i][j][k];
        }
      }
    }
    rubiksCleanup();
    displayRubiksCube((int*)newStickers);
    //delay(1000);
  }
  delay(5000);
  }
  clean();
} //rubiks
/* END FUNCTIONS FOR RUBIKS */



void dancingCube() {
  clean();
  int iterations = 1 * pow(2,3);
  int numberOfPoints = sizeof(smallCube)/sizeof(smallCube[0]);
  float cube[numberOfPoints][4];
  float transformedCube[numberOfPoints][4];
  for (int runs = 0; runs < iterations; runs++) {
    byte R = random(16), G = random(16), B = random(16);
    CopyFloatMatrix((float*)smallCube, numberOfPoints, 4, (float*)cube);
    displayObject((float*) cube,numberOfPoints, R,G,B);
    delay(100*pow(2,6-6));
    int delayFactor = 50  *pow(2,6-6);
    for (int i = 0; i < dancingCubeTransformSteps; i++) {
      MultiplyFloatMatrixPROGMEM((float*)cube, (float*)dancingCubeTransforms[i], numberOfPoints, 4, 4, (float*)transformedCube);
      
      
      drawLines((float*)transformedCube, (int*)cubeAdjacency, numberOfPoints,R,G,B);
      drawLines((float*)cube, (int*)cubeAdjacency, numberOfPoints,0,0,0);
      CopyFloatMatrix((float*)transformedCube, numberOfPoints, 4, (float*)cube);
      delay(delayFactor);
    }
    clean();
  }
  clean();
}//dancingCube

/* TEXT ROUTINES TEXT ROUTINES TEXT ROUTINES TEXT ROUTINES TEXT ROUTINES TEXT ROUTINES */
void displayTextRoutine() {
  for (int i = 0; i < 3;i++) {
    displayScrollingRandomText();
    //displaySolidColoredText(messages[0],2000,1);
//    switch (settings[2]) {
//      case 0:
//      {
//        displayScrollingRandomText();
//        break;
//      }
//      case 1:
//      {
//        displayScrollingColoredText(messages[settings[1]-6],settings[3]);
//        break;
//      }
//      case 2:
//      {
//        displaySolidColoredText(messages[settings[1]-6],2000,settings[3]);
//        break;
//      }
//      case 3:
//      {
//        displayScrollingText(messages[settings[1]-6],random(16),random(16),random(16));
//        break;
//      }
//      case 4:
//      {
//        displaySolidText(messages[settings[1]-6],2000,random(16),random(16),random(16));
//        break;
//      }
//      default:
//      {
//        displayScrollingColoredText(messages[settings[1]-6],settings[3]);
//        break;
//      }
//    }
  }
  clean();
}

 /* END TEXT ROUTINES END TEXT ROUTINES END TEXT ROUTINES END TEXT ROUTINES END TEXT ROUTINES */

//DANCING SPHERE
void dancingSphere() {
  //clean();
  int lats = 4;
  int longs = lats;
  int delayFactor = 75;
  int iterations = 10;
  byte currentFrame[65];
  byte previousFrame[65];
  const int numberOfSphereAnimations = 4;
  void (*sphereAnimations[numberOfSphereAnimations])(byte*, byte*, int, int, int, byte, byte, byte) = {
    sphereAnimationShrinkAndGrowFrom1Corner, 
    sphereAnimationGrowAndShrinkFromCenter, 
    sphereAnimationGrowFrom2Corners,
    sphereAnimationGrowAndShrinkFrom4Corners};
    //sphereAnimationHugeSphereMoving};
  for (int runs = 0; runs < iterations; runs++) {
    int loops = random(1,4);
    int animation = random(0,numberOfSphereAnimations);
    #ifdef DEBUG2
      Serial.print("In dancing Sphere on run ");
      Serial.print(runs);
      Serial.print(" running animation ");
      Serial.print(animation);
      Serial.print(" ");
      Serial.print(loops);
      Serial.println(" times.");
    #endif
    for (int i = 0; i < loops; i++) {
        byte R = random(16), G = random(16), B = random(16);
       (*sphereAnimations[animation])((byte*)currentFrame,(byte*)previousFrame, delayFactor, lats, longs, R, G, B);
    }
  }
  clean();
}

//cameForTheLo

void cameForTheLo() {
  int iterations = 10;
  int delayFactor = 100;
  for (int runs = 0; runs < iterations; runs++) { 
    makeCube(0,0,0,random(7),random(16),random(16));
    makeCube(4,4,4,random(7),random (16),random(16));
    delay(delayFactor);
    
    
    
    for(int i=0;i<=3;i++){
      moveCube(i,0,0,random(7),random(16),random(16),true,0);
      moveCube(4-i,4,4,random(7),random(16),random(16),false,0);
      delay(delayFactor);
    }
    //for(int i=4;i>=1;i--){
    //  moveCube(i,0,0,random(7),random(16),random(16),false,0);
    //  delay(random(lowerBound,upperBound));
    //}
    for(int i=0;i<=3;i++){
      moveCube(4,i,0,random(7),random(16),random(16),true,1);
      moveCube(0,4-i,4,random(7),random(16),random(16),false,1);
      delay(delayFactor);
      
    }
    for(int i=0;i<=3;i++){
      moveCube(4,4,i,random(7),random(16),random(16),true,2);
      moveCube(0,0,4-i,random(7),random(16),random(16),false,2);
      delay(delayFactor);
    }
    
    for(int i=0;i<=3;i++){
      extendCube(i,0,0,random(7),random(16),random(16),true,0);
      extendCube(4-i,4,4,random(7),random(16),random(16),false,0);
      delay(delayFactor);
    }
    
    for(int i=0;i<=3;i++){
      moveCube(4,i,0,random(7),random(16),random(16),true,1);
      moveCube(4,4-i,4,random(7),random(16),random(16),false,1);
      delay(delayFactor);
    }
    
    for(int i=0;i<=3;i++){
      moveCube(i,0,0,random(7),random(16),random(16),true,0);
      moveCube(i,4,4,random(7),random(16),random(16),true,0);
      moveCube(4-i,4,0,random(7),random(16),random(16),false,0);
      moveCube(4-i,0,4,random(7),random(16),random(16),false,0);
      delay(delayFactor);
    }
    
    for(int i=0;i<=3;i++){
      moveCube(4,i,0,random(7),random(16),random(16),true,1);
      moveCube(4,4-i,4,random(7),random(16),random(16),false,1);
      moveCube(0,4,i,random(7),random(16),random(16),true,2);
      moveCube(0,0,4-i,random(7),random(16),random(16),false,2);
      delay(delayFactor);
    }
    
    for(int i=0;i<=3;i++){
      moveCube(i,0,0,random(7),random(16),random(16),true,0);
      moveCube(i,4,4,random(7),random(16),random(16),true,0);
      moveCube(4-i,4,0,random(7),random(16),random(16),false,0);
      moveCube(4-i,0,4,random(7),random(16),random(16),false,0);
      delay(delayFactor);
    }
    
    for(int i=0;i<=3;i++){
      moveCube(4,i,0,random(7),random(16),random(16),true,1);
      moveCube(4,4-i,4,random(7),random(16),random(16),false,1);
      moveCube(0,4,i,random(7),random(16),random(16),true,2);
      moveCube(0,0,4-i,random(7),random(16),random(16),false,2);
      delay(delayFactor);
    }
    
    for(int i=0;i<=3;i++){
      moveCube(i,0,0,random(7),random(16),random(16),true,0);
      moveCube(i,4,4,random(7),random(16),random(16),true,0);
      moveCube(4-i,4,0,random(7),random(16),random(16),false,0);
      moveCube(4-i,0,4,random(7),random(16),random(16),false,0);
      delay(delayFactor);
    }
    
    for(int i=0;i<=3;i++){
      moveCube(4,i,0,random(7),random(16),random(16),true,1);
      moveCube(4,4-i,4,random(7),random(16),random(16),false,1);
      moveCube(0,4,i,random(7),random(16),random(16),true,2);
      moveCube(0,0,4-i,random(7),random(16),random(16),false,2);
      delay(delayFactor);
    }
    
    
    for(int i=0;i<=3;i++){
      moveCube(4-i,0,4,random(7),random(16),random(16),false,0);
      moveCube(i,4,4,random(7),random(16),random(16),true,0);
      delay(delayFactor);
    }
    
    for(int i=0;i<=3;i++){
      moveCube(0,0,4-i,random(7),random(16),random(16),false,2);
      moveCube(4,4,i,random(7),random(16),random(16),true,2);
      delay(delayFactor);
    }
  }
}

