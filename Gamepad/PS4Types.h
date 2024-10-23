#ifndef PS4TYPES_H_
#define PS4TYPES_H_

#include "stdint.h"
#include "stddef.h"

// ========================================================
// Definiciones de Constantes para el D-Pad de PS4
// ========================================================

#define PS4GAMEPAD_DPAD_UP          0
#define PS4GAMEPAD_DPAD_UP_RIGHT    1
#define PS4GAMEPAD_DPAD_RIGHT       2
#define PS4GAMEPAD_DPAD_DOWN_RIGHT  3
#define PS4GAMEPAD_DPAD_DOWN        4
#define PS4GAMEPAD_DPAD_DOWN_LEFT   5
#define PS4GAMEPAD_DPAD_LEFT        6
#define PS4GAMEPAD_DPAD_UP_LEFT     7
#define PS4GAMEPAD_DPAD_CENTERED    0x08  // El estado neutro del Hat Switch

// ========================================================
// Tamaño del Reporte para PS4
// ========================================================

#define PS4_GAMEPAD_REPORT_SIZE 13 // Tamaño del reporte (ajustado según el descriptor HID)

// ========================================================
// Report Descriptor HID para PS4
// ========================================================

// El descriptor HID para el mando de PS4
static uint8_t PS4ReportDescriptor[] = {
    // Descriptor de ejemplo para el mando de PS4
    0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
    0x09, 0x05,        // Usage (Game Pad)
    0xA1, 0x01,        // Collection (Application)

    // ----------------- Botones ------------------------
    0x05, 0x09,        // Usage Page (Button)
    0x19, 0x01,        // Usage Minimum (Button 1)
    0x29, 0x0E,        // Usage Maximum (Button 14)
    0x15, 0x00,        // Logical Minimum (0)
    0x25, 0x01,        // Logical Maximum (1)
    0x95, 0x0E,        // Report Count (14 buttons)
    0x75, 0x01,        // Report Size (1 bit)
    0x81, 0x02,        // Input (Data,Var,Abs)

    0x95, 0x02,        // Report Count (2) - 2 bits de relleno
    0x75, 0x01,        // Report Size (1 bit)
    0x81, 0x01,        // Input (Const,Array,Abs)

    // ----------------- D-Pad (Hat Switch) ------------------------
    0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
    0x09, 0x39,        // Usage (Hat switch)
    0x15, 0x00,        // Logical Minimum (0)
    0x25, 0x07,        // Logical Maximum (7)
    0x35, 0x00,        // Physical Minimum (0)
    0x46, 0x3B, 0x01,  // Physical Maximum (315 grados)
    0x75, 0x04,        // Report Size (4 bits)
    0x95, 0x01,        // Report Count (1)
    0x65, 0x14,        // Unit (System: English Rotation, Centimeter)
    0x81, 0x42,        // Input (Data,Var,Abs,Null State)

    0x75, 0x04,        // Report Size (4 bits) - 4 bits de relleno
    0x95, 0x01,        // Report Count (1)
    0x81, 0x01,        // Input (Const,Array,Abs)

    // ----------------- Ejes analógicos ------------------------
    0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
    0x09, 0x30,        // Usage (X - Joystick izquierdo eje X)
    0x09, 0x31,        // Usage (Y - Joystick izquierdo eje Y)
    0x09, 0x32,        // Usage (Z - Joystick derecho eje X)
    0x09, 0x35,        // Usage (Rz - Joystick derecho eje Y)
    0x15, 0x00,        // Logical Minimum (0)
    0x26, 0xFF, 0x00,  // Logical Maximum (255)
    0x75, 0x08,        // Report Size (8 bits)
    0x95, 0x04,        // Report Count (4 ejes)
    0x81, 0x02,        // Input (Data,Var,Abs)

    0xC0               // End Collection
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
