//
// Created by User on 12/6/2023.
//
#include <Arduino.h>
#ifndef CONTACT_WELDING_OUTPUT_H
#define CONTACT_WELDING_OUTPUT_H


class Output {
private:
    int pin = 5;
    bool isInverted = false;
public:
    Output(int pin, bool isInverted = false) {
        this->pin = pin;
        this->isInverted = isInverted;
        pinMode(pin, OUTPUT);
        digitalWrite(this->pin, this->isInverted);
    }

    void setState(bool state) {
        if (isInverted) {
            digitalWrite(this->pin, !state);
        } else {
            digitalWrite(this->pin, state);  // Turn on the LED
        }
    }
};


#endif //CONTACT_WELDING_OUTPUT_H
