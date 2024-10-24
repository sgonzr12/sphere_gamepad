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

  //calibrate the threshold values for all buttons
  Serial.println("calibrating");
  calibrateThresholdValues();

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
  Serial.println(touchRead(1));
  if (touchRead(BUTTON_B) > thresholdValues[BUTTON_B]) {
    PS4GamepadPressButton(B, &psGamepad);
    Serial.println("Boton B presionado");
  } else {
    PS4GamepadReleaseButton(B, &psGamepad);
  }
  if (touchRead(BUTTON_A) > thresholdValues[BUTTON_A]) {
    PS4GamepadPressButton(A, &psGamepad);
    Serial.println("Boton A presionado");
  } else {
    PS4GamepadReleaseButton(A, &psGamepad);
  }
  if (touchRead(BUTTON_Y) > thresholdValues[BUTTON_Y]) {
    PS4GamepadPressButton(Y, &psGamepad);
    Serial.println("Boton Y presionado");
  } else {
    PS4GamepadReleaseButton(Y, &psGamepad);
  }
  if (touchRead(BUTTON_X) > thresholdValues[BUTTON_X]) {
    PS4GamepadPressButton(X, &psGamepad);
    Serial.println("Boton X presionado");
  } else {
    PS4GamepadReleaseButton(X, &psGamepad);
  }
  if (touchRead(BUTTON_L) > thresholdValues[BUTTON_L]) {
    Serial.println("Boton L1 presionado");
    PS4GamepadPressButton(L1, &psGamepad);
  } else {
    PS4GamepadReleaseButton(L1, &psGamepad);
  }
  if (touchRead(BUTTON_R) > thresholdValues[BUTTON_R]) {
    Serial.println("Boton R1 presionado");
    PS4GamepadPressButton(R1, &psGamepad);
  } else {
    PS4GamepadReleaseButton(R1, &psGamepad);
  }
  if (touchRead(BUTTON_ZL) > thresholdValues[BUTTON_ZL]) {
    Serial.println("Boton L2 presionado");
    PS4GamepadPressButton(L2, &psGamepad);
  } else {
    PS4GamepadReleaseButton(L2, &psGamepad);
  }
  if (touchRead(BUTTON_ZR) > thresholdValues[BUTTON_ZR]) {
    Serial.println("Boton R2 presionado");
    PS4GamepadPressButton(R2, &psGamepad);
  } else {
    PS4GamepadReleaseButton(R2, &psGamepad);
  }
  if (touchRead(BUTTON_HOME) > thresholdValues[BUTTON_HOME]) {
    PS4GamepadPressButton(OPTIONS, &psGamepad);
    Serial.println("Boton OPTIONS presionado");
  } else {
    PS4GamepadReleaseButton(OPTIONS, &psGamepad);
  }
  if (touchRead(BUTTON_CAPTURE) > thresholdValues[BUTTON_CAPTURE]) {
    PS4GamepadPressButton(SHARE, &psGamepad);
    Serial.println("Boton SHARE presionado");
  } else {
    PS4GamepadReleaseButton(SHARE, &psGamepad);
  }
  if (touchRead(DPAD_UP) > thresholdValues[DPAD_UP]) {
    Serial.println("Boton DPAD-U presionado");
    PS4GamepadPressButton(UP, &psGamepad);
  } else {
    PS4GamepadReleaseButton(UP, &psGamepad);
  }
  if (touchRead(DPAD_DOWN) > thresholdValues[DPAD_DOWN]) {
    Serial.println("Boton DPAD-D presionado");
    PS4GamepadPressButton(DOWN, &psGamepad);
  } else {
    PS4GamepadReleaseButton(DOWN, &psGamepad);
  }
  if (touchRead(DPAD_LEFT) > thresholdValues[DPAD_LEFT]) {
    Serial.println("Boton DPAD-L presionado");
    PS4GamepadPressButton(LEFT, &psGamepad);
  } else {
    PS4GamepadReleaseButton(LEFT, &psGamepad);
  }
  if (touchRead(DPAD_RIGHT) > thresholdValues[DPAD_RIGHT]) {
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

void calibrateThresholdValues() {
  //calibrate the threshold values for all buttons

  Serial.println("calibrating threshold values for all buttons");
  int values[BUTTONSNUMBER+1];
  unsigned long tiempoinicio = millis();
  int counter = 0;

  // Inicializar valores
  for(int i = 0; i <= BUTTONSNUMBER; i++){
    values[i] = 0;
  }

  //obtener valores
  while(millis() - tiempoinicio < calibrationTime){
    for(int i = 1; i <= BUTTONSNUMBER; i++){
      values[i] += touchRead(i);
    }
    counter ++;
  }

  //calcular promedio
  for(int i = 1; i <= BUTTONSNUMBER; i++){
    thresholdValues[i] = (values[i] / counter)*TOUCHED_THRESHOLD_FACTOR;

    //imprimir valor
    Serial.print("Threshold Boton ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(thresholdValues[i]);
  }

}
