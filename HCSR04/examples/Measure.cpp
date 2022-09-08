/*
Created by Juan Ignacio Causse on 8 sep, 2022

Contact: juanignaciocausse@gmail.com

This software is free to use and modify, just let me know what you created based on it!
*/

#include <HCSR04.h>

#define ECHO 3
#define TRIGGER 4

HCSR04 sensor = new HCSR04(ECHO, TRIGGER);
double distance;

void setup(){
    Serial.begin(9600);
}

void loop(){
    distance = sensor.measure_cm();
    Serial.print("DIST = ")
    if (sensor.is_out_of_range()){
        Serial.println("inf");
    }
    else{
        Serial.print(distance);
        Serial.println(" cm");
    }
    delay(500);
}