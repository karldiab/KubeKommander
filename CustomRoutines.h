void LED(int z, int x, int y, byte R, byte G, byte B);
void LEDNo(int LEDNumber, byte R, byte G, byte B);
void clean();

//void spirals() {
//  int delayFactor = 3;
//  int iterationSeed = 2;
//  int iterations = iterationSeed;
//  for (int runNumber = 0; runNumber < iterations; runNumber++) {
//    int colorSet = random(numberOfColorSets);
//    //LED(Y,X,Z,R,G,B);
//    //start by making all faces light up by spiraling in from the outside. Each run through this has a color set chosen randomly (colorSet) which is a random index for the array of color sets, each set has 8 colors
//    //I created above (colorSets array). Each LED's color depends on it's y position. eg if the rainbow color set is chosen, all bottom LEDS will be red, then the next ones up will be orange, etc. till we get to purple up top
//    for (int i = 0; i < 8; i++) {//start outer square
//      LED(0,i,0,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));//front face
//      LED(0,i,7,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));//back face
//      LED(0,0,i,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));//left face
//      LED(0,7,i,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));//right face
//      delay(delayFactor);
//    }
//    for (int i = 1; i < 8; i++) {
//      LED(i,7,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,7,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,0,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,7,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      delay(delayFactor);
//    }
//    for (int i = 6; i >= 1; i--) {
//      LED(7,i,0,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//      LED(7,i,7,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//      LED(7,0,i,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//      LED(7,7,i,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//      delay(delayFactor);
//    }
//    for (int i = 7; i >= 1; i--) {//end outer square
//      LED(i,0,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,0,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,0,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,7,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      delay(delayFactor);
//    }
//    for (int i = 1; i < 7; i++) {//start first inner square
//      LED(1,i,0,pgm_read_word_near(&colorSets[colorSet][1][0]),pgm_read_word_near(&colorSets[colorSet][1][1]),pgm_read_word_near(&colorSets[colorSet][1][2]));//front face
//      LED(1,i,7,pgm_read_word_near(&colorSets[colorSet][1][0]),pgm_read_word_near(&colorSets[colorSet][1][1]),pgm_read_word_near(&colorSets[colorSet][1][2]));//back face
//      LED(1,0,i,pgm_read_word_near(&colorSets[colorSet][1][0]),pgm_read_word_near(&colorSets[colorSet][1][1]),pgm_read_word_near(&colorSets[colorSet][1][2]));//left face
//      LED(1,7,i,pgm_read_word_near(&colorSets[colorSet][1][0]),pgm_read_word_near(&colorSets[colorSet][1][1]),pgm_read_word_near(&colorSets[colorSet][1][2]));//right face
//      LED(0,i,1,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));//bottom face
//      LED(7,i,1,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));//top face
//      delay(delayFactor);
//    }
//    for (int i = 1; i < 7; i++) {
//      LED(i,6,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,6,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,0,6,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,7,6,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(0,6,i,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
//      LED(7,6,i,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//      delay(delayFactor);
//    }
//    for (int i = 6; i > 1; i--) {
//      LED(6,i,0,pgm_read_word_near(&colorSets[colorSet][6][0]),pgm_read_word_near(&colorSets[colorSet][6][1]),pgm_read_word_near(&colorSets[colorSet][6][2]));
//      LED(6,i,7,pgm_read_word_near(&colorSets[colorSet][6][0]),pgm_read_word_near(&colorSets[colorSet][6][1]),pgm_read_word_near(&colorSets[colorSet][6][2]));
//      LED(6,0,i,pgm_read_word_near(&colorSets[colorSet][6][0]),pgm_read_word_near(&colorSets[colorSet][6][1]),pgm_read_word_near(&colorSets[colorSet][6][2]));
//      LED(6,7,i,pgm_read_word_near(&colorSets[colorSet][6][0]),pgm_read_word_near(&colorSets[colorSet][6][1]),pgm_read_word_near(&colorSets[colorSet][6][2]));
//      LED(0,i,6,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
//      LED(7,i,6,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//      delay(delayFactor);
//    }
//    for (int i = 6; i > 1; i--) {//end first inner square
//      LED(i,1,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,1,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,0,1,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,7,1,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(0,1,i,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
//      LED(7,1,i,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//      delay(delayFactor);
//    }
//    for (int i = 2; i < 6; i++) {//start second inner square
//      LED(2,i,0,pgm_read_word_near(&colorSets[colorSet][2][0]),pgm_read_word_near(&colorSets[colorSet][2][1]),pgm_read_word_near(&colorSets[colorSet][2][2]));
//      LED(2,i,7,pgm_read_word_near(&colorSets[colorSet][2][0]),pgm_read_word_near(&colorSets[colorSet][2][1]),pgm_read_word_near(&colorSets[colorSet][2][2]));
//      LED(2,0,i,pgm_read_word_near(&colorSets[colorSet][2][0]),pgm_read_word_near(&colorSets[colorSet][2][1]),pgm_read_word_near(&colorSets[colorSet][2][2]));
//      LED(2,7,i,pgm_read_word_near(&colorSets[colorSet][2][0]),pgm_read_word_near(&colorSets[colorSet][2][1]),pgm_read_word_near(&colorSets[colorSet][2][2]));  
//      LED(0,i,2,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
//      LED(7,i,2,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));  
//      delay(delayFactor);
//    }
//    for (int i = 2; i < 6; i++) {
//      LED(i,5,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,5,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,0,5,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,7,5,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(0,5,i,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
//      LED(7,5,i,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//      delay(delayFactor);
//    }
//    for (int i = 5; i > 2; i--) {
//      LED(5,i,0,pgm_read_word_near(&colorSets[colorSet][5][0]),pgm_read_word_near(&colorSets[colorSet][5][1]),pgm_read_word_near(&colorSets[colorSet][5][2]));
//      LED(5,i,7,pgm_read_word_near(&colorSets[colorSet][5][0]),pgm_read_word_near(&colorSets[colorSet][5][1]),pgm_read_word_near(&colorSets[colorSet][5][2]));
//      LED(5,0,i,pgm_read_word_near(&colorSets[colorSet][5][0]),pgm_read_word_near(&colorSets[colorSet][5][1]),pgm_read_word_near(&colorSets[colorSet][5][2]));
//      LED(5,7,i,pgm_read_word_near(&colorSets[colorSet][5][0]),pgm_read_word_near(&colorSets[colorSet][5][1]),pgm_read_word_near(&colorSets[colorSet][5][2]));
//      LED(0,i,5,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
//      LED(7,i,5,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//      delay(delayFactor);
//    }
//    for (int i = 5; i > 2; i--) {//end second inner square
//      LED(i,2,0,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,2,7,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,0,2,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(i,7,2,pgm_read_word_near(&colorSets[colorSet][i][0]),pgm_read_word_near(&colorSets[colorSet][i][1]),pgm_read_word_near(&colorSets[colorSet][i][2]));
//      LED(0,2,i,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
//      LED(7,2,i,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//      delay(delayFactor);
//    }
//    LED(3,3,0,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));//start third inner square
//    LED(3,3,7,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
//    LED(3,0,3,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
//    LED(3,7,3,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
//    LED(0,3,3,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
//    LED(7,3,3,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//    delay(delayFactor);
//    LED(3,4,0,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
//    LED(3,4,7,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
//    LED(3,0,4,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
//    LED(3,7,4,pgm_read_word_near(&colorSets[colorSet][3][0]),pgm_read_word_near(&colorSets[colorSet][3][1]),pgm_read_word_near(&colorSets[colorSet][3][2]));
//    LED(0,4,3,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
//    LED(7,4,3,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//    delay(delayFactor);
//    LED(4,4,0,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
//    LED(4,4,7,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
//    LED(4,0,4,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
//    LED(4,7,4,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
//    LED(0,4,4,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
//    LED(7,4,4,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));
//    
//    delay(delayFactor);
//    LED(4,3,0,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
//    LED(4,3,7,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
//    LED(4,0,3,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
//    LED(4,7,3,pgm_read_word_near(&colorSets[colorSet][4][0]),pgm_read_word_near(&colorSets[colorSet][4][1]),pgm_read_word_near(&colorSets[colorSet][4][2]));
//    LED(0,3,4,pgm_read_word_near(&colorSets[colorSet][0][0]),pgm_read_word_near(&colorSets[colorSet][0][1]),pgm_read_word_near(&colorSets[colorSet][0][2]));
//    LED(7,3,4,pgm_read_word_near(&colorSets[colorSet][7][0]),pgm_read_word_near(&colorSets[colorSet][7][1]),pgm_read_word_near(&colorSets[colorSet][7][2]));//end third inner square
//    delay(delayFactor);
//    //Cool beans, now do the spiral thing again in reverse but change LED colors to 0,0,0 to turn them off. This will make the spiral undo itself from the inside
//    LED(4,3,0,0,0,0);
//    LED(4,3,7,0,0,0);
//    LED(4,0,3,0,0,0);
//    LED(4,7,3,0,0,0);
//    LED(0,3,4,0,0,0);
//    LED(7,3,4,0,0,0);
//    delay(delayFactor);
//    LED(4,4,0,0,0,0);
//    LED(4,4,7,0,0,0);
//    LED(4,0,4,0,0,0);
//    LED(4,7,4,0,0,0);
//    LED(0,4,4,0,0,0);
//    LED(7,4,4,0,0,0);
//    delay(delayFactor);
//    LED(3,4,0,0,0,0);
//    LED(3,4,7,0,0,0);
//    LED(3,0,4,0,0,0);
//    LED(3,7,4,0,0,0);
//    LED(0,4,3,0,0,0);
//    LED(7,4,3,0,0,0);
//    delay(delayFactor);
//    LED(3,3,0,0,0,0);
//    LED(3,3,7,0,0,0);
//    LED(3,0,3,0,0,0);
//    LED(3,7,3,0,0,0);
//    LED(0,3,3,0,0,0);
//    LED(7,3,3,0,0,0);
//    delay(delayFactor);
//    for (int i = 3; i <= 5; i++) {
//      LED(i,2,0,0,0,0);
//      LED(i,2,7,0,0,0);
//      LED(i,0,2,0,0,0);
//      LED(i,7,2,0,0,0);
//      LED(0,2,i,0,0,0);
//      LED(7,2,i,0,0,0);
//      delay(delayFactor);
//    }
//    for (int i = 2; i <= 5; i++) {
//      LED(5,i,0,0,0,0);
//      LED(5,i,7,0,0,0);
//      LED(5,0,i,0,0,0);
//      LED(5,7,i,0,0,0);
//      LED(0,i,5,0,0,0);
//      LED(7,i,5,0,0,0);
//      delay(delayFactor);
//    }
//    for (int i = 5; i > 2; i--) {
//      LED(i,5,0,0,0,0);
//      LED(i,5,7,0,0,0);
//      LED(i,0,5,0,0,0);
//      LED(i,7,5,0,0,0);
//      LED(0,5,i,0,0,0);
//      LED(7,5,i,0,0,0);
//      delay(delayFactor);
//    }
//    for (int i = 5; i > 1; i--) {
//      LED(2,i,0,0,0,0);
//      LED(2,i,7,0,0,0);
//      LED(2,0,i,0,0,0);
//      LED(2,7,i,0,0,0);  
//      LED(0,i,2,0,0,0);
//      LED(7,i,2,0,0,0);  
//      delay(delayFactor);
//    }
//    for (int i = 2; i <= 5; i++) {
//      LED(i,1,0,0,0,0);
//      LED(i,1,7,0,0,0);
//      LED(i,0,1,0,0,0);
//      LED(i,7,1,0,0,0);
//      LED(0,1,i,0,0,0);
//      LED(7,1,i,0,0,0);
//      delay(delayFactor);
//    }
//      for (int i = 1; i <= 5; i++) {
//      LED(6,i,0,0,0,0);
//      LED(6,i,7,0,0,0);
//      LED(6,0,i,0,0,0);
//      LED(6,7,i,0,0,0);
//      LED(0,i,6,0,0,0);
//      LED(7,i,6,0,0,0);
//      delay(delayFactor);
//    }
//      for (int i = 7; i > 1; i--) {//d
//      LED(i,6,0,0,0,0);
//      LED(i,6,7,0,0,0);
//      LED(i,0,6,0,0,0);
//      LED(i,7,6,0,0,0);
//      LED(0,6,i,0,0,0);
//      LED(7,6,i,0,0,0);
//      delay(delayFactor);
//    }
//     for (int i = 6; i > 0; i--) {//d
//      LED(1,i,0,0,0,0);
//      LED(1,i,7,0,0,0);
//      LED(1,0,i,0,0,0);
//      LED(1,7,i,0,0,0);
//      LED(0,i,1,0,0,0);
//      LED(7,i,1,0,0,0);
//      delay(delayFactor);
//    }
//      for (int i = 1; i <= 7; i++) {
//      LED(i,0,0,0,0,0);
//      LED(i,0,7,0,0,0);
//      LED(i,0,0,0,0,0);
//      LED(i,7,7,0,0,0);
//      delay(delayFactor);
//    }
//      for (int i = 1; i <= 7; i++) {
//      LED(7,i,0,0,0,0);
//      LED(7,i,7,0,0,0);
//      LED(7,0,i,0,0,0);
//      LED(7,7,i,0,0,0);
//      delay(delayFactor);
//    }
//      for (int i = 7; i > 0; i--) {
//      LED(i,7,0,0,0,0);
//      LED(i,7,7,0,0,0);
//      LED(i,0,7,0,0,0);
//      LED(i,7,7,0,0,0);
//      delay(delayFactor);
//    }
//      for (int i = 7; i > 0; i--) {
//      LED(0,i,0,0,0,0);
//      LED(0,i,7,0,0,0);
//      LED(0,0,i,0,0,0);
//      LED(0,7,i,0,0,0);
//      delay(delayFactor);
//    }
//  }
//}

