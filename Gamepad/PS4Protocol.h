#ifndef PS4PROTOCOL_H_
#define PS4PROTOCOL_H_

#include "PS4Types.h"

// Funcion que devuelve un byte (8 bits) indicando el estado del D-PAD a partir
// del estado de pulsacion de cada uno de sus botones
void PS4ProtocolDPadButtonsToByte(int up, int down, int left, int right, uint8_t* byte);

// Funcion que devueve en dos bytes (16 bits) el estado de los primeros 14 botones
// del tipo tNSButtons
void PS4ProtocolButtonsToBytes (tPS4Gamepad PS4Gamepad,  uint16_t* twoBytes);

// Serializacion de la estructura que contiene las informacion de los botones pulsados
// (para su posterior envio a la PS4 por USB)
void PS4ProtocolSerializePS4GamepadData (tPS4Gamepad PS4Gamepad, uint8_t buffer [PS4_GAMEPAD_REPORT_SIZE]);

#endif // PS4PROTOCOL_H_