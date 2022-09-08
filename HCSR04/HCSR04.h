/*
Created by Juan Ignacio Causse on 8 sep, 2022

Contact: juanignaciocausse@gmail.com

This software is free to use and modify, just let me know what you created based on it!
*/

#ifndef _HCSR04_H_
#define _HCSR04_H_

#include <Arduino.h>

class HCSR04{
public:
    HCSR04(int echo_pin, int trigger_pin);

    double measure_cm();        //Returns distance in cm or a negative value if out of range. If 50 ms have not passed since the last measurement, a negative value is returned.
    double measure_m();         //Returns distance in cm or a negative value if out of range. If 50 ms have not passed since the last measurement, a negative value is returned.
    bool is_out_of_range();     //Returns whether the last measure was out of range or not.

private:
    int echo_pin, trigger_pin;
    bool out_of_range;
    unsigned long last_measurement;
}

#endif //_HCSR04_H_
