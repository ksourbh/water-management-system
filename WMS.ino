#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//needed for library

#include <DNSServer.h>

#include <ESP8266WebServer.h>

#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

#define trigger D0

#define LED D2

#define power D3
#define relay D4
#define floats D5
#define floatss D6

void setup() {

    // put your setup code here, to run once:

    Serial.begin(115200);

    pinMode(trigger,INPUT); 

    pinMode(LED,OUTPUT); 

     pinMode(power,OUTPUT);   
     pinMode (relay, OUTPUT);
     pinMode(floats, INPUT);
     pinMode(floatss,INPUT); 

    if(digitalRead(trigger) == HIGH){

    digitalWrite(power,HIGH);

    WiFiManager wifiManager;

    wifiManager.resetSettings();

    wifiManager.autoConnect("CIRCUIT DIGEST WiFi Manager");

    Serial.println("connected :)");
   

  }     

}

void loop() { 

  if (WiFi.status() == WL_CONNECTED)

        {

          digitalWrite(power,LOW);

          while(WiFi.status() == WL_CONNECTED){           

            digitalWrite(LED,HIGH);

            delay(500);

            digitalWrite(LED,LOW);

            delay(200);   

          }              

        }

        else {

          digitalWrite(LED,LOW);

        }
        {
          {
   if(digitalRead(floats)==HIGH && digitalRead(floatss)==HIGH) //Both float sensor is in high mode
  {
    //Stop both Motors
    digitalWrite(relay,HIGH);
  }

  else if(digitalRead(floats)==HIGH && digitalRead(floatss)==LOW)  //Upper float sensor is low and lower float sensor is in high
  {
    //Move both the Motors
    digitalWrite(relay,HIGH);
  }

  else if(digitalRead(floats)==LOW && digitalRead(floatss)==LOW) // both float sensor is in high mode means the tank is full
  {
    //Stopping the relay as the tank is full
    digitalWrite(relay,LOW);     
       delay(100);
  }

          }
        }
}
