#include "PS4Protocol.h"

// Enumeración de botones para el mando de PS4
typedef enum {
    CROSS = 0,
    CIRCLE,
    SQUARE,
    TRIANGLE,
    L1,
    R1,
    L2,
    R2,
    SHARE,
    OPTIONS,
    L3,
    R3,
    PS,
    TOUCHPAD
} tPS4Buttons;

// Estructura del mando de PS4
typedef struct {
    bool buttonsPressed[14]; // Array de botones según la enumeración tPS4Buttons
    // Agrega otros campos si es necesario, como los valores de los joysticks
} tPS4Gamepad;

// Estructura del reporte de datos del mando de PS4
typedef struct {
    uint8_t actionButtons;
    uint8_t menuButtons;
    uint8_t dPad;
    uint8_t leftXAxis;
    uint8_t leftYAxis;
    uint8_t rightXAxis;
    uint8_t rightYAxis;
    uint8_t filler;
} tPS4GamepadReportData;

// Función para convertir los botones del D-Pad a un byte
void PS4ProtocolDPadButtonsToByte(int up, int down, int left, int right, uint8_t* byte) {
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
        *byte = PS4GAMEPAD_DPAD_CENTERED;
    }
}

// Función para establecer los botones del reporte de PS4
void PS4ProtocolReportDataSetButtons(tPS4Gamepad PS4Gamepad, tPS4GamepadReportData* PS4GamepadReportData) {
    PS4GamepadReportData->actionButtons = 0x00;
    for (int i = CROSS; i <= R2; i++) {
        PS4GamepadReportData->actionButtons |= (uint8_t)(PS4Gamepad.buttonsPressed[i] << i);
    }

    PS4GamepadReportData->menuButtons = 0x00;
    for (int i = SHARE; i <= TOUCHPAD; i++) {
        PS4GamepadReportData->menuButtons |= (uint8_t)(PS4Gamepad.buttonsPressed[i] << (i - SHARE));
    }
}

// Función para establecer valores por defecto del reporte de PS4
void PS4ProtocolReportDataSetDefaultValues(tPS4GamepadReportData* PS4GamepadReportData) {
    PS4GamepadReportData->actionButtons  = 0x00;
    PS4GamepadReportData->menuButtons    = 0x00;
    PS4GamepadReportData->dPad           = PS4GAMEPAD_DPAD_CENTERED;
    PS4GamepadReportData->leftXAxis      = 0x80;
    PS4GamepadReportData->leftYAxis      = 0x80;
    PS4GamepadReportData->rightXAxis     = 0x80;
    PS4GamepadReportData->rightYAxis     = 0x80;
    PS4GamepadReportData->filler         = 0x00;
}

// Función para serializar los datos del mando de PS4
#define PS4_GAMEPAD_REPORT_SIZE 8

void PS4ProtocolSerializePS4GamepadData(tPS4Gamepad PS4Gamepad, uint8_t buffer[PS4_GAMEPAD_REPORT_SIZE]) {
    tPS4GamepadReportData PS4GamepadReportData;

    // Establecer valores por defecto
    PS4ProtocolReportDataSetDefaultValues(&PS4GamepadReportData);

    // Establecer botones
    PS4ProtocolReportDataSetButtons(PS4Gamepad, &PS4GamepadReportData);

    // Aquí puedes agregar la lógica para el D-Pad y los joysticks si es necesario
    // Por ejemplo:
    // PS4ProtocolDPadButtonsToByte(up, down, left, right, &PS4GamepadReportData.dPad);
    // PS4GamepadReportData.leftXAxis = ...;
    // PS4GamepadReportData.leftYAxis = ...;
    // PS4GamepadReportData.rightXAxis = ...;
    // PS4GamepadReportData.rightYAxis = ...;

    // Serializar los datos en el buffer
    buffer[0] = PS4GamepadReportData.actionButtons;
    buffer[1] = PS4GamepadReportData.menuButtons;
    buffer[2] = PS4GamepadReportData.dPad;
    buffer[3] = PS4GamepadReportData.leftXAxis;
    buffer[4] = PS4GamepadReportData.leftYAxis;
    buffer[5] = PS4GamepadReportData.rightXAxis;
    buffer[6] = PS4GamepadReportData.rightYAxis;
    buffer[7] = PS4GamepadReportData.filler;
}
