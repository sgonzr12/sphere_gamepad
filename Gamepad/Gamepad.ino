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
  #include "PS4Protocol.h"
  #include "PS4Gamepad.h"
  #include "Pins.h"
}

ESP32USB esp32USB;

// Gamepad
tPSGamepad psGamepad;
// Datos del gamepad serializados para su envio
uint8_t buffer[PS4_GAMEPAD_REPORT_SIZE];

void setup() {

  Serial.begin(9600);

  PS4GamepadReleaseAllButtons(&psGamepad);

  esp32USB.begin();
}

void loop() {
  /*
    // Variable estática para almacenar el índice del botón actual
    static tPSButtons botonActual = CROSS; // Empezamos por el primer botón

    // Registramos la pulsación del botón actual en psGamepad
    PS4GamepadPressButton(botonActual, &psGamepad);

    // Serializamos los datos contenidos en psGamepad para su envío
    PS4ProtocolSerializePSGamepadData(psGamepad, buffer);

    // Enviamos el contenido del buffer por USB
    esp32USB.write(PS4_GAMEPAD_REPORT_SIZE, buffer);

    // Esperamos un poco para simular la duración de la pulsación
    delay(100);

    // Soltamos el botón actual
    PS4GamepadReleaseButton(botonActual, &psGamepad);

    // Serializamos nuevamente después de soltar el botón
    PS4ProtocolSerializePSGamepadData(psGamepad, buffer);

    // Enviamos nuevamente el buffer tras soltar el botón
    esp32USB.write(PS4_GAMEPAD_REPORT_SIZE, buffer);

    // Esperamos antes de pasar al siguiente botón
    delay(100);

    // Avanzamos al siguiente botón de forma cíclica
    botonActual = (tPSButtons)((int)botonActual + 1); // Convertimos a int, sumamos 1 y luego a tPSButtons
    if (botonActual >= RESERVED_LAST_BUTTON_UNUSED) {
      botonActual = CROSS; // Reiniciamos al primer botón
    }
  */

  //check if any button is pressed
  //imprimir valor del pin A
  Serial.println(touchRead(BUTTON_ZR));
  if (touchRead(BUTTON_B) > TOUCH_THRESHOLD) {
    PS4GamepadPressButton(B, &psGamepad);
    Serial.println("Boton CROSS presionado");
  } else {
    PS4GamepadReleaseButton(B, &psGamepad);
  }
  if (touchRead(BUTTON_A) > TOUCH_THRESHOLD) {
    PS4GamepadPressButton(A, &psGamepad);
  } else {
    PS4GamepadReleaseButton(A, &psGamepad);
  }
  if (touchRead(BUTTON_Y) > TOUCH_THRESHOLD) {
    PS4GamepadPressButton(Y, &psGamepad);
  } else {
    PS4GamepadReleaseButton(Y, &psGamepad);
  }
  if (touchRead(BUTTON_X) > TOUCH_THRESHOLD) {
    PS4GamepadPressButton(X, &psGamepad);
  } else {
    PS4GamepadReleaseButton(X, &psGamepad);
  }
  if (touchRead(BUTTON_L) > TOUCH_THRESHOLD) {
    Serial.println("Boton L1 presionado");
    PS4GamepadPressButton(L1, &psGamepad);
  } else {
    PS4GamepadReleaseButton(L1, &psGamepad);
  }
  if (touchRead(BUTTON_R) > TOUCH_THRESHOLD) {
    Serial.println("Boton R1 presionado");
    PS4GamepadPressButton(R1, &psGamepad);
  } else {
    PS4GamepadReleaseButton(R1, &psGamepad);
  }
  if (touchRead(BUTTON_ZL) > TOUCH_THRESHOLD) {
    Serial.println("Boton L2 presionado");
    PS4GamepadPressButton(L2, &psGamepad);
  } else {
    PS4GamepadReleaseButton(L2, &psGamepad);
  }
  if (touchRead(BUTTON_ZR) > TOUCH_THRESHOLD) {
    Serial.println("Boton R2 presionado");
    PS4GamepadPressButton(R2, &psGamepad);
  } else {
    PS4GamepadReleaseButton(R2, &psGamepad);
  }
  if (touchRead(BUTTON_HOME) > TOUCH_THRESHOLD) {
    PS4GamepadPressButton(OPTIONS, &psGamepad);
  } else {
    PS4GamepadReleaseButton(OPTIONS, &psGamepad);
  }
  if (touchRead(BUTTON_CAPTURE) > TOUCH_THRESHOLD) {
    PS4GamepadPressButton(SHARE, &psGamepad);
  } else {
    PS4GamepadReleaseButton(SHARE, &psGamepad);
  }
  if (touchRead(DPAD_UP) > TOUCH_THRESHOLD) {
    Serial.println("Boton DPAD-U presionado");
    PS4GamepadPressButton(UP, &psGamepad);
  } else {
    PS4GamepadReleaseButton(UP, &psGamepad);
  }
  if (touchRead(DPAD_DOWN) > TOUCH_THRESHOLD) {
    Serial.println("Boton DPAD-D presionado");
    PS4GamepadPressButton(DOWN, &psGamepad);
  } else {
    PS4GamepadReleaseButton(DOWN, &psGamepad);
  }
  if (touchRead(DPAD_LEFT) > TOUCH_THRESHOLD) {
    Serial.println("Boton DPAD-L presionado");
    PS4GamepadPressButton(LEFT, &psGamepad);
  } else {
    PS4GamepadReleaseButton(LEFT, &psGamepad);
  }
  if (touchRead(DPAD_RIGHT) > TOUCH_THRESHOLD) {
    Serial.println("Boton DPAD-R presionado");
    PS4GamepadPressButton(RIGHT, &psGamepad);
  } else {
    PS4GamepadReleaseButton(RIGHT, &psGamepad);
  }

  // Serializamos los datos contenidos en psGamepad para su envío
  PS4ProtocolSerializePSGamepadData(psGamepad, buffer);

  // Enviamos el contenido del buffer por USB
  esp32USB.write(PS4_GAMEPAD_REPORT_SIZE, buffer);

  // Añadir un delay para que no se envíen los datos tan rápido
  delay(100);
}
