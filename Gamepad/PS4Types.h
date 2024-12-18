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
  0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
  0x09, 0x05,        // Usage (Game Pad)
  0xA1, 0x01,        // Collection (Application)
  0x85, 0x01,        // Report ID (1)
  0x09, 0x30,        // Usage (X)
  0x09, 0x31,        // Usage (Y)
  0x09, 0x32,        // Usage (Z)
  0x09, 0x35,        // Usage (Rz)
  0x15, 0x00,        // Logical Minimum (0)
  0x26, 0xFF, 0x00,  // Logical Maximum (255)
  0x75, 0x08,        // Report Size (8)
  0x95, 0x04,        // Report Count (4)
  0x81, 0x02,        // Input (Data,Var,Abs)
  0x09, 0x39,        // Usage (Hat switch)
  0x15, 0x00,        // Logical Minimum (0)
  0x25, 0x07,        // Logical Maximum (7)
  0x35, 0x00,        // Physical Minimum (0)
  0x46, 0x3B, 0x01,  // Physical Maximum (315)
  0x65, 0x14,        // Unit (System: English Rotation, Centimeter)
  0x75, 0x04,        // Report Size (4)
  0x95, 0x01,        // Report Count (1)
  0x81, 0x42,        // Input (Data,Var,Abs,Null State)
  0x65, 0x00,        // Unit (None)
  0x05, 0x09,        // Usage Page (Button)
  0x19, 0x01,        // Usage Minimum (Button 1)
  0x29, 0x0E,        // Usage Maximum (Button 14)
  0x15, 0x00,        // Logical Minimum (0)
  0x25, 0x01,        // Logical Maximum (1)
  0x75, 0x01,        // Report Size (1)
  0x95, 0x0E,        // Report Count (14)
  0x81, 0x02,        // Input (Data,Var,Abs)
  0x06, 0x00, 0xFF,  // Usage Page (Vendor Defined 0xFF00)
  0x09, 0x20,        // Usage (0x20)
  0x75, 0x06,        // Report Size (6)
  0x95, 0x01,        // Report Count (1)
  0x15, 0x00,        // Logical Minimum (0)
  0x25, 0x7F,        // Logical Maximum (127)
  0x81, 0x02,        // Input (Data,Var,Abs)
  0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
  0x09, 0x33,        // Usage (Rx)
  0x09, 0x34,        // Usage (Ry)
  0x15, 0x00,        // Logical Minimum (0)
  0x26, 0xFF, 0x00,  // Logical Maximum (255)
  0x75, 0x08,        // Report Size (8)
  0x95, 0x02,        // Report Count (2)
  0x81, 0x02,        // Input (Data,Var,Abs)
  0x06, 0x00, 0xFF,  // Usage Page (Vendor Defined 0xFF00)
  0x09, 0x21,        // Usage (0x21)
  0x95, 0x36,        // Report Count (54)
  0x81, 0x02,        // Input (Data,Var,Abs)
  0x85, 0x05,        // Report ID (5)
  0x09, 0x22,        // Usage (0x22)
  0x95, 0x1F,        // Report Count (31)
  0x91, 0x02,        // Output (Data,Var,Abs)
  0x85, 0x04,        // Report ID (4)
  0x09, 0x23,        // Usage (0x23)
  0x95, 0x24,        // Report Count (36)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x02,        // Report ID (2)
  0x09, 0x24,        // Usage (0x24)
  0x95, 0x24,        // Report Count (36)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x08,        // Report ID (8)
  0x09, 0x25,        // Usage (0x25)
  0x95, 0x03,        // Report Count (3)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x10,        // Report ID (16)
  0x09, 0x26,        // Usage (0x26)
  0x95, 0x04,        // Report Count (4)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x11,        // Report ID (17)
  0x09, 0x27,        // Usage (0x27)
  0x95, 0x02,        // Report Count (2)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x12,        // Report ID (18)
  0x06, 0x02, 0xFF,  // Usage Page (Vendor Defined 0xFF02)
  0x09, 0x21,        // Usage (0x21)
  0x95, 0x0F,        // Report Count (15)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x13,        // Report ID (19)
  0x09, 0x22,        // Usage (0x22)
  0x95, 0x16,        // Report Count (22)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x14,        // Report ID (20)
  0x06, 0x05, 0xFF,  // Usage Page (Vendor Defined 0xFF05)
  0x09, 0x20,        // Usage (0x20)
  0x95, 0x10,        // Report Count (16)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x15,        // Report ID (21)
  0x09, 0x21,        // Usage (0x21)
  0x95, 0x2C,        // Report Count (44)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x06, 0x80, 0xFF,  // Usage Page (Vendor Defined 0xFF80)
  0x85, 0x80,        // Report ID (128)
  0x09, 0x20,        // Usage (0x20)
  0x95, 0x06,        // Report Count (6)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x81,        // Report ID (129)
  0x09, 0x21,        // Usage (0x21)
  0x95, 0x06,        // Report Count (6)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x82,        // Report ID (130)
  0x09, 0x22,        // Usage (0x22)
  0x95, 0x05,        // Report Count (5)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x83,        // Report ID (131)
  0x09, 0x23,        // Usage (0x23)
  0x95, 0x01,        // Report Count (1)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x84,        // Report ID (132)
  0x09, 0x24,        // Usage (0x24)
  0x95, 0x04,        // Report Count (4)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x85,        // Report ID (133)
  0x09, 0x25,        // Usage (0x25)
  0x95, 0x06,        // Report Count (6)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x86,        // Report ID (134)
  0x09, 0x26,        // Usage (0x26)
  0x95, 0x06,        // Report Count (6)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x87,        // Report ID (135)
  0x09, 0x27,        // Usage (0x27)
  0x95, 0x23,        // Report Count (35)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x88,        // Report ID (136)
  0x09, 0x28,        // Usage (0x28)
  0x95, 0x22,        // Report Count (34)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x89,        // Report ID (137)
  0x09, 0x29,        // Usage (0x29)
  0x95, 0x02,        // Report Count (2)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x90,        // Report ID (144)
  0x09, 0x30,        // Usage (0x30)
  0x95, 0x05,        // Report Count (5)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x91,        // Report ID (145)
  0x09, 0x31,        // Usage (0x31)
  0x95, 0x03,        // Report Count (3)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x92,        // Report ID (146)
  0x09, 0x32,        // Usage (0x32)
  0x95, 0x03,        // Report Count (3)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0x93,        // Report ID (147)
  0x09, 0x33,        // Usage (0x33)
  0x95, 0x0C,        // Report Count (12)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xA0,        // Report ID (160)
  0x09, 0x40,        // Usage (0x40)
  0x95, 0x06,        // Report Count (6)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xA1,        // Report ID (161)
  0x09, 0x41,        // Usage (0x41)
  0x95, 0x01,        // Report Count (1)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xA2,        // Report ID (162)
  0x09, 0x42,        // Usage (0x42)
  0x95, 0x01,        // Report Count (1)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xA3,        // Report ID (163)
  0x09, 0x43,        // Usage (0x43)
  0x95, 0x30,        // Report Count (48)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xA4,        // Report ID (164)
  0x09, 0x44,        // Usage (0x44)
  0x95, 0x0D,        // Report Count (13)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xA5,        // Report ID (165)
  0x09, 0x45,        // Usage (0x45)
  0x95, 0x15,        // Report Count (21)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xA6,        // Report ID (166)
  0x09, 0x46,        // Usage (0x46)
  0x95, 0x15,        // Report Count (21)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xF0,        // Report ID (240)
  0x09, 0x47,        // Usage (0x47)
  0x95, 0x3F,        // Report Count (63)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xF1,        // Report ID (241)
  0x09, 0x48,        // Usage (0x48)
  0x95, 0x3F,        // Report Count (63)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xF2,        // Report ID (242)
  0x09, 0x49,        // Usage (0x49)
  0x95, 0x0F,        // Report Count (15)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xA7,        // Report ID (167)
  0x09, 0x4A,        // Usage (0x4A)
  0x95, 0x01,        // Report Count (1)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xA8,        // Report ID (168)
  0x09, 0x4B,        // Usage (0x4B)
  0x95, 0x01,        // Report Count (1)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xA9,        // Report ID (169)
  0x09, 0x4C,        // Usage (0x4C)
  0x95, 0x08,        // Report Count (8)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xAA,        // Report ID (170)
  0x09, 0x4E,        // Usage (0x4E)
  0x95, 0x01,        // Report Count (1)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xAB,        // Report ID (171)
  0x09, 0x4F,        // Usage (0x4F)
  0x95, 0x39,        // Report Count (57)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xAC,        // Report ID (172)
  0x09, 0x50,        // Usage (0x50)
  0x95, 0x39,        // Report Count (57)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xAD,        // Report ID (173)
  0x09, 0x51,        // Usage (0x51)
  0x95, 0x0B,        // Report Count (11)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xAE,        // Report ID (174)
  0x09, 0x52,        // Usage (0x52)
  0x95, 0x01,        // Report Count (1)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xAF,        // Report ID (175)
  0x09, 0x53,        // Usage (0x53)
  0x95, 0x02,        // Report Count (2)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
  0x85, 0xB0,        // Report ID (176)
  0x09, 0x54,        // Usage (0x54)
  0x95, 0x3F,        // Report Count (63)
  0xB1, 0x02,        // Feature (Data,Var,Abs)
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
