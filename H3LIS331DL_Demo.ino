# Teensy-STEVAL-MKI153V1
/* get accelerate data of H3LIS331DL
 * Auth : lawliet(lawliet.zou@gmail.com)
 * version : 0.1
 */

#include <H3LIS331DL.h>
#include <Wire.h>

//please get these value by running H3LIS331DL_AdjVal Sketch.
// X 203  Y 165  Z 371


#define VAL_X_AXIS  52
#define VAL_Y_AXIS  -125
#define VAL_Z_AXIS  362
int triggerpin = 7;
bool triggerstate = HIGH;

H3LIS331DL h3lis;

void setup(){
  Serial.begin(9600);
  h3lis.init();
  h3lis.importPara(VAL_X_AXIS,VAL_Y_AXIS,VAL_Z_AXIS);
  pinMode(triggerpin,INPUT_PULLUP);
}
void loop()
{
  triggerstate =digitalRead(triggerpin);
  if(triggerstate ==LOW)
  {
//  int16_t x,y,z;
//  h3lis.readXYZ(&x,&y,&z);
 // Serial.print("x, y, z = ");
// Serial.print(x);
//  Serial.print("\t");
//  Serial.print(y);
//  Serial.print("\t");
//  Serial.println(z);

  double xyz[3];
  h3lis.getAcceleration(xyz);
//  Serial.print("accelerate of x, y, z = ");
  Serial.print(xyz[0]);
//  Serial.print("g");
  Serial.print("\t");
  Serial.print(xyz[1]);
//  Serial.print("g");
  Serial.print("\t");
  Serial.println(xyz[2]);
//  Serial.println("g");  
  
  delay(10);
}
}
