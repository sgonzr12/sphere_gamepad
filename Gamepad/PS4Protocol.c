#include "PS4Protocol.h"

// Función que devuelve un byte (8 bits) indicando el estado del D-PAD a partir
// del estado de pulsación de cada uno de sus botones.
// La dirección del D-PAD se ajusta a los requisitos del mando de PS4.
void PS4ProtocolDPadButtonsToByte(int up, int down, int left, int right, uint8_t* byte) {
    // Se verifica cada combinación válida y se asigna el valor correspondiente a *byte.
    if (up && !down && !left && !right) {
        *byte = PS4GAMEPAD_DPAD_UP;
    } else if (up && !down && !left && right) {
        *byte = PS4GAMEPAD_DPAD_UP_RIGHT;
    } else if (!up && !down && !left && right) {
        *byte = PS4GAMEPAD_DPAD_RIGHT;
    } else if (!up && down && !left && right) {
        *byte = PS4GAMEPAD_DPAD_DOWN_RIGHT;
    } else if (!up && down && !left && !right) {
        *byte = PS4GAMEPAD_DPAD_DOWN;
    } else if (!up && down && left && !right) {
        *byte = PS4GAMEPAD_DPAD_DOWN_LEFT;
    } else if (!up && !down && left && !right) {
        *byte = PS4GAMEPAD_DPAD_LEFT;
    } else if (up && !down && left && !right) {
        *byte = PS4GAMEPAD_DPAD_UP_LEFT;
    } else {
        // Si la combinación no es válida, se centra el D-Pad.
        *byte = PS4GAMEPAD_DPAD_CENTERED;
    }
}

// Función que rellena los campos actionButtons y menuButtons de psGamepadReportData.
// El primer byte representa el estado de los botones de acción del mando PS4.
void PS4ProtocolReportDataSetButtons(tPSGamepad psGamepad, tPSGamepadReportData* psGamepadReportData) {
    // Inicializamos actionButtons a 0
    psGamepadReportData->actionButtons = 0x00;

    // Asignamos los botones de acción (por ejemplo, X, O, Cuadrado, Triángulo)
    for (int i = X; i <= OPTIONS; i++) {
        psGamepadReportData->actionButtons |= (uint8_t)(psGamepad.buttonsPressed[i] << i);
    }

    // Inicializamos menuButtons a 0
    psGamepadReportData->menuButtons = 0x00;

    // Asignamos los botones de menú (por ejemplo, SHARE, OPTIONS)
    // (ajusta según los botones específicos del PS4)
    for (int i = SHARE; i <= OPTIONS; i++) {
        psGamepadReportData->menuButtons |= (uint8_t)(psGamepad.buttonsPressed[i] << (i - SHARE));
    }
}

// Valores por defecto del report que se envía al PS4
void PS4ProtocolReportDataSetDefaultValues(tPSGamepadReportData* psGamepadReportData) {
    psGamepadReportData->actionButtons = 0x00;
    psGamepadReportData->menuButtons = 0x00;
    psGamepadReportData->dPad = PS4GAMEPAD_DPAD_CENTERED; // Valor centrado
    psGamepadReportData->filler = 0x00; // Relleno
}

// Serializa los datos del mando PS4 en un buffer.
void PS4ProtocolSerializePSGamepadData(tPSGamepad psGamepad, uint8_t buffer[PS4_GAMEPAD_REPORT_SIZE]) {
    tPSGamepadReportData psGamepadReportData;

    // Cargamos los valores por defecto del report
    PS4ProtocolReportDataSetDefaultValues(&psGamepadReportData);

    // Rellenamos los botones de acción y de menú
    PS4ProtocolReportDataSetButtons(psGamepad, &psGamepadReportData);

    // Serializamos los campos manualmente en el buffer
    buffer[0] = psGamepadReportData.actionButtons; // Botones de acción
    buffer[1] = psGamepadReportData.menuButtons;   // Botones de menú
    buffer[2] = psGamepadReportData.dPad;          // D-Pad
    buffer[3] = psGamepadReportData.filler;        // Relleno
}
