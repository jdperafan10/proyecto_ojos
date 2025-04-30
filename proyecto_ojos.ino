// Tu archivo principal (ej. main.ino)
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "pintura.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int pinSensor = A0;
int valorRaw;
int humedadPorcentaje;

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("No se encontró la pantalla OLED"));
    while (1);
  }
}

void loop() {
  display.clearDisplay();  // Limpiar la pantalla antes de mostrar el primer diseño
  
valorRaw = analogRead(pinSensor);  // Lee entre 0 y 1023
  // Convertimos el valor a porcentaje de humedad (invirtiendo la escala)
  humedadPorcentaje = map(valorRaw, 1023, 0, 0, 100); // 1023 seco → 0%, 0 húmedo → 100%

  Serial.print("Humedad del suelo: ");
  Serial.print(humedadPorcentaje);
  Serial.println(" %");

  delay(500);

  if (humedadPorcentaje == 0 ) {

    display.clearDisplay();  // Limpiar la pantalla antes de mostrar el segundo diseño
// Muestra el noveno diseño
  pintar9(display);
  display.display();  // Actualizar pantalla con el noveno diseño
  delay(100);  // Espera 2 segundos antes de volver al primer diseño

  }else {
  if (humedadPorcentaje > 0 && humedadPorcentaje < 25 ) {

    display.clearDisplay();  // Limpiar la pantalla antes de mostrar el segundo diseño

  // Muestra el quinto diseño
  pintar5(display);
  display.display();  // Actualizar pantalla con el segundo diseño
  delay(100);  // Espera 2 segundos antes de volver al quinto diseño

  } else {
    if (humedadPorcentaje >= 25 && humedadPorcentaje < 40) {

display.clearDisplay();  // Limpiar la pantalla antes de mostrar el tercer diseño
      // Muestra el tercer diseño
  pintar3(display);
  display.display();  // Actualizar pantalla con el segundo diseño
  delay(100);  // Espera 2 segundos antes de volver al primer diseño

    } else {
      if (humedadPorcentaje >= 40 && humedadPorcentaje < 60) {

        display.clearDisplay();  // Limpiar la pantalla antes de mostrar el segundo diseño

  // Muestra el segundo diseño
  pintar2(display);
  display.display();  // Actualizar pantalla con el segundo diseño
  delay(100);  // Espera 2 segundos antes de volver al primer diseño

      } else {
        if (humedadPorcentaje >= 60) {

          display.clearDisplay();  // Limpiar la pantalla antes de mostrar el segundo diseño
          // Muestra el primer diseño
  pintar1(display);
  display.display();  // Actualizar pantalla con el primer diseño
  delay(100);  // Espera 2 segundos
        }
      }
    }
  }
}


}
