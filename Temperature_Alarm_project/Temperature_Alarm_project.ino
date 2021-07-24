/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial myserial(7,8); //blutooth Tx=0 ,Rx=1

#define sensor A0
int value=0;
float volt=0;
int temp=0;
int Buzz=A1;
String a;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(8,OUTPUT);
  lcd.begin(16,2);
  lcd.print("Temp= ");
  pinMode(Buzz,OUTPUT);
  myserial.begin(9600);
  Serial.begin(9600);
  
}

void loop() {
 value=analogRead(sensor);
 volt=(5.0/1023.0)*value;
 temp=volt/.01; //temp=(volt/10mv)
 delay(500);
 lcd.setCursor(6, 0);
 lcd.print(temp);
 lcd.print(" C");
 if (temp>=17)
{digitalWrite(Buzz,HIGH); 
Serial.println("Beware there is a fire"); 
if(Serial.available()>0){
  char data=Serial.read();
  switch(data){
   case 'A':
    digitalWrite(8,HIGH);
    break;
   case 'B':
    digitalWrite(8,LOW);
    break;
    default:break;
  }
  Serial.println(data);
}
delay(50);
}else
{digitalWrite (Buzz,LOW);}
}
