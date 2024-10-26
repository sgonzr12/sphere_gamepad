#ifndef PS4PROTOCOL_H_
#define PS4PROTOCOL_H_

#include "PS4Types.h"

// Define the struct for action buttons
typedef struct {
  union {
      uint8_t value; // Botones de acción
      struct {
          uint8_t D_pad : 4; // bits para D-PAD
          uint8_t triangle : 1;   // bit para el estado del botón Triángulo
          uint8_t circle : 1; // bit para el estado del botón Círculo
          uint8_t X : 1;        // bit para el estado del botón X
          uint8_t square : 1;   // bit para el estado del botón Cuadrado
      } Parts;
  };
} ActionButtons;

// Define the struct for more buttons
typedef struct {
  union {
      uint8_t value; // otros botones
      struct {
          uint8_t L1 : 1; // bit para el estado del botón L1
          uint8_t R1 : 1; // bit para el estado del botón R1
          uint8_t L2 : 1; // bit para el estado del botón L2
          uint8_t R2 : 1; // bit para el estado del botón R2
          uint8_t SHARE : 1; // bit para el estado del botón SHARE
          uint8_t OPTIONS : 1; // bit para el estado del botón OPTIONS
          uint8_t padding : 2; // Relleno
      } Parts;
  };
} MoreButtons;

// Function declarations
int PS4ProtocolDPadButtonsToInt(int up, int down, int left, int right);
void PS4ProtocolReportDataSetButtons(tPSGamepad psGamepad, tPSGamepadReportData* psGamepadReportData);
void PS4ProtocolSerializePSGamepadData(tPSGamepad psGamepad, uint8_t buffer[PS4_GAMEPAD_REPORT_SIZE]);

#endif // PS4PROTOCOL_H_