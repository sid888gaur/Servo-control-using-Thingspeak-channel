#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include <Servo.h>
Servo servo;

char ssid[] = "SSID";   // your network SSID (name) 
char pass[] = "PASSWORD";   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

// Counting channel details
const char * myCounterReadAPIKey = "Read API";
unsigned int counterFieldNumber = 1; 

void setup() {
  Serial.begin(115200);  // Initialize serial
  delay(10);
  servo.attach(2);        // pin number = 2
  WiFi.mode(WIFI_STA);    // station mode : nodemcu connects to a wifi network || access point : mode enables nodemcu to create its own wifi network
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {

  int statusCode = 0;
  
  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected");
  }

  // Read in field 4 of the public channel recording the temperature
  int value = ThingSpeak.readFloatField(ChannelNumber, FieldNumber);  

  // Check the status of the read operation to see if it was successful
  statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200){
    servo.write(value);
  }
  else{
    Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  }
  
  delay(5000); // No need to read the temperature too often.
  
}