//void tesseract() { 
//  clean();
//  bool firstRun = true;
//  byte startingColor[3];
//  byte oldStartingColor[3];
//  int duration = 4;
//  for (int runs = 0; runs < duration; runs++) {
//    //0 = y 1 = x 2 = z
//    byte colorShiftDirection = random(3);
//    byte colorSet = random(numberOfColorSets);
//    bool colorDirection = random(1);
//    startingColor[0] = pgm_read_word_near(&colorSets[colorSet][colorDirection? 7 : 0][0]);
//    startingColor[1] = pgm_read_word_near(&colorSets[colorSet][colorDirection? 7 : 0][1]);
//    startingColor[2] = pgm_read_word_near(&colorSets[colorSet][colorDirection? 7 : 0][2]);
//    if (!firstRun) {
//      for (int frame = 0; frame < 6; frame++) {
//        int R = map(frame,0,6,oldStartingColor[0],startingColor[0]);
//        int G = map(frame,0,6,oldStartingColor[1],startingColor[1]);
//        int B = map(frame,0,6,oldStartingColor[2],startingColor[2]);
//        for (int i = 0; i < 120; i++) {
//            LED(pgm_read_byte_near(&tesseractPoints[i][0]),pgm_read_byte_near(&tesseractPoints[i][1]),pgm_read_byte_near(&tesseractPoints[i][2]),R,G,B);
//        }
//        delay(150);
//      }
//    } else {
//      for (int i = 0; i < 120; i++) {
//          LED(pgm_read_byte_near(&tesseractPoints[i][0]),pgm_read_byte_near(&tesseractPoints[i][1]),pgm_read_byte_near(&tesseractPoints[i][2]),startingColor[0],startingColor[1],startingColor[2]);
//      }
//    }
//    firstRun = false;
//    int yShift;
//    delay(150*random(1,4));
//    for (int frame = 7; frame > -8; frame--) {
//      for (int i = 0; i < 120; i++) {
//        int xyzPosition = pgm_read_byte_near(&tesseractPoints[i][colorShiftDirection]);
//        if (colorDirection) {
//          yShift = xyzPosition + frame > 7 ? 7 : xyzPosition + frame;
//        } else {
//          yShift = xyzPosition - frame > 7 ? 7 : xyzPosition - frame;
//        }
//          yShift = yShift < 0 ? 0 : yShift;
//          LED(pgm_read_byte_near(&tesseractPoints[i][0]),pgm_read_byte_near(&tesseractPoints[i][1]),pgm_read_byte_near(&tesseractPoints[i][2]),pgm_read_word_near(&colorSets[colorSet][yShift][0]),pgm_read_word_near(&colorSets[colorSet][yShift][1]),pgm_read_word_near(&colorSets[colorSet][yShift][2]));
//      }
//      delay(150);
//      if (frame == -7) {
//        startingColor[0] = pgm_read_word_near(&colorSets[colorSet][yShift][0]);
//        startingColor[1] = pgm_read_word_near(&colorSets[colorSet][yShift][1]);
//        startingColor[2] = pgm_read_word_near(&colorSets[colorSet][yShift][2]);
//      }
//    }
//    delay(150*random(1,4));
//    oldStartingColor[0] = startingColor[0];
//    oldStartingColor[1] = startingColor[1];
//    oldStartingColor[2] = startingColor[2];
//    if (random(1000) < 30) {
//      for (int runs = 0; runs < 300; runs++) {
//        for (int i = 0; i < 120; i++) {
//            LED(pgm_read_byte_near(&tesseractPoints[i][0]),pgm_read_byte_near(&tesseractPoints[i][1]),pgm_read_byte_near(&tesseractPoints[i][2]),random(13),random(16),random(16));
//        }
//      }
//    }
//  }
//} //tesserect

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
