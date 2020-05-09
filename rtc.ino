#include <Wire.h>       //I2C library
#include <RtcDS3231.h>  //RTC library
#include <ESP8266WiFi.h> // wifi
#include <Firebase.h>  
#include <FirebaseArduino.h>  
#include <FirebaseCloudMessaging.h>  
#include <FirebaseError.h>  
#include <FirebaseHttpClient.h>  
#include <FirebaseObject.h>  
  

int Years,Months,Days,Hours,Minutes,Seconds;
String data_f,data, path;
int day_real, month_real, year_real, hour_real, minute_real, second_real, day_s_f, month_s_f, year_s_f, day_e_f, month_e_f, year_e_f, day_s1_f, month_s1_f, year_s1_f, day_e1_f, month_e1_f, year_e1_f;
int morning_h_f, morning_m_f, afternoon_h_f, afternoon_m_f, night_h_f, night_m_f, morning_h1_f, morning_m1_f, afternoon_h1_f, afternoon_m1_f, night_h1_f, night_m1_f;
int years_r,months_r,days_r,hours_r,minutes_r,seconds_r;
String start_f, end_f, morning_f, afternoon_f, night_f, start1_f, end1_f, morning1_f, afternoon1_f, night1_f; 

#define FIREBASE_HOST "medibox-f3f81.firebaseio.com"//url
#define FIREBASE_AUTH "wHX3KFzOD4OQFoTRRNLrBBLMBbAlhpPmh4alK5vi"//token
#define WIFI_SSID "Realme"  //hotspot CELESTIAL V SOLUTIONS
#define WIFI_PASSWORD "hari13032"//password dhscvs98451
#define SKIP_FP_CONTROL
 
//RtcDS3231 rtcObject;              //Uncomment for version 1.0.1 of the rtc library
RtcDS3231<TwoWire> rtcObject(Wire); //Uncomment for version 2.0.0 of the rtc library
 
void setup() {
 
  Serial.begin(9600);  //Starts serial connection
  rtcObject.Begin();     //Starts I2C
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
 
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  RtcDateTime currentTime = RtcDateTime(19, 4, 25, 4, 20, 00); //define date and time object
  rtcObject.SetDateTime(currentTime); //configure the RTC with object
 
}
Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
}

