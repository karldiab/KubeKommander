unsigned long start;//for a millis timer to cycle through the animations
void LED(int z, int x, int y, byte R, byte G, byte B);
void LEDNo(int LEDNumber, byte R, byte G, byte B);
void clean();
unsigned int counter = 0;
unsigned int frameNo = 1;

void testSend() {
    byte R;
  byte G;
  byte B;
  if (frameNo%2 == 0) {
    R = random(15);
    G = random(15);
    B = random(15);
  } else {
    R = 0;
    G = 0;
    B = 0;
  }
  Serial.print("Sending frame no ");
  Serial.print(frameNo);
  Serial.print(" with RGB: ");
  Serial.print(R);
  Serial.print(", ");
  Serial.print(G);
  Serial.print(", ");
  Serial.println(B);
  unsigned long startTime = millis();
    for (int i = 0; i < 512; i++) {
      LEDNo(i,R,G,B);
    }
  Serial.print("Frame sent in this many ms: ");
  Serial.println(millis() - startTime);
  frameNo++;
  Serial.println("Done sending the frame. Waiting .1 secs");
  //delay(100);
}
