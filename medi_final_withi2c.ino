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

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */
// include the library code:
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
const int trigPin = 8;
const int echoPin = 9;
const int trigPin2 =10;
const int echoPin2 =11;
//int prox=A0;
int led1=A0;
int led2=A1;
int buz=A2;
boolean sms1=false;
boolean sms2=false;

long duration,duration2,duration3,duration4;

int distance,distance2,distance3,distance4;

// initialize the library with the numbers of the interface pins

String data,send_data,sent_data;
int s1,s2,s3,s4;
char d;
String final_data,final_data2;
void setup() {
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(buz, OUTPUT);
   lcd.init();                      // initialize the lcd 
                                     // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Medi Box");
}
void(* resetFunc) (void) = 0; //declare reset function @ address 0

void loop() {
  dist();
  
 if(Serial.available())
{
  data="";
  while(Serial.available())
  {
     d=Serial.read();
    data +=d;
    delay(5);
    }Serial.println(data);

int x = data.indexOf(String('#')); 
int y = data.indexOf(String(','));
  
String code =data.substring(x,y);
  
   // Serial.println(code);//////////////////
   if(code=="#1001")
   {
   int x; //= indata.indexOf(String('"'));   // Find the first occurance of an open quotation.  This is where we begin to read from
  int y; //= indata.lastIndexOf(String('"')); // Find the last occurance of an open quotation. This is where we end.
  
 // String num=indata.substring(x+1,y-26);//1001,shiv|11/12/18 1:30$anasin@
  
  x = data.indexOf(String(','))+1;  
  y = data.indexOf(String('|'));
  
  String p_name =data.substring(x,y);
  //Serial.print(p_name);

    x = data.indexOf(String('|'))+1;  
    y = data.indexOf(String('$'));
  
  String Time_T  =data.substring(x,y);
  //Serial.println(Time_T);

   x = data.indexOf(String('$'))+1;  
    y = data.indexOf(String('@'));
  
  String tablet  = data.substring(x,y);
  

x = data.indexOf(String('@'))+1;  
y = data.indexOf(String('^'));
String bin =data.substring(x,y);

final_data="Name: "+String(p_name)+",  "+"D & T: "+String(Time_T);//+",  "+"Tablet: "+String(tablet);
final_data2 ="Tablet: "+String(tablet);
 
//Serial.println(final_data);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(final_data);
lcd.setCursor(0,1);
lcd.print(final_data2);
   
    if(bin=="1")
    {
    digitalWrite(led1,HIGH);
    digitalWrite(buz,HIGH);
    delay(2000);
    digitalWrite(buz,LOW);
    digitalWrite(led1,LOW);
    }
   else if(bin=="2")
    {
    digitalWrite(led2,HIGH);
    digitalWrite(buz,HIGH);
    delay(2000);
    digitalWrite(buz,LOW);
    digitalWrite(led2,LOW);
    }
   }
    }
    
  int l= final_data.length();
  for (int positionCounter = 0; positionCounter < l; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    
    dist();
    sms();
   Serial.println("resetting");
  resetFunc();  //call reset
  
  delay(100);
  Serial.println("never happens");
       
  } 
}

void sms()
{//////////////
   if (distance>7 && sms1==false)
   {
    sms1=true;
  // put your main code here, to run repeatedly:
  Serial.print("AT=1\r");
  delay(100);
  Serial.print("AT+CMGF=1\r");
  delay(100);
  Serial.print("AT+CMGS=\"+919444267734\"\r");
  delay(100);
  Serial.println("Tablet  is almost empty..");
  delay(100);
  Serial.write(0x1A);
  delay(100);
   Serial.write(0x1A);
  delay(100);
  Serial.write(0x1A);
  delay(100);//9916275040
     
 // delay(4000);
   }else if(distance <= 7){sms1=false;}

     if (distance2>7 && sms2==false)
   {sms2=true;
  // put your main code here, to run repeatedly:
  Serial.print("AT=1\r");
  delay(100);
  Serial.print("AT+CMGF=1\r");
  delay(100);
  Serial.print("AT+CMGS=\"+919444267734\"\r");//917022564369
  delay(100);
  Serial.println("Tablet name-2 is almost empty..");
  delay(100);
  Serial.write(0x1A);
  delay(100);
   Serial.write(0x1A);
  delay(100);
  Serial.write(0x1A);
  delay(100);
     
   }else if(distance2 <= 7){sms2=false;}}
void dist()
{
 /////////////////////////////////////// ultra 1 
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
delay(10);
//sms();
//Serial.println(distance);


/////////////////////////////////////// ultra 2
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration2 = pulseIn(echoPin2, HIGH);
// Calculating the distance
distance2= duration2*0.034/2;
//sms();
//Serial.println(distance2);

  }
