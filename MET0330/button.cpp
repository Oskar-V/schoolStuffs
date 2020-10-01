/*
 * IoT Button example
 *
 * This example subscribe to the "button" topic. When a message received, then it
 * will show the message
 *
 * Created 21 Febuary 2018 by Mallor Kingsepp
 */

#include <Arduino.h>
#include <ittiot.h>
#include "Switch.h"
#include "String.h"

const byte buttonPin = D3;
int i;

Switch button = Switch(buttonPin);

void iot_received(String topic, String msg)
{
    Serial.print("MSG FROM USER callback, topic: ");
    Serial.print(topic);
    Serial.print(" payload: ");
    Serial.println(msg);
}

// Function started after the connection to the server is established.
void iot_connected()
{
    Serial.println("MQTT connected callback");
    // Subscribe to the topic "button"
    iot.subscribe("ESP01/button");
    iot.log("IoT Button example!");
}

void setup()
{
    Serial.begin(115200);
    Serial.println("Booting");

    pinMode(buttonPin, INPUT);
    // Print json config to serial
    iot.printConfig();
    // Initialize IoT library
    iot.setup();
    // Initialize relay pin
}

void loop()
{
    // IoT behind the plan work, it should be periodically called
    iot.handle();
    delay(200);
    button.poll();

    if (button.longPress())
    {
        // Send command to turn the LED red on long press
        String msg = String("255;0;0");
        iot.publishMsg("rgb", msg.c_str());
    }

    if (button.doubleClick())
    {
        // Send command to turn the LED blue on double click
        String msg = String("0;0;255");
        iot.publishMsg("rgb", msg.c_str());
    }

    if (button.pushed())
    {
        // Send command to turn the LED yellow
        String msg = String("255;255;0");
        iot.publishMsg("rgb", msg.c_str());
    }
}