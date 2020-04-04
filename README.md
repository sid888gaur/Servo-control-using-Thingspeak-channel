# Servo-control-using-Thingspeak-channel
*In this project, a servo motor is controlled from a Thingspeak channel using NodeMCU*

## Components
- NodeMCU x 1
- Servo motor x 1

## Libraries required
- Thingspeak.h
- ESP8266WiFi.h
- Servo.h

## Description

A *Thingsepeak channel* is required to control the servo motor
### Creating a Thingspeak channel
- Sign Up for New User Account - https://thingspeak.com/users/sign_up
- Create a new Channel by selecting Channels, My Channels, and then New Channel
- Enable one field
- ThingSpeak channel ID and ThingSpeak channel READ_APIKEY are your Channel ID and Read API key

### Servo_control_Thingspeak.ino
This file consists of the code to control servo motor using Thingspeak channel
