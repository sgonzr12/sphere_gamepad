#include "PS4Types.h"

/**
 * @brief Marca un botón específico como presionado en el mando de PS4.
 *
 * @param buttonIndex   Índice del botón a presionar, basado en la enumeración tPS4Buttons.
 * @param PS4Gamepad    Puntero a la estructura del mando de PS4.
 */
void PS4GamepadPressButton(tPS4Buttons buttonIndex, tPS4Gamepad* PS4Gamepad) {
    if (buttonIndex < RESERVED_LAST_BUTTON_UNUSED) {
        PS4Gamepad->buttonsPressed[buttonIndex] = PRESSED;
    }
}

/**
 * @brief Marca un botón específico como no presionado en el mando de PS4.
 *
 * @param buttonIndex   Índice del botón a liberar, basado en la enumeración tPS4Buttons.
 * @param PS4Gamepad    Puntero a la estructura del mando de PS4.
 */
void PS4GamepadReleaseButton(tPS4Buttons buttonIndex, tPS4Gamepad* PS4Gamepad) {
    if (buttonIndex < RESERVED_LAST_BUTTON_UNUSED) {
        PS4Gamepad->buttonsPressed[buttonIndex] = NOT_PRESSED;
    }
}

/**
 * @brief Libera todos los botones del mando de PS4, marcándolos como no presionados.
 *
 * @param PS4Gamepad    Puntero a la estructura del mando de PS4.
 */
void PS4GamepadReleaseAllButtons(tPS4Gamepad* PS4Gamepad) {
    for (int i = 0; i < RESERVED_LAST_BUTTON_UNUSED; i++) {
        PS4Gamepad->buttonsPressed[i] = NOT_PRESSED;
    }
}

// TO DO: Implementar funciones adicionales para otras funcionalidades del mando de PS4,
// como manejar los ejes de los joysticks, gatillos analógicos, touchpad, etc.
