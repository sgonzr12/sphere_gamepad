#ifndef PS4PROTOCOL_H_
#define PS4PROTOCOL_H_

#include "PS4Types.h"

// Función que devuelve un byte (8 bits) indicando el estado del D-PAD a partir
// del estado de pulsación de cada uno de sus botones
void PS4ProtocolDPadButtonsToByte(int up, int down, int left, int right, uint8_t* byte);

// Función que devuelve en dos bytes (16 bits) el estado de los primeros 14 botones
// del tipo tPSButtons
void PS4ProtocolButtonsToBytes(tPSGamepad psGamepad, uint16_t* twoBytes);

// Serialización de la estructura que contiene la información de los botones pulsados
// (para su posterior envío a la PS4 por USB)
void PS4ProtocolSerializePSGamepadData(tPSGamepad psGamepad, uint8_t buffer[PS4_GAMEPAD_REPORT_SIZE]);

#endif // PS4PROTOCOL_H_
