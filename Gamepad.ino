/*
MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "ESP32USB.h"

extern "C" {
  #include "NSProtocol.h"
  #include "NSGamepad.h"
  #include "Pins.h"
}

ESP32USB esp32USB;

// Gamepad
tNSGamepad nsGamepad;
// Datos del gamepad serializados para su envio
uint8_t buffer [NS_GAMEPAD_REPORT_SIZE];

void setup() {

  Serial.begin(9600);

  NSGamepadReleaseAllButtons(&nsGamepad);

  esp32USB.begin();
}

void loop() {
  /*
    // Variable estática para almacenar el índice del botón actual
    static tNSButtons botonActual = Y; // Empezamos por el primer botón

    // Registramos la pulsación del botón actual en nsGamepad
    NSGamepadPressButton(botonActual, &nsGamepad);

    // Serializamos los datos contenidos en nsGamepad para su envío
    NSProtocolSerializeNSGamepadData(nsGamepad, buffer);

    // Enviamos el contenido del buffer por USB
    esp32USB.write(NS_GAMEPAD_REPORT_SIZE, buffer);

    // Esperamos un poco para simular la duración de la pulsación
    delay(100);

    // Soltamos el botón actual
    NSGamepadReleaseButton(botonActual, &nsGamepad);

    // Serializamos nuevamente después de soltar el botón
    NSProtocolSerializeNSGamepadData(nsGamepad, buffer);

    // Enviamos nuevamente el buffer tras soltar el botón
    esp32USB.write(NS_GAMEPAD_REPORT_SIZE, buffer);

    // Esperamos antes de pasar al siguiente botón
    delay(100);

    // Avanzamos al siguiente botón de forma cíclica
    botonActual = (tNSButtons)((int)botonActual + 1); // Convertimos a int, sumamos 1 y luego a tNSButtons
    if (botonActual >= RESERVED_LAST_BUTTON_UNUSED) {
      botonActual = Y; // Reiniciamos al primer botón
    }
  */



  //check if any button is pressed
  //imprimir valor del pin A
  Serial.println(touchRead(BUTTON_ZR));
  if (touchRead(BUTTON_A) > TOUCH_THRESHOLD) {
    NSGamepadPressButton(A, &nsGamepad);
    //mostrarMensaje("Boton A presionado");
    Serial.println("Boton A presionado");
  } else {
    NSGamepadReleaseButton(A, &nsGamepad);
  }
  if (touchRead(BUTTON_B) > TOUCH_THRESHOLD) {
    NSGamepadPressButton(B, &nsGamepad);
  } else {
    NSGamepadReleaseButton(B, &nsGamepad);
  }
  if (touchRead(BUTTON_X) > TOUCH_THRESHOLD) {
    NSGamepadPressButton(X, &nsGamepad);
  } else {
    NSGamepadReleaseButton(X, &nsGamepad);
  }
  if (touchRead(BUTTON_Y) > TOUCH_THRESHOLD) {
    NSGamepadPressButton(Y, &nsGamepad);
  } else {
    NSGamepadReleaseButton(Y, &nsGamepad);
  }
  if (touchRead(BUTTON_L) > TOUCH_THRESHOLD) {
    Serial.println("Boton L presionado");
    NSGamepadPressButton(L, &nsGamepad);
  } else {
    NSGamepadReleaseButton(L, &nsGamepad);
  }
  if (touchRead(BUTTON_R) > TOUCH_THRESHOLD) {

    Serial.println("Boton R presionado");
    NSGamepadPressButton(R, &nsGamepad);
  } else {
    NSGamepadReleaseButton(R, &nsGamepad);
  }
  if (touchRead(BUTTON_ZL) > TOUCH_THRESHOLD) {
    Serial.println("Boton ZL presionado");
    NSGamepadPressButton(ZL, &nsGamepad);
  } else {
    NSGamepadReleaseButton(ZL, &nsGamepad);
  }
  if (touchRead(BUTTON_ZR) > TOUCH_THRESHOLD) {
    Serial.println("Boton ZR presionado");
    NSGamepadPressButton(ZR, &nsGamepad);
  } else {
    NSGamepadReleaseButton(ZR, &nsGamepad);
  }
  if (touchRead(BUTTON_HOME) > TOUCH_THRESHOLD) {
    NSGamepadPressButton(HOME, &nsGamepad);
  } else {
    NSGamepadReleaseButton(HOME, &nsGamepad);
  }
  if (touchRead(BUTTON_CAPTURE) > TOUCH_THRESHOLD) {
    NSGamepadPressButton(CAPTURE, &nsGamepad);
  } else {
    NSGamepadReleaseButton(CAPTURE, &nsGamepad);
  }
  if (touchRead(DPAD_UP) > TOUCH_THRESHOLD) {
    Serial.println("Boton DPAD-U presionado");
    NSGamepadPressButton(UP, &nsGamepad);
  } else {
    NSGamepadReleaseButton(UP, &nsGamepad);
  }
  if (touchRead(DPAD_DOWN) > TOUCH_THRESHOLD) {
    Serial.println("Boton DPAD-D presionado");
    NSGamepadPressButton(DOWN, &nsGamepad);
  } else {
    NSGamepadReleaseButton(DOWN, &nsGamepad);
  }
  if (touchRead(DPAD_LEFT) > TOUCH_THRESHOLD) {
    Serial.println("Boton DPAD-L presionado");
    NSGamepadPressButton(LEFT, &nsGamepad);
  } else {
    NSGamepadReleaseButton(LEFT, &nsGamepad);
  }
  if (touchRead(DPAD_RIGHT) > TOUCH_THRESHOLD) {
    Serial.println("Boton DPAD-R presionado");
    NSGamepadPressButton(RIGHT, &nsGamepad);
  } else {
    NSGamepadReleaseButton(RIGHT, &nsGamepad);
  }

  // Serializamos los datos contenidos en nsGamepad para su envío
  NSProtocolSerializeNSGamepadData(nsGamepad, buffer);

  // Enviamos el contenido del buffer por USB
  esp32USB.write(NS_GAMEPAD_REPORT_SIZE, buffer);

  //añadir un delay para que no se envíen los datos tan rápido
  delay(100);

}

