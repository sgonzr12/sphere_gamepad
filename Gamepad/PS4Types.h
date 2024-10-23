#ifndef PS4TYPES_H_
#define PS4TYPES_H_

#include "stdint.h"
#include "stddef.h"

// ** Tipos de datos impuestos por el protocolo de la PS4 **

// Dpad directions
#define PS4GAMEPAD_DPAD_UP  0
#define PS4GAMEPAD_DPAD_UP_RIGHT 1
#define PS4GAMEPAD_DPAD_RIGHT 2
#define PS4GAMEPAD_DPAD_DOWN_RIGHT 3
#define PS4GAMEPAD_DPAD_DOWN 4
#define PS4GAMEPAD_DPAD_DOWN_LEFT 5
#define PS4GAMEPAD_DPAD_LEFT 6
#define PS4GAMEPAD_DPAD_UP_LEFT 7
#define PS4GAMEPAD_DPAD_CENTERED 0xF

// ** Tipos de datos impuestos por el protocolo de comunicacion USB OTG de la PS4 **

// Tamaño del mensaje del protocolo para gamepads de la PS4 (en bytes)
#define PS4_GAMEPAD_REPORT_SIZE 8

// Report descriptor.
// Datos binarios que especifican tipo de dispositivo y detalles de los informes (reports)
// que se enviaran por USB.
// Es imprescindible especificar este dato para que el dispositivo
// se identifique y funcione correctamente (quien utilice esta clase deberá hacerlo).
// HID report descriptor using TinyUSB's template
// Single Report (no ID) descriptor
static uint8_t PSReportDescriptor[] = {
  // Gamepad for PS4
  // 14 buttons, 1 8-way dpad
  0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
  0x09, 0x05,        // Usage (Game Pad)
  0xA1, 0x01,        // Collection (Application)
  0x15, 0x00,        //   Logical Minimum (0)
  0x25, 0x01,        //   Logical Maximum (1)
  0x35, 0x00,        //   Physical Minimum (0)
  0x46, 0x3B, 0x01,  //   Physical Maximum (315)    // 0x45, 0x01,        //   Physical Maximum (1)
  0x75, 0x01,        //   Report Size (1)
  0x95, 0x0E,        //   Report Count (14)
  0x05, 0x09,        //   Usage Page (Button)
  0x19, 0x01,        //   Usage Minimum (0x01)
  0x29, 0x0E,        //   Usage Maximum (0x0E)
  0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,    //?
                     //   Preferred State,No Null Position)
  0x95, 0x02,        //   Report Count (2)
  0x81, 0x02,        //   Input (Const,Array,Abs,No Wrap,Linear,    //
                     //   Preferred State,No Null Position)
  0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
  0x25, 0x07,        //   Logical Maximum (7)
  0x46, 0x3B, 0x01,  //   Physical Maximum (315)
  0x75, 0x04,        //   Report Size (4)
  0x95, 0x01,        //   Report Count (1)
  0x65, 0x14,        //   Unit (System: English Rotation, Length: Centimeter)
  0x09, 0x39,        //   Usage (Hat switch)
  0x81, 0x42,        //   Input (Data,Var,Abs,No Wrap,Linear,
                     //   Preferred State,Null State)
  0x65, 0x00,        //   Unit (None)
  0x95, 0x01,        //   Report Count (1)
  0x81, 0x02,        //   Input (Const,Array,Abs,No Wrap,Linear,    //?
                     //   Preferred State,No Null Position)
  0xC0,              // End Collection
};

// Estructura del mensaje (contenido del buffer) tal cual debe enviarse a la PS4,
// siguiendo su protocolo
// 14 Buttons, 1 D-Pad
typedef struct {
  uint8_t actionButtons; // Botones de acción
  uint8_t menuButtons;   // Botones del menú
  uint8_t dPad;          // D-Pad
  uint8_t filler;        // Espacio adicional
} tPSGamepadReportData;

// ** Tipos de datos definidos por nosotros (como queramos) **

typedef enum {NOT_PRESSED = 0, PRESSED} tPSButtonState;

typedef enum {
  Y = 0,
  B,
  A,
  X,
  L1,
  R1,
  L2,
  R2,
  SHARE,
  OPTIONS,
  UP,
  DOWN,
  LEFT,
  RIGHT,
  RESERVED_LAST_BUTTON_UNUSED
} tPSButtons;

typedef struct {
  tPSButtonState buttonsPressed[RESERVED_LAST_BUTTON_UNUSED];
  // Definir el resto de campos útiles según sea necesario
} tPSGamepad;

#endif
