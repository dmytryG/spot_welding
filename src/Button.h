//
// Created by User on 12/6/2023.
//
#include <Arduino.h>
#ifndef CONTACT_WELDING_BUTTON_H
#define CONTACT_WELDING_BUTTON_H


class Button {
private:
    int pin = 13;
    long lastNotPressed = 0;
    bool isClickProcessed = false;
    bool hasPressed = false;
    bool isInverted = false;
public:
    Button(int pin, bool isInverted = false) {
        this->pin = pin;
        this->isInverted = isInverted;
        pinMode(pin, INPUT_PULLUP);
    }

    void loop() {
        bool buttonState;
        if (isInverted) {
            buttonState = !digitalRead(this->pin);
        } else {
            buttonState = digitalRead(this->pin);
        }
        if (buttonState == LOW) {
            this->lastNotPressed = millis();
            this->isClickProcessed = false;
        } else {
            if (millis() - this->lastNotPressed > 100 && millis() - this->lastNotPressed < 500) {
                this->hasPressed = true;
            } else {
                this->hasPressed = false;
            }
        }
    }

    bool isPressed() {
        if (!this->isClickProcessed && this->hasPressed) {
            this->hasPressed = false;
            this->isClickProcessed = true;
            return true;
        }
        return false;
    }
};


#endif //CONTACT_WELDING_BUTTON_H
