#include "ASCIICharsin8x8.h"


//GENERAL
#define numberOfColorSets 5
const int colorSets[numberOfColorSets][8][3] PROGMEM = {
  {{0, 5, 15},{0, 1, 9},{0, 0, 10},{1, 0, 11},{3, 0, 12},{10, 0, 15},{10, 0, 10},{10, 0, 1}},
  {{15, 15, 0},{10, 10, 0},{15, 5, 0},{15, 2, 0},{15, 1, 0},{15, 0, 0},{12, 0, 0},{10, 0, 0}},
  {{15, 0, 0},{15, 6, 0},{15, 15, 0},{9, 14, 0},{0, 15, 0},{0, 15, 15},{0, 0, 15},{6, 3, 15}},//rainbow
  {{6, 3, 15},{4, 3, 15},{1, 3, 15},{0, 0, 15},{1, 2, 12},{7, 1, 9},{10, 0, 7},{15, 0, 0}},//purple to blue to red
  {{0, 15, 0},{1, 12, 2},{2, 11, 7},{3, 9, 10},{4, 7, 11},{5, 5, 13},{6, 4, 14},{6, 3, 15}}//green to purple
 };
 //END GENERAL
//FOR TESSERECT
 const byte tesseractPoints[120][3] PROGMEM = {
  {0,0,0},{0,0,1},{0,0,2},{0,0,3},{0,0,4},{0,0,5},{0,0,6},{0,0,7},
  {0,1,0},{0,2,0},{0,3,0},{0,4,0},{0,5,0},{0,6,0},{0,7,0},
  {1,0,0},{2,0,0},{3,0,0},{4,0,0},{5,0,0},{6,0,0},{7,0,0},
  {7,7,7},{7,7,6},{7,7,5},{7,7,4},{7,7,3},{7,7,2},{7,7,1},{7,7,0},
  {7,6,7},{7,5,7},{7,4,7},{7,3,7},{7,2,7},{7,1,7},{7,0,7},
  {6,7,7},{5,7,7},{4,7,7},{3,7,7},{2,7,7},{1,7,7},{0,7,7},
  {1,0,7},{2,0,7},{3,0,7},{4,0,7},{5,0,7},{6,0,7},
  {1,7,0},{2,7,0},{3,7,0},{4,7,0},{5,7,0},{6,7,0},
  {7,1,0},{7,2,0},{7,3,0},{7,4,0},{7,5,0},{7,6,0},
  {7,0,1},{7,0,2},{7,0,3},{7,0,4},{7,0,5},{7,0,6},
  {0,1,7},{0,2,7},{0,3,7},{0,4,7},{0,5,7},{0,6,7},
  {0,7,1},{0,7,2},{0,7,3},{0,7,4},{0,7,5},{0,7,6},
  {2,2,2},{2,3,2},{2,4,2},{2,5,2},
  {3,2,2},{4,2,2},{5,2,2},
  {2,2,3},{2,2,4},{2,2,5},
  {5,5,5},{4,5,5},{3,5,5},{2,5,5},
  {5,4,5},{5,3,5},{5,2,5},
  {5,5,4},{5,5,3},{5,5,2},
  {2,5,4},{2,5,3},
  {2,4,5},{2,3,5},
  {5,2,4},{5,2,3},
  {5,3,2},{5,4,2},
  {3,2,5},{4,2,5},
  {3,5,2},{4,5,2},
  {1,1,1},{1,6,1},{1,6,6},{1,1,6},{6,1,1},{6,6,1},{6,6,6},{6,1,6}
};
//END TESSERECT DATA

