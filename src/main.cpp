#include <Arduino.h>
#include "Display.h"
#include "Config.h"
#include "Controls.h"
#include "Output.h"
#include "RelayProcessor.h"

Config * config;
Display * display;
Controls * controls;
RelayProcessor * relayProcessor;


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    config = new Config();
    display = new Display(config);
    controls = new Controls(config);
    relayProcessor = new RelayProcessor(config, true);
    display->sayHi();
}

void loop() {
    // put your main code here, to run repeatedly:
    display->update();
    controls->update();
    relayProcessor->update();
}
