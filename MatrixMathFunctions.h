void CopyIntMatrix(int* A, int n, int m, int* B)
{
  int i, j, k;
  for (i = 0; i < m; i++)
    for(j = 0; j < n; j++)
    {
    
      B[n * i + j] = A[n * i + j];
    }
}
void printMatrix(int* matrixToPrint, int len, int width) {
  int matrix[len][width];
  CopyIntMatrix((int*)matrixToPrint, len, width, (int*)matrix);
  Serial.println("Printing matrix:");
  Serial.println("{");
  for (int i = 0; i < len; i++) {
    Serial.print("  {");
    for (int j = 0; j < width; j++) {
      Serial.print(matrix[i][j]);Serial.print(",");
    }
    Serial.println("},");
  }
  Serial.println("}");
}

void printFloatMatrix(float* A, int m, int n, String label)
{
 // A = input matrix (m x n)
  int i, j;
  Serial.println();
  Serial.println(label);
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      Serial.print(A[n * i + j]);
      Serial.print("\t");
    }
    Serial.println();
  }
}



void CopyFloatMatrix(float* A, int n, int m, float* B)
{
  int i, j, k;
  for (i = 0; i < m; i++)
    for(j = 0; j < n; j++)
    {
    
      B[n * i + j] = A[n * i + j];
    }
}
void MultiplyIntMatrix(int* A, int* B, int m, int p, int n, int* C){
  // A = input matrix (m x p)
  // B = input matrix (p x n)
  // m = number of rows in A
  // p = number of columns in A = number of rows in B
  // n = number of columns in B
  // C = output matrix = A*B (m x n)
  int i, j, k;
  for (i = 0; i < m; i++)
    for(j = 0; j < n; j++)
    {
      C[n * i + j] = 0;
      for (k = 0; k < p; k++)
        C[n * i + j] = C[n * i + j] + A[p * i + k] * B[n * k + j];
    }
}
//exactly like MultiplyIntMatrix except it gets the values of matrix B via PROGMEM recall. This is to save memory
void MultiplyIntMatrixPROGMEM(int* A, int* B, int m, int p, int n, int* C) {
  // A = input matrix (m x p)
  // B = input matrix (p x n)
  // m = number of rows in A
  // p = number of columns in A = number of rows in B
  // n = number of columns in B
  // C = output matrix = A*B (m x n)
  int i, j, k;
  for (i = 0; i < m; i++)
    for(j = 0; j < n; j++)
    {
      C[n * i + j] = 0;
      for (k = 0; k < p; k++)
        C[n * i + j] = C[n * i + j] + A[p * i + k] * pgm_read_word_near(&B[n * k + j]);
    }
}
void MultiplyFloatMatrix(float* A, float* B, int m, int p, int n, float* C)
{
  // A = input matrix (m x p)
  // B = input matrix (p x n)
  // m = number of rows in A
  // p = number of columns in A = number of rows in B
  // n = number of columns in B
  // C = output matrix = A*B (m x n)
  int i, j, k;
  for (i = 0; i < m; i++)
    for(j = 0; j < n; j++)
    {
      C[n * i + j] = 0;
      for (k = 0; k < p; k++)
        C[n * i + j] = C[n * i + j] + A[p * i + k] * B[n * k + j];
    }
}
//a hacky function to save memory. Multiplys a float matrix A with a PROGMEM float matrix B
void MultiplyFloatMatrixPROGMEM(float* A, float* B, int m, int p, int n, float* C)
{
  // A = input matrix (m x p)
  // B = input matrix (p x n)
  // m = number of rows in A
  // p = number of columns in A = number of rows in B
  // n = number of columns in B
  // C = output matrix = A*B (m x n)
  int i, j, k;
  for (i = 0; i < m; i++)
    for(j = 0; j < n; j++)
    {
      C[n * i + j] = 0;
      for (k = 0; k < p; k++)
        C[n * i + j] = C[n * i + j] + A[p * i + k] * pgm_read_float_near(&B[n * k + j]);
    }
}
//a hacky function to save memory. Multiplys an int matrix A with a PROGMEM float matrix B
void MultiplyIntAndFloatMatrixPROGMEM(int* A, float* B, int m, int p, int n, float* C)
{
  // A = input matrix (m x p)
  // B = input matrix (p x n)
  // m = number of rows in A
  // p = number of columns in A = number of rows in B
  // n = number of columns in B
  // C = output matrix = A*B (m x n)
  int i, j, k;
  for (i = 0; i < m; i++)
    for(j = 0; j < n; j++)
    {
      C[n * i + j] = 0;
      for (k = 0; k < p; k++)
        C[n * i + j] = C[n * i + j] + (float)A[p * i + k] * pgm_read_float_near(&B[n * k + j]);
    }
}

