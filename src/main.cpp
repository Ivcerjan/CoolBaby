#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <TFT_eSPI.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
TFT_eSPI tft = TFT_eSPI();

void setup() {
    Serial.begin(115200);
    delay(1000);

    Wire.begin(21, 22); // SDA, SCL

    if (!mlx.begin()) {
        Serial.println("Can't find MLX90614 sensor. Check wires!");
        while (1) {
            delay(1000);
        }
    }

    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.println("Ready!");

    Serial.println("Sensor and display ready.");
}

void loop() {
    float objectTemp = mlx.readObjectTempC();

    tft.fillScreen(TFT_BLACK);

    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.println("Food temp:");

    tft.setTextSize(3);
    tft.setCursor(10, 50);
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.println(objectTemp, 1);

    Serial.print("Food temp: ");
    Serial.println(objectTemp);

    delay(1000);
}