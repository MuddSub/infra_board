#include <Wire.h> 

#define pin_data 18
#define pin_clock 19

#define Power_Register 0x2D 


void setup() {
  Serial.begin(9600); 
  Wire.begin(); 
  delay (100); //allow for measurement 
  pinMode(pin_data, OUTPUT);
  pinMode(pin_clock, OUTPUT);
  digitalWrite(pin_data, LOW);
  digitalWrite(pin_clock, LOW); 
  Wire.beginTransmission();
  Wire.write(Power_Register); //setting up
  Wire.write(8);
  Wire.endTransmission();

}

void loop() {
 
  Wire.beginTransmission();
  Wire.write(pin_data);
  Wire.write(pin_clock); //writing data to those pins
  Wire.requestFrom(); //do we need this if we're not requesting from an address?

  byte num=0;
  while(Wire.available())  { //reading bytes available 
    num= Wire.read(); //reading one byte of information at a time
    //from SDA and SCL lines
  }

  Wire.endTransmission();

  Serial.print("num = "); 
  Serial.println(num, DEC); //printing data from bytes available during transmission 

  //increment num
 // num= num+1; //why?

  delay(5000); 

//  printVolts();
//}
// 
// void printVolts()
//{
//  int sensorValue = digitalRead(pin_data); 
//  float voltage = sensorValue * (5.00 / 1023.00) * 2; //convert the value to a true voltage.
//  Serial.print(voltage); 
//  if (voltage < 6.50) //set the voltage considered low battery here
//  {
//    digitalWrite(pin_data, HIGH); 
//  }

}
