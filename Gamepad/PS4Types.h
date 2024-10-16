#ifndef PS4TYPES_H_
#define PS4TYPES_H_

#include "stdint.h"
#include "stddef.h"

// ** Tipos de datos impuestos por el protocolo de la PlayStation 4 (sacados de la documentación) **
// Direcciones del D-Pad
#define PS4GAMEPAD_DPAD_UP          0
#define PS4GAMEPAD_DPAD_UP_RIGHT    1
#define PS4GAMEPAD_DPAD_RIGHT       2
#define PS4GAMEPAD_DPAD_DOWN_RIGHT  3
#define PS4GAMEPAD_DPAD_DOWN        4
#define PS4GAMEPAD_DPAD_DOWN_LEFT   5
#define PS4GAMEPAD_DPAD_LEFT        6
#define PS4GAMEPAD_DPAD_UP_LEFT     7
#define PS4GAMEPAD_DPAD_CENTERED    0xF

// ** Tipos de datos impuestos por el protocolo de comunicación USB HID de la PlayStation 4 **

// Tamaño del mensaje del protocolo para gamepads de la PlayStation 4 (en bytes)
#define PS4_GAMEPAD_REPORT_SIZE 20

// Report descriptor.
// Datos binarios que especifican tipo de dispositivo y detalles de los informes (reports) 
// que se enviarán por USB.
// Es imprescindible especificar este dato para que el dispositivo 
// se identifique y funcione correctamente (quien utilice esta clase deberá hacerlo).
// HID report descriptor para mando de PlayStation 4
static uint8_t PS4ReportDescriptor[] = {
    // Descriptor de ejemplo para mando de PS4
    0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
    0x09, 0x05,        // Usage (Game Pad)
    0xA1, 0x01,        // Collection (Application)
    0x15, 0x00,        //   Logical Minimum (0)
    0x25, 0x01,        //   Logical Maximum (1)
    0x35, 0x00,        //   Physical Minimum (0)
    0x45, 0x01,        //   Physical Maximum (1)
    0x75, 0x01,        //   Report Size (1)
    0x95, 0x14,        //   Report Count (20)
    0x05, 0x09,        //   Usage Page (Button)
    0x19, 0x01,        //   Usage Minimum (0x01)
    0x29, 0x14,        //   Usage Maximum (0x14)
    0x81, 0x02,        //   Input (Data,Var,Abs)
    0x95, 0x02,        //   Report Count (2)
    0x81, 0x03,        //   Input (Cnst,Var,Abs)
    0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
    0x09, 0x30,        //   Usage (X)
    0x09, 0x31,        //   Usage (Y)
    0x09, 0x32,        //   Usage (Z)
    0x09, 0x35,        //   Usage (Rz)
    0x15, 0x00,        //   Logical Minimum (0)
    0x26, 0xFF, 0x00,  //   Logical Maximum (255)
    0x75, 0x08,        //   Report Size (8)
    0x95, 0x04,        //   Report Count (4)
    0x81, 0x02,        //   Input (Data,Var,Abs)
    0xC0               // End Collection
};

// Estructura del mensaje (contenido del buffer) tal cual debe enviarse a la PlayStation 4,
// siguiendo su protocolo
// 20 Bytes de reporte que incluyen botones, ejes, y otros controles
typedef struct {
    uint8_t buttons[3];        // 24 botones (cada bit representa un botón, 3 bytes)
    uint8_t dPad;               // Estado del D-Pad
    uint8_t reserved;           // Byte reservado
    uint8_t leftXAxis;          // Eje X del joystick izquierdo
    uint8_t leftYAxis;          // Eje Y del joystick izquierdo
    uint8_t rightXAxis;         // Eje X del joystick derecho
    uint8_t rightYAxis;         // Eje Y del joystick derecho
    uint8_t leftTrigger;        // Gatillo izquierdo (analogico)
    uint8_t rightTrigger;       // Gatillo derecho (analogico)
    uint8_t touchpad;           // Estado del touchpad
} tPS4GamepadReportData;

// ** Tipos de datos definidos por nosotros (como queramos) **

// Estado de los botones
typedef enum {NOT_PRESSED = 0, PRESSED} tPS4ButtonState;

// Enumeración de botones para el mando de PS4
typedef enum {
    CROSS = 0,         // Botón Cross (X)
    CIRCLE,            // Botón Circle (O)
    SQUARE,            // Botón Square (□)
    TRIANGLE,          // Botón Triangle (Δ)
    L1,                // Botón L1
    R1,                // Botón R1
    L2,                // Botón L2 (gatillo analógico izquierdo)
    R2,                // Botón R2 (gatillo analógico derecho)
    SHARE,             // Botón Share
    OPTIONS,           // Botón Options
    L3,                // Botón L3 (Joystick izquierdo presionado)
    R3,                // Botón R3 (Joystick derecho presionado)
    PS,                // Botón PS
    TOUCHPAD,          // Botón Touchpad
    UP,                // Dirección D-Pad Arriba
    DOWN,              // Dirección D-Pad Abajo
    LEFT,              // Dirección D-Pad Izquierda
    RIGHT,             // Dirección D-Pad Derecha
    RESERVED_LAST_BUTTON_UNUSED
} tPS4Buttons;

// TO DO: Completar
typedef struct {
    tPS4ButtonState buttonsPressed[RESERVED_LAST_BUTTON_UNUSED];

    // Definir el resto de campos útiles
    uint8_t dPadUp;
    uint8_t dPadDown;
    uint8_t dPadLeft;
    uint8_t dPadRight;

    uint8_t leftXAxis;
    uint8_t leftYAxis;
    uint8_t rightXAxis;
    uint8_t rightYAxis;

    uint8_t leftTrigger;
    uint8_t rightTrigger;

    uint8_t touchpadPressed;
    // Agrega otros campos si es necesario
} tPS4Gamepad;

#endif // PSTYPES_H_