//FOR RUBIKS
byte colorTranslator[6][3] = {{7,15,0},{8,15,15},{10,4,0},{0,0,15},{0,15,0},{15,0,0}};
//0 = right 1 = left 2 = front 3 = back 4 = top 5 =bottom faces
  int sideDisplayTransforms[6][4][4] = {
    {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,0,1}},
    {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,7,1}},
    {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}},
    {{1,0,0,0},{0,-1,0,0},{0,0,-1,0},{0,7,7,1}},
    {{0,0,1,0},{0,1,0,0},{-1,0,0,0},{7,0,0,1}},
    {{0,0,-1,0},{0,1,0,0},{1,0,0,0},{0,0,7,1}}
  };
  //row.position.LEDNo.xyz
  int stickerLEDPositions[3][3][4][4] = {
    {
      {{6,1,0,1},{6,2,0,1},{5,1,0,1},{5,2,0,1}},
      {{6,3,0,1},{6,4,0,1},{5,3,0,1},{5,4,0,1}},
      {{6,5,0,1},{6,6,0,1},{5,5,0,1},{5,6,0,1}}
    },
    {
      {{4,1,0,1},{4,2,0,1},{3,1,0,1},{3,2,0,1}},
      {{4,3,0,1},{4,4,0,1},{3,3,0,1},{3,4,0,1}},
      {{4,5,0,1},{4,6,0,1},{3,5,0,1},{3,6,0,1}}
    },
    {
      {{2,1,0,1},{2,2,0,1},{1,1,0,1},{1,2,0,1}},
      {{2,3,0,1},{2,4,0,1},{1,3,0,1},{1,4,0,1}},
      {{2,5,0,1},{2,6,0,1},{1,5,0,1},{1,6,0,1}}
    }
  };
  //0 = right 1 = left 2 = front 3 = back 4 = top 5 =bottom faces
  byte originalStickersIndex[6][21] = {
    {0,1,2,3,4,5,6,7,8,20,23,26,27,30,33,38,41,44,47,50,53},
    {9,10,11,12,13,14,15,16,17,18,21,24,29,32,35,36,39,42,45,48,51},
    {18,19,20,21,22,23,24,25,26,0,3,6,11,14,17,42,43,44,45,46,47},
    {27,28,29,30,31,32,33,34,35,2,5,8,9,12,15,36,37,38,51,52,53},
    {36,37,38,39,40,41,42,43,44,18,19,20,27,28,29,0,1,2,9,10,11},
    {45,46,47,48,49,50,51,52,53,6,7,8,15,16,17,24,25,26,33,34,35}
  };
  //indexes to swap with if CW
  const byte swapIndex[6][21] PROGMEM = {
    {6,3,0,7,4,1,8,5,2,47,50,53,38,41,44,20,23,26,27,30,33},
    {15,12,9,16,13,10,17,14,11,36,39,42,45,48,51,29,32,35,18,21,24},
    {24,21,18,25,22,19,26,23,20,42,43,44,45,46,47,11,14,17,0,3,6},
    {33,30,27,34,31,28,35,32,29,51,52,53,36,37,38,2,5,8,9,12,15},
    {42,39,36,43,40,37,44,41,38,0,1,2,9,10,11,27,28,29,18,19,20},
    {51,48,45,52,49,46,53,50,47,24,25,26,33,34,35,15,16,17,6,7,8}
  };
//rotation matrixes for rubiks animations spining CW
//0 = right 1 = left 2 = front 3 = back 4 = top 5 =bottom faces
const float rubiksRotations[6][3][4][4] PROGMEM = {
{
  {{0.923879532,0,0.382683432,0},{0,1,0,0},{-0.382683432,0,0.923879532,0},{1.605813,0,-1.07297,1}},
  {{0.707106781,0,0.707106781,0},{0,1,0,0},{-0.707106781,0,0.707106781,0},{3.5,0,0,1}},
  {{0.382683432,0,0.9238795325,0},{0,1,0,0},{-0.9238795325,0,0.382683432,0},{5.394187,0,-1.07297,1}}
},
{
  {{0.923879532,0,-0.382683432,0},{0,1,0,0},{0.382683432,0,0.923879532,0},{-1.07297,0,1.605813,1}},
  {{0.707106781,0,-0.707106781,0},{0,1,0,0},{0.707106781,0,0.707106781,0},{0,0,3.5,1}},
  {{0.382683432,0,-0.9238795325,0},{0,1,0,0},{0.9238795325,0,0.382683432,0},{-1.07297,0,5.394187,1}}
},
{
  {{0.923879532,0.382683432,0,0},{-0.382683432,0.923879532,0,0},{0,0,1,0},{1.605813,-1.07297,0,1}},
  {{0.707106781,0.707106781,0,0},{-0.707106781,0.707106781,0,0},{0,0,1,0},{3.5,-1.44975,0,1}},
  {{0.382683432,0.9238795325,0,0},{-0.9238795325,0.382683432,0,0},{0,0,1,0},{5.394187,-1.07297,0,1}}
},
{
  {{0.923879532,-0.382683432,0,0},{0.382683432,0.923879532,0,0},{0,0,1,0},{-1.07297,1.605813,0,1}},
  {{0.707106781,-0.707106781,0,0},{0.707106781,0.707106781,0,0},{0,0,1,0},{-1.44975,3.5,0,1}},
  {{0.382683432,-0.9238795325,0,0},{0.9238795325,0.382683432,0,0},{0,0,1,0},{-1.07297,5.394187,0,1}}
},
{
  {{1,0,0,0},{0,0.923879532,-0.382683432,0},{0,0.382683432,0.923879532},{0,-1.07297,1.605813,1}},
  {{1,0,0,0},{0,0.707106781,-0.707106781,0},{0,0.707106781,0.707106781},{0,-1.44975,3.5,1}},
  {{1,0,0,0},{0,0.382683432,-0.9238795325,0},{0,0.9238795325,0.382683432},{0,-1.07297,5.394187,1}}
},
{
  {{1,0,0,0},{0,0.923879532,0.382683432,0},{0,-0.382683432,0.923879532},{0,1.605813,-1.07297,1}},
  {{1,0,0,0},{0,0.707106781,0.707106781,0},{0,-0.707106781,0.707106781},{0,3.5,-1.44975,1}},
  {{1,0,0,0},{0,0.382683432,0.9238795325,0},{0,-0.9238795325,0.382683432},{0,5.394187,-1.07297,1}}
}
};

