//
// Created by User on 12/6/2023.
//

#ifndef CONTACT_WELDING_RELAYPROCESSOR_H
#define CONTACT_WELDING_RELAYPROCESSOR_H
#include "Config.h"
#include "Button.h"
#include "Output.h"


class RelayProcessor {
private:
    Config * config;
    Button * fire;
    Output * output;
public:
    RelayProcessor(Config * config, bool isInverted = false) {
        this->config = config;
        fire = new Button(6, true);
        output = new Output(8, isInverted);
    }
    void update() {
        fire->loop();
        if (fire->isPressed()) {
            output->setState(true);
            delay(config->expo);
            output->setState(false);
        }
    }
};


#endif //CONTACT_WELDING_RELAYPROCESSOR_H