void first_tab(){
  

            if ((hours_r == morning_h_f) && (minutes_r == morning_m_f)){


                        Firebase.setInt("bin", 1);
                        Firebase.setInt("status", 1);
                        //Serial.println("inside first_mor1");
                        
                        data="#1001";
                       // Serial.println(data);
                        data +=',';
                        data +=Firebase.getString(path+"/patient_name");   
                        data +='|';
                        data +=Firebase.getString(path+"/tab_information/1_tab/morning");
                        data +='$';
                        data +=Firebase.getString(path+"/tab_information/1_tab/tablet");
                        data +='@';
                        data +=1;
                        data +='^';
                        Serial.println(data);
                        data="";
                        //delay(100); 
                        //digitalWrite(LED_BUILTIN, LOW);
                        
                    }

              if((hours_r == afternoon_h_f) && (minutes_r == afternoon_m_f)){
                
                        
                        Firebase.setInt("bin", 1);
                        Firebase.setInt("status", 1);
                        //Serial.println("inside first_aft1");
                        data="#1001";
                       // Serial.println(data);
                        data +=',';
                        data +=Firebase.getString(path+"/patient_name");   
                        data +='|';
                        data +=Firebase.getString(path+"/tab_information/1_tab/afternoon");
                        data +='$';
                        data +=Firebase.getString(path+"/tab_information/1_tab/tablet");
                        data +='@';
                        data +=1;
                        data +='^';
                        Serial.println(data);
                        data="";
                        delay(2000);
                        //digitalWrite(LED_BUILTIN, LOW);
              }

              if((hours_r == night_h_f) && (minutes_r == night_m_f)){

                        
                        Firebase.setInt("bin", 1);
                        Firebase.setInt("status", 1);
                        //Serial.println("inside first_nig1");
                        
                        //Serial.println("i am here");
                        data="#1001";
                       // Serial.println(data);
                        data +=',';
                        data +=Firebase.getString(path+"/patient_name");   
                        data +='|';
                        data +=Firebase.getString(path+"/tab_information/1_tab/night");
                        data +='$';
                        data +=Firebase.getString(path+"/tab_information/1_tab/tablet");
                        data +='@';
                        data +=1;
                        data +='^';
                        Serial.println(data);
                        data="";
                        delay(2000);
                        //digitalWrite(LED_BUILTIN, LOW);
              }
                    
            
  
}
void second_tab(){

if ((hours_r == morning_h1_f) && (minutes_r == morning_m1_f)){

                        
                        Firebase.setInt("bin", 2);
                        Firebase.setInt("status", 1);
                       // Serial.println("inside first_mor2");
                        data="#1001";
                        data +=',';
                        data +=Firebase.getString(path+"/patient_name");   
                        data +='|';
                        data +=Firebase.getString(path+"/tab_information/2_tab/morning");
                        data +='$';
                        data +=Firebase.getString(path+"/tab_information/2_tab/tablet");
                        data +='@';
                        data +=2;
                        data +='^';
                        Serial.println(data);
                        data=""; 
                        delay(2000);
                        //digitalWrite(LED_BUILTIN, LOW);
                    }

              if((hours_r == afternoon_h1_f) && (minutes_r == afternoon_m1_f)){

                        Firebase.setInt("bin", 2);
                        Firebase.setInt("status", 1);
                        //Serial.println("inside first_aft2");
                        data="#1001";
                        data +=',';
                        data +=Firebase.getString(path+"/patient_name");   
                        data +='|';
                        data +=Firebase.getString(path+"/tab_information/2_tab/afternoon");
                        data +='$';
                        data +=Firebase.getString(path+"/tab_information/2_tab/tablet");
                        data +='@';
                        data +=2;
                        data +='^';
                        Serial.println(data);
                        data="";
                        delay(2000);
                        //digitalWrite(LED_BUILTIN, LOW);
              }

              if((hours_r == night_h1_f) && (minutes_r == night_m1_f)){

                        Firebase.setInt("bin", 2);
                        Firebase.setInt("status", 1);
                        //Serial.println("inside first_nig2");
                        data="#1001";
                        data +=',';
                        data +=Firebase.getString(path+"/patient_name");   
                        data +='|';
                        data +=Firebase.getString(path+"/tab_information/2_tab/night");
                        data +='$';
                        data +=Firebase.getString(path+"/tab_information/2_tab/tablet");
                        data +='@';
                        data +=2;
                        data +='^';
                        Serial.println(data);
                        //Serial.println(data);
                        data="";
                        delay(2000);
                        //digitalWrite(LED_BUILTIN, LOW);
             }
                    
  
}

 
void loop() {
//  for(int i=0
  path =Firebase.getString("1/path");
  delay(500);
  start_f = Firebase.getString(path+"/tab_information/1_tab/start");
  //Serial.println(start_f);
  end_f = Firebase.getString(path+"/tab_information/1_tab/end");
 // Serial.println(end_f);
  morning_f = Firebase.getString(path+"/tab_information/1_tab/morning");
  afternoon_f = Firebase.getString(path+"/tab_information/1_tab/afternoon");
  night_f = Firebase.getString(path+"/tab_information/1_tab/night");
  
  start1_f = Firebase.getString(path+"/tab_information/2_tab/start");
  end1_f = Firebase.getString(path+"/tab_information/2_tab/end");
  morning1_f = Firebase.getString(path+"/tab_information/2_tab/morning");
  afternoon1_f = Firebase.getString(path+"/tab_information/2_tab/afternoon");
  night1_f = Firebase.getString(path+"/tab_information/2_tab/night");

  day_s_f = start_f.substring(0, 2).toInt();
  month_s_f = start_f.substring(3, 5).toInt();
  year_s_f = start_f.substring(6, 10).toInt();
  day_e_f = end_f.substring(0, 2).toInt();
  month_e_f = end_f.substring(3, 5).toInt();
  year_e_f = end_f.substring(6, 10).toInt();
  morning_h_f = morning_f.substring(0, 2).toInt();
  morning_m_f = morning_f.substring(3, 5).toInt();
  afternoon_h_f = afternoon_f.substring(0, 2).toInt();
  afternoon_m_f = afternoon_f.substring(3, 5).toInt();
  night_h_f = night_f.substring(0, 2).toInt();
  night_m_f = night_f.substring(3, 5).toInt();

  day_s1_f = start1_f.substring(0, 2).toInt();
  month_s1_f = start1_f.substring(3, 5).toInt();
  year_s1_f = start1_f.substring(6, 10).toInt();
  day_e1_f = end1_f.substring(0, 2).toInt();
  month_e1_f = end1_f.substring(3, 5).toInt();
  year_e1_f = end1_f.substring(6, 10).toInt();
  morning_h1_f = morning1_f.substring(0, 2).toInt();
  morning_m1_f = morning1_f.substring(3, 5).toInt();
  afternoon_h1_f = afternoon1_f.substring(0, 2).toInt();
  afternoon_m1_f = afternoon1_f.substring(3, 5).toInt();
  night_h1_f = night1_f.substring(0, 2).toInt();
  night_m1_f = night1_f.substring(3, 5).toInt();
 
  RtcDateTime currentTime = rtcObject.GetDateTime();    //get the time from the RTC
 
  char str[20];   //declare a string as an array of chars
 
  //Serial.println(str); //print the string to the serial port
  //Serial.println("Current date and time");
  years_r=currentTime.Year();
  Serial.println(years_r);
  months_r=currentTime.Month();
  Serial.println(months_r);
  days_r= currentTime.Day();
  Serial.println(days_r);
 hours_r=currentTime.Hour();
  Serial.println(hours_r);
 minutes_r= currentTime.Minute();
  Serial.println(minutes_r);
  seconds_r= currentTime.Second();
  Serial.println(seconds_r);
  Serial.println("Firebase-Date");
  Serial.println(start_f);
  Serial.println(day_s_f);
  Serial.println(month_s_f);
  Serial.println(year_s_f);
  Serial.println(end_f);
  Serial.println(day_e_f);
  Serial.println(month_e_f);
  Serial.println(year_e_f);
  Serial.println("Firebase-Time");
  Serial.println(morning_h_f);
  Serial.println(morning_m_f);
  Serial.println(afternoon_h_f);
  Serial.println(afternoon_m_f);
  Serial.println(night_h_f);
  Serial.println(night_m_f);



    if (((years_r >= year_s_f) && (months_r >= month_s_f) && (days_r >= day_s_f))  &&  ((years_r <= year_e_f) && (months_r <= month_e_f) && (days_r <= day_e_f))){
        Serial.println("Correct Date_1");
        first_tab();
    }
    if (((years_r >= year_s1_f) && (months_r >= month_s1_f) && (days_r >= day_s1_f))  &&  ((years_r <= year_e1_f) && (months_r <= month_e1_f) && (days_r <= day_e1_f))){
        Serial.println("Correct Date_2");
        second_tab(); 
    }
 
 int d=Firebase.getInt("status");
  }
