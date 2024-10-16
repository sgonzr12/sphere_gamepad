/*
MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
...
(The MIT License text remains unchanged)
*/

#include "ESP32USB.h"

extern "C" {
  #include "PS4Types.h"      // Cambiado de "NSTypes.h" a "PSTypes.h"
  #include "PS4Protocol.h"  // Cambiado de "NSProtocol.h" a "PS4Protocol.h"
  #include "Pins.h"
}

ESP32USB esp32USB;

// Gamepad
tPS4Gamepad PS4Gamepad;
// Datos del gamepad serializados para su envio
uint8_t buffer[PS4_GAMEPAD_REPORT_SIZE];

void setup() {
  Serial.begin(9600);

  // Inicializar todos los botones como no presionados
  PS4GamepadReleaseAllButtons(&PS4Gamepad);

  // Inicializar la comunicación USB
  esp32USB.begin();
}

void loop() {
  // Verificar el estado de cada botón utilizando sensores táctiles
  // Imprimir el valor del pin ZR para depuración
  Serial.println(touchRead(BUTTON_ZR));

  // Mapeo de botones de PS4
  if (touchRead(BUTTON_A) > TOUCH_THRESHOLD) {
    PS4GamepadPressButton(CROSS, &PS4Gamepad); // BUTTON_A mapea a CROSS
    Serial.println("Boton A presionado");
  } else {
    PS4GamepadReleaseButton(CROSS, &PS4Gamepad);
  }

  if (touchRead(BUTTON_B) > TOUCH_THRESHOLD) {
    PS4GamepadPressButton(CIRCLE, &PS4Gamepad); // BUTTON_B mapea a CIRCLE
  } else {
    PS4GamepadReleaseButton(CIRCLE, &PS4Gamepad);
  }

  if (touchRead(BUTTON_X) > TOUCH_THRESHOLD) {
    PS4GamepadPressButton(SQUARE, &PS4Gamepad); // BUTTON_X mapea a SQUARE
  } else {
    PS4GamepadReleaseButton(SQUARE, &PS4Gamepad);
  }

  if (touchRead(BUTTON_Y) > TOUCH_THRESHOLD) {
    PS4GamepadPressButton(TRIANGLE, &PS4Gamepad); // BUTTON_Y mapea a TRIANGLE
  } else {
    PS4GamepadReleaseButton(TRIANGLE, &PS4Gamepad);
  }

  if (touchRead(BUTTON_L) > TOUCH_THRESHOLD) {
    Serial.println("Boton L presionado");
    PS4GamepadPressButton(L1, &PS4Gamepad); // BUTTON_L mapea a L1
  } else {
    PS4GamepadReleaseButton(L1, &PS4Gamepad);
  }

  if (touchRead(BUTTON_R) > TOUCH_THRESHOLD) {
    Serial.println("Boton R presionado");
    PS4GamepadPressButton(R1, &PS4Gamepad); // BUTTON_R mapea a R1
  } else {
    PS4GamepadReleaseButton(R1, &PS4Gamepad);
  }

  if (touchRead(BUTTON_ZL) > TOUCH_THRESHOLD) {
    Serial.println("Boton ZL presionado");
    PS4GamepadPressButton(L2, &PS4Gamepad); // BUTTON_ZL mapea a L2
  } else {
    PS4GamepadReleaseButton(L2, &PS4Gamepad);
  }

  if (touchRead(BUTTON_ZR) > TOUCH_THRESHOLD) {
    Serial.println("Boton ZR presionado");
    PS4GamepadPressButton(R2, &PS4Gamepad); // BUTTON_ZR mapea a R2
  } else {
    PS4GamepadReleaseButton(R2, &PS4Gamepad);
  }

  if (touchRead(BUTTON_HOME) > TOUCH_THRESHOLD) {
    PS4GamepadPressButton(PS, &PS4Gamepad); // BUTTON_HOME mapea a PS
  } else {
    PS4GamepadReleaseButton(PS, &PS4Gamepad);
  }

  if (touchRead(BUTTON_CAPTURE) > TOUCH_THRESHOLD) {
    PS4GamepadPressButton(SHARE, &PS4Gamepad); // BUTTON_CAPTURE mapea a SHARE
  } else {
    PS4GamepadReleaseButton(SHARE, &PS4Gamepad);
  }

  if (touchRead(DPAD_UP) > TOUCH_THRESHOLD) {
    Serial.println("Boton DPAD-U presionado");
    PS4GamepadPressButton(UP, &PS4Gamepad);
  } else {
    PS4GamepadReleaseButton(UP, &PS4Gamepad);
  }

  if (touchRead(DPAD_DOWN) > TOUCH_THRESHOLD) {
    Serial.println("Boton DPAD-D presionado");
    PS4GamepadPressButton(DOWN, &PS4Gamepad);
  } else {
    PS4GamepadReleaseButton(DOWN, &PS4Gamepad);
  }

  if (touchRead(DPAD_LEFT) > TOUCH_THRESHOLD) {
    Serial.println("Boton DPAD-L presionado");
    PS4GamepadPressButton(LEFT, &PS4Gamepad);
  } else {
    PS4GamepadReleaseButton(LEFT, &PS4Gamepad);
  }

  if (touchRead(DPAD_RIGHT) > TOUCH_THRESHOLD) {
    Serial.println("Boton DPAD-R presionado");
    PS4GamepadPressButton(RIGHT, &PS4Gamepad);
  } else {
    PS4GamepadReleaseButton(RIGHT, &PS4Gamepad);
  }

  // Serializar los datos del mando PS4 para su envío
  PS4ProtocolSerializePS4GamepadData(PS4Gamepad, buffer);

  // Enviar el contenido del buffer por USB
  esp32USB.write(PS4_GAMEPAD_REPORT_SIZE, buffer);

  // Añadir un pequeño retraso para evitar envíos excesivamente rápidos
  delay(100);
}
