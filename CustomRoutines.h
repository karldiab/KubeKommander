void LED(int z, int x, int y, byte R, byte G, byte B);
void LEDTruncate(int z, int x, int y, byte R, byte G, byte B);
void LEDNo(int LEDNumber, byte R, byte G, byte B);
unsigned int getLEDNumber(unsigned int z, unsigned int x, unsigned int y);
void clean();
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

/* FUNCTIONS TO DISPLAY RUBIKS */
void rubiksCleanup();
void displayRubiksCube(int* faceStickers);
void rotateCube(int* oldPositions, int* newPositions, int sideToRotate, bool CW);
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
}//dancingCube

/* TEXT ROUTINES TEXT ROUTINES TEXT ROUTINES TEXT ROUTINES TEXT ROUTINES TEXT ROUTINES */
void displaySingleChar(char c, int delayms,int R, int G, int B);
void displaySolidColoredText(String s, int delayms, int colorSet);
void displayScrollingText(String s,int R, int G, int B);
void displayScrollingColoredText(String s,int colorSet);
void displayScrollingRandomText();
void displaySolidLetter(char c,int R, int G, int B);
 void displaySolidColoredLetter(char c,int colorSet);
void displayScrollingLetter(char c, int R, int G, int B);
void displayScrollingColoredLetter(char c, int colorSet);
void displaySolidText(String s, int delayms,int R, int G, int B);
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
 /* END TEXT ROUTINES END TEXT ROUTINES END TEXT ROUTINES END TEXT ROUTINES END TEXT ROUTINES */

//DANCING SPHERE
void dancingSphere() {
  //clean();
  int lats = 4;
  int longs = lats;
  int delayFactor = 60;
  int iterations = 20;
  byte currentFrame[65];
  byte previousFrame[65];
  const int numberOfSphereAnimations = 4;
  void (*sphereAnimations[numberOfSphereAnimations])(byte*, byte*, int, int, int, byte, byte, byte) = {
    sphereAnimationShrinkAndGrowFrom1Corner, 
    sphereAnimationGrowAndShrinkFromCenter, 
    sphereAnimationGrowFrom2Corners,
    sphereAnimationGrowAndShrinkFrom4Corners};
  for (int runs = 0; runs < iterations; runs++) {
    int loops = random(1,2);
    int animation = random(0,numberOfSphereAnimations);
    #ifdef DEBUG
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
  
}
