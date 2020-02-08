#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
char auth[] = "cwCqd9j89iIJi6QNZsvF7Zdb14cBLy9V";
 
/* WiFi credentials */
char ssid[] = "Saad";
char pass[] = "12345678";
 
SimpleTimer timer;
 
int mq6 = A0; // smoke sensor is connected with the analog pin A0 
int data = 0; 

void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, getSendData);
}
 
void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
  Serial.println(mq6);
}
 
/***************************************************
 * Send Sensor data to Blynk
 **************************************************/
void getSendData()
{
data = analogRead(mq6); 
  Blynk.virtualWrite(V2, data); //virtual pin V3
 
  if (data > 800 )
  {
    Blynk.notify("LPG leakaging is HIGH!!!"); 
  }
 
 }
