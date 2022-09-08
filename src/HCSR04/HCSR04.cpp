/*
Created by Juan Ignacio Causse on 8 sep, 2022

Contact: juanignaciocausse@gmail.com

This software is free to use and modify, just let me know what you created based on it!
*/

#include <HCSR04.h>

HCSR04::HCSR04(int echo_pin, int trigger_pin){
    this -> echo_pin = echo_pin;
    this -> trigger_pin = trigger_pin;

    pinMode(echo_pin, INPUT);
    pinMode(trigger_pin, OUTPUT);

    digitalWrite(trigger_pin, LOW);

    out_of_range = false;
    last_measurement = 0;
}

double HCSR04::measure_cm(){
    out_of_range = false;

    if (millis() - last_measurement < 50){
        return -1;
    }

    unsigned long time;

    digitalWrite(trigger_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin, LOW);

    while(digitalRead(echo_pin) == LOW);
    time = micros();

    while(digitalRead(echo_pin) == HIGH);
    time = micros() - time;

    last_measurement = millis();

    if (time > 37500){
        out_of_range = true;
        return -1;
    }

    return ((double) time) / 58;
}

double HCSR04::measure_m(){
    double cm = measure_cm();
    return cm / 100;
}

bool HCSR04::is_out_of_range(){
    return out_of_range;
}
