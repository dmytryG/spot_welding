//
// Created by User on 12/6/2023.
//

#ifndef CONTACT_WELDING_CONTROLS_H
#define CONTACT_WELDING_CONTROLS_H
#include "Config.h"
#include "Button.h"

class Controls {
private:
    Config * config;
    Button * less;
    Button * more;
public:
    Controls(Config * config) {
        this->config = config;
        less = new Button(11);
        more = new Button(12);
    }
    void update() {
        less->loop();
        more->loop();
        if (less->isPressed()) {
            Serial.print("Subtracted 10, now its ");
            config->expo -= 10;
            Serial.println(config->expo);
        } else if (more->isPressed()) {
            Serial.print("Added 10, now its ");
            config->expo += 10;
            Serial.println(config->expo);
        }
    }
};


#endif //CONTACT_WELDING_CONTROLS_H
