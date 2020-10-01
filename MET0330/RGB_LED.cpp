#include <Arduino.h>
#include <ittiot.h>
#include <Adafruit_NeoPixel.h>

#define PIN D2

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

// https://stackoverflow.com/questions/9072320/split-string-into-string-array
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = {0, -1};
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++)
    {
        if (data.charAt(i) == separator || i == maxIndex)
        {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i + 1 : i;
        }
    }

    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

// Change RGB LED color
// mosquitto_pub -u test -P test -t "ITT/IOT/3/rgb" -m "51;255;153"
void iot_received(String topic, String msg)
{
    Serial.print("MSG FROM USER callback, topic: ");
    Serial.print(topic);
    Serial.print(" payload: ");
    Serial.println(msg);

    String r = getValue(msg, ';', 0);
    String g = getValue(msg, ';', 1);
    String b = getValue(msg, ';', 2);

    Serial.print("R: ");
    Serial.println(r);

    Serial.print("G: ");
    Serial.println(g);

    Serial.print("B: ");
    Serial.println(b);

    pixels.setPixelColor(0, r.toInt(), g.toInt(), b.toInt()); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.
}

void iot_connected()
{
    Serial.println("MQTT connected callback");
    // Changed subscribe address to read button output
    iot.subscribe("ESP01/rgb"); 
    iot.log("IoT NeoPixel example!");
}

void setup()
{
    Serial.begin(115200);
    Serial.println("Booting");

    iot.printConfig(); // print json config to serial //Peale Serial.begin ja enne iot.setup
    iot.setup();

    pixels.begin(); // This initializes the NeoPixel library.
}

void loop()
{
    iot.handle();
    delay(200);
}