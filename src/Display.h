//
// Created by User on 12/6/2023.
//

#ifndef CONTACT_WELDING_DISPLAY_H
#define CONTACT_WELDING_DISPLAY_H
#define CLK 5
#define DIO 4

#include "GyverTM1637.h"
GyverTM1637 disp(CLK, DIO);
#include "Config.h"


class Display {
private:
    Config * config;
public:
    Display(Config * config) {
        this->config = config;
        disp.clear();
        disp.brightness(7);
    }

    void update() {
        disp.displayInt(config->expo / 10);
    }

    void sayHi() {
        uint32_t Now, clocktimer;
        // пишем HELL
        disp.brightness(7);
        disp.displayByte(_H, _E, _L, _O);

        Now = millis();
        while (millis () - Now < 3000) {    // 3 секунды
            for (int i = 7; i > 0; i--) {
                disp.brightness(i);   // меняем яркость
                delay(40);
            }
            for (int i = 0; i < 8; i++) {
                disp.brightness(i);   // меняем яркость
                delay(40);
            }
        }
        disp.brightness(7);
    }
};


#endif //CONTACT_WELDING_DISPLAY_H
