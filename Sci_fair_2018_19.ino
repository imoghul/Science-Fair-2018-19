#include <Pixy2.h>

const int motorOneEnable=13;
const int motorOneFirst=12;
const int motorOneSecond=11;

const int motorTwoEnable=7;
const int motorTwoFirst=6;
const int motorTwoSecond=5;

const int wScreen=640;
const int hScreen=400;

const int speedConst=1000;
const int centeringTolerance=10;


Pixy2 pixy;


void setup() {
  Serial.begin(115200);
  pixy.init();
}

void loop() {
  printBlocks();
  
  //setArbitrary(speedConst, true, motorOneEnable, motorOneFirst, motorOneSecond);
  //setArbitrary(speedConst, true, motorTwoEnable, motorTwoFirst, motorTwoSecond);
  
  /*for i in getAllBlocks(){
    Serial.println(getAllBlocks()[i]);
  }
  recyclePixy();
  */
}



void setArbitrary(int nonVectorVelocity, boolean flip, int enable, int pin1, int pin2){
  analogWrite(enable, nonVectorVelocity);
  digitalWrite(pin1, flip);
  digitalWrite(pin2, !flip);
}

void driveOne(int velocity){
  if(velocity>0{
    analogWrite(motorOneEnable, velocity);
    digitalWrite(motorOneFirst, true);
    digitalWrite(motorOneSecond, false);
  }else{
    analogWrite(enable, velocity);
    digitalWrite(motorOneFirst, false);
    digitalWrite(motorOneSecond, true);
  }
}

void driveTwo(int velocity){
  if(velocity>0{
    analogWrite(motorTwoEnable, velocity);
    digitalWrite(motorTwoFirst, true);
    digitalWrite(motorTwoSecond, false);
  }else{
    analogWrite(motorTwoEnable, velocity);
    digitalWrite(motorTwoFirst, false);
    digitalWrite(motorTwoSecond, true);
  }
}



void printBlocks(){
  pixy.ccc.getBlocks();
  if (pixy.ccc.numBlocks)
  {
    Serial.print("Detected ");
    Serial.println(pixy.ccc.numBlocks);
    for (int i=0; i<pixy.ccc.numBlocks; i++)
    {
      Serial.print("  block ");
      Serial.print(i);
      Serial.print(": ");
      pixy.ccc.blocks[i].print();
    }
  }
}


double getOffCenterValue(int objectX){
  return (objectX-(wScreen/2)) ;
}

void align(int tolerance){ // needs relooking
  while(abs(getOffCenterValue( /*getAllBlocks()[0].x*/ ) < tolerance){
    setArbitrary(speedConst, getOffCenterVlaue( /*getAllBlocks()[0].x*/ ) > 0, motorOneEnable, motorOneFirst, motorOneSecond);
    setArbitrary(speedConst, getOffCenterValue( /*getAllBlocks()[0].x*/ ) > 0, motorTwoEnable, motorTwoFirst, motorTwoSecond);
  }
}

void recyclePixy(){
  
  if(sizeof(getAllBlocks())>0){
    align(centeringTolerance)
  }
  setArbitrary(speedConst, true, motorOneEnable, motorOneFirst, motorOneSecond);
  setArbitrary(speedConst, false, motorTwoEnable, motorTwoFirst, motorTwoSecond);
}
  