// Functions to display on cube from matrixes

 void transformAndDisplayObject(int* pointsMatrix, int pointCounter, int* transformMatrix, int R, int G, int B) { 
  int transformedObject[pointCounter][4];
  MultiplyIntMatrix((int*)pointsMatrix, (int*)transformMatrix, pointCounter, 4, 4, (int*)transformedObject);
  for (int pointNo = 0; pointNo < pointCounter; pointNo++) {
    //if point is out of bounds, don't display it
    if (transformedObject[pointNo][0] >= 0 && transformedObject[pointNo][0] < 8 && transformedObject[pointNo][1] >= 0 && transformedObject[pointNo][1] < 8 && transformedObject[pointNo][2] >= 0 && transformedObject[pointNo][2] < 8) {
      LED(transformedObject[pointNo][0],transformedObject[pointNo][1],transformedObject[pointNo][2],R,G,B);
    } else {
      //Serial.print("Not displaying point ");Serial.print(transformedObject[pointNo][0]);Serial.print(",");Serial.print(transformedObject[pointNo][1]);Serial.print(",");Serial.print(transformedObject[pointNo][2]);Serial.println(" Cause OOB");
    }
  }
  CopyIntMatrix((int*)transformedObject, pointCounter, 4, (int*)pointsMatrix);
}
void displayObject(float* pointsMatrix, int pointCounter, int R, int G, int B) {
  float object[pointCounter][4];
  CopyFloatMatrix((float*)pointsMatrix, pointCounter, 4, (float*)object);
  for (int pointNo = 0; pointNo < pointCounter; pointNo++) {
    //if point is out of bounds, don't display it
    if (object[pointNo][0] >= 0 && object[pointNo][0] < 8 && object[pointNo][1] >= 0 && object[pointNo][1] < 8 && object[pointNo][2] >= 0 && object[pointNo][2] < 8) {
      LED(object[pointNo][0],object[pointNo][1],object[pointNo][2],R,G,B);
    }
  }
}
void displayObjectTruncate(float* pointsMatrix, int pointCounter, int R, int G, int B) {
  float object[pointCounter][4];
  CopyFloatMatrix((float*)pointsMatrix, pointCounter, 4, (float*)object);
  for (int pointNo = 0; pointNo < pointCounter; pointNo++) {
    //if point is out of bounds, don't display it
    if (object[pointNo][0] >= 0 && object[pointNo][0] < 8 && object[pointNo][1] >= 0 && object[pointNo][1] < 8 && object[pointNo][2] >= 0 && object[pointNo][2] < 8) {
      LEDTruncate(object[pointNo][0],object[pointNo][1],object[pointNo][2],R,G,B);
    }
  }
}
//this function takes a points and adjacency matrix and displays the lines in between the points according to the adjacency matrix
void drawLines(float* pointsMatrix, int* adjacencyMatrix, int pointCounter, int R, int G, int B) {
  float points[pointCounter][4];
  CopyFloatMatrix((float*)pointsMatrix, pointCounter, 4, (float*)points);
  int adjacency[pointCounter][pointCounter];
  CopyIntMatrix((int*)adjacencyMatrix, pointCounter, pointCounter, (int*)adjacency);
  for (int i = 0; i < pointCounter; i++) {
    for (int j = 0; j < pointCounter; j++) {
      if (adjacency[i][j]) {
        int pointsInLine = 8;
        for (int p = 0; p < pointsInLine; p++) {
          float t = (float)p/pointsInLine;
          LED(points[i][0] + (points[j][0]-points[i][0])*t,points[i][1] + (points[j][1]-points[i][1])*t,points[i][2] + (points[j][2]-points[i][2])*t,R,G,B);
        }
      }
    }
  }
}
