#include "PS4Gamepad.h"

// Función para marcar un botón como presionado
void PS4GamepadPressButton(tPSButtons buttonIndex, tPSGamepad* psGamepad) {
    psGamepad->buttonsPressed[buttonIndex] = PRESSED;
}

// Función para marcar un botón como no presionado
void PS4GamepadReleaseButton(tPSButtons buttonIndex, tPSGamepad* psGamepad) {
    psGamepad->buttonsPressed[buttonIndex] = NOT_PRESSED;
}

// Función para liberar todos los botones
void PS4GamepadReleaseAllButtons(tPSGamepad* psGamepad) {
    int i = 0;

    for (i = 0; i < RESERVED_LAST_BUTTON_UNUSED; i++) {
        psGamepad->buttonsPressed[i] = NOT_PRESSED;
    }
}

// TO DO: Resto de botones y funcionalidades
