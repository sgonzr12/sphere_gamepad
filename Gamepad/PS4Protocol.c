#include "PS4Protocol.h"

// Función que devuelve un byte (8 bits) indicando el estado del D-PAD a partir
// del estado de pulsación de cada uno de sus botones.
// La dirección del D-PAD se ajusta a los requisitos del mando de PS4.
int PS4ProtocolDPadButtonsToInt(int up, int down, int left, int right) {
    // Se verifica cada combinación válida y se asigna el valor correspondiente a *byte.
    if (up && !down && !left && !right) {
        return PS4GAMEPAD_DPAD_UP;
    } else if (up && !down && !left && right) {
        return PS4GAMEPAD_DPAD_UP_RIGHT;
    } else if (!up && !down && !left && right) {
        return PS4GAMEPAD_DPAD_RIGHT;
    } else if (!up && down && !left && right) {
        return PS4GAMEPAD_DPAD_DOWN_RIGHT;
    } else if (!up && down && !left && !right) {
        return PS4GAMEPAD_DPAD_DOWN;
    } else if (!up && down && left && !right) {
        return PS4GAMEPAD_DPAD_DOWN_LEFT;
    } else if (!up && !down && left && !right) {
        return PS4GAMEPAD_DPAD_LEFT;
    } else if (up && !down && left && !right) {
        return PS4GAMEPAD_DPAD_UP_LEFT;
    } else {
        // Si la combinación no es válida, se centra el D-Pad.
        return PS4GAMEPAD_DPAD_CENTERED;
    }
}

// Función que rellena los campos actionsButtons y moreButtons del report de datos
// El primer byte representa el estado de los botones de acción del mando PS4.
void PS4ProtocolReportDataSetButtons(tPSGamepad psGamepad, tPSGamepadReportData* psGamepadReportData) {

    // Se inicializa el byte de los botones de acción
    psGamepadReportData->actionButtons = 0;

    // Inicializar union actionButtons a 0
    ActionButtons actionButtons;
    actionButtons.value = 0;

    int up = psGamepad.buttonsPressed[UP];
    int down = psGamepad.buttonsPressed[DOWN];
    int left = psGamepad.buttonsPressed[LEFT];
    int right = psGamepad.buttonsPressed[RIGHT];

    int DPad = PS4ProtocolDPadButtonsToInt(up, down, left, right);

    // Se asigna el valor correspondiente al D-Pad
    actionButtons.Parts.D_pad = DPad;

    // Se asigna el valor correspondiente a cada botón de acción
    if (psGamepad.buttonsPressed[TRIANGLE] == PRESSED) {
        actionButtons.Parts.triangle = 1;
    }
    if (psGamepad.buttonsPressed[CIRCLE] == PRESSED) {
        actionButtons.Parts.circle = 1;
    }
    if (psGamepad.buttonsPressed[X] == PRESSED) {
        actionButtons.Parts.X = 1;
    }
    if (psGamepad.buttonsPressed[SQUARE] == PRESSED) {
        actionButtons.Parts.square = 1; 
    }

    // Se asigna el valor de la union a la estructura
    psGamepadReportData->actionButtons = actionButtons.value;

    // inicializar union moreButtons a 0
    psGamepadReportData->moreButtons = 0;

    // inicializar union MOREbuttons a 0
    MoreButtons moreButtons;
    moreButtons.value = 0;

    // Se asigna el valom correspondiente a cada botón adicional
    if (psGamepad.buttonsPressed[L1] == PRESSED) {
        moreButtons.Parts.L1 = 1;
    }
    if (psGamepad.buttonsPressed[R1] == PRESSED) {
        moreButtons.Parts.R1 = 1;
    }
    if (psGamepad.buttonsPressed[L2] == PRESSED) {
        moreButtons.Parts.L2 = 1;
    }
    if (psGamepad.buttonsPressed[R2] == PRESSED) {
        moreButtons.Parts.R2 = 1;
    }
    if (psGamepad.buttonsPressed[SHARE] == PRESSED) {
        moreButtons.Parts.SHARE = 1;
    }
    if (psGamepad.buttonsPressed[OPTIONS] == PRESSED) {
        moreButtons.Parts.OPTIONS = 1;
    }

    // Se asigna el valor de la union a la estructura
    //psGamepadReportData->moreButtons = moreButtons.value;
    
}

// Valores por defecto del report que se envía al PS4
void PS4ProtocolReportDataSetDefaultValues(tPSGamepadReportData* psGamepadReportData) {

    // Se inicializan los valores por defecto del report
    psGamepadReportData->info = 0;
    psGamepadReportData->x = 0;
    psGamepadReportData->y = 0;
    psGamepadReportData->z = 0;
    psGamepadReportData->rz = 0;
    psGamepadReportData->actionButtons = 0;
    psGamepadReportData->moreButtons = 0;

}

// Serializa los datos del mando PS4 en un buffer.
void PS4ProtocolSerializePSGamepadData(tPSGamepad psGamepad, uint8_t buffer[PS4_GAMEPAD_REPORT_SIZE]) {
    tPSGamepadReportData psGamepadReportData;

    // Cargamos los valores por defecto del report
    PS4ProtocolReportDataSetDefaultValues(&psGamepadReportData);

    // Rellenamos los botones de acción y de menú
    PS4ProtocolReportDataSetButtons(psGamepad, &psGamepadReportData);

    // Serializamos los campos manualmente en el buffer
    buffer[0] = psGamepadReportData.info;         // Información adicional
    buffer[1] = psGamepadReportData.x;            // Eje X
    buffer[2] = psGamepadReportData.y;            // Eje Y
    buffer[3] = psGamepadReportData.z;            // Eje Z
    buffer[4] = psGamepadReportData.rz;           // Eje Rz
    buffer[5] = psGamepadReportData.actionButtons; // Botones de acción
    buffer[6] = psGamepadReportData.moreButtons;   // Botones de menú
}