//END RUBIKS

//dancingCube
float smallCube[8][4] = {
    {3,3,3,1},
    {3,3,4,1},
    {3,4,3,1},
    {4,3,3,1},
    {4,4,4,1},
    {3,4,4,1},
    {4,3,4,1},
    {4,4,3,1}

  };
int cubeAdjacency[8][8] = {
    {0,1,1,1,0,0,0,0},
    {1,0,0,0,0,1,1,0},
    {1,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,1,1},
    {0,0,0,0,0,1,1,1},
    {0,1,1,0,1,0,0,0},
    {0,1,0,1,1,0,0,0},
    {0,0,1,1,1,0,0,0}
};
#define dancingCubeTransformSteps 5
const float dancingCubeTransforms[dancingCubeTransformSteps][4][4] PROGMEM = {
 {
    {3,0,0,0},
    {0,3,0,0},
    {0,0,3,0},
    {-7,-7,-7,1},
  },
  {
    {1.7,0,0,0},
    {0,1.7,0,0},
    {0,0,1.7,0},
    {-2,-2,-2,1}
  },
  {
    {1.3,0,0,0},
    {0,1.3,0,0},
    {0,0,1.3,0},
    {-1,-1,-1,1}
  },
  {
    {0.769,0,0,0},
    {0,0.769,0,0},
    {0,0,0.769,0},
    {1,1,1,1}
  },
  {
    {0.588,0,0,0},
    {0,0.588,0,0},
    {0,0,0.588,0},
    {2,2,2,1}
  }
// {
//    {0.333,0,0,0},
//    {0,0.333,0,0},
//    {0,0,0.333,0},
//    {3,3,3,1},
//  }
  };
int identityMatrix[4][4] = {
  {1,0,0,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,0,0,1}
};
//end dancingCube

//Text Routines Text Routines Text Routines Text Routines Text Routines Text Routines 

//#define numberOfMessages 4
//String messages[numberOfMessages] = {"?","X","!","CUBE"};
#define numberOfMessages 1
String messages[numberOfMessages] = {"BRENT"};
//Object transform variables
#define scrollingTextTransformSteps 14
byte scrollingTestStepsTillCleared = 8;
byte scrollingTextTransformObjects = 4;
int scrollingTextTransform[4][scrollingTextTransformSteps][4][4] = 
      {
        {
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,6,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,5,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,4,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,3,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,2,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,1,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,-1,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,-2,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,-3,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,-4,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,-5,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,-6,0,1}},
          {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,-7,0,1}}
        },
        {
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,1,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,2,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,3,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,4,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,5,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,6,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,7,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,8,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,9,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,10,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,11,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,12,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,13,1}},
          {{1,0,0,0},{0,0,-1,0},{0,1,0,0},{0,0,14,1}}
        },
        {
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,6,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,5,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,4,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,3,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,2,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,1,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,0,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,-1,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,-2,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,-3,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,-4,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,-5,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,-6,1}},
          {{1,0,0,0},{0,0,1,0},{0,-1,0,0},{0,7,-7,1}}
        },
        {
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,1,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,2,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,3,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,4,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,5,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,6,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,7,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,8,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,9,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,10,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,11,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,12,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,13,7,1}},
          {{1,0,0,0},{0,-1,0,0},{0,0,1,0},{0,14,7,1}}
        }
      };

//END Text Routines END Text Routines END Text Routines END Text Routines END Text Routines END Text Routines 
