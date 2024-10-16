#include "NSProtocol.h"

// Funcion que devuelve un byte (8 bits) indicando el estado del D-PAD a partir
// del estado de pulsacion de cada uno de sus botones.
// Sacado directamente de los protocolos de la NS:
// Hay combinaciones no validas, que deben sustituirse por "centrado":
// The direction pad is limited to 8 directions plus centered. This means
// some combinations of 4 dpad buttons are not valid and cannot be sent.
// Button down = true(1)
// Valid: Any 1 button down, any 2 adjacent buttons down, no buttons down
// Invalid: all other combinations.
// ej3: Pulsado arriba y abajo => esta combinacion no es valida
// por lo que debe sustituirse por centrado
void NSProtocolDPadButtonsToByte(int up, int down, int left, int right, uint8_t* byte) {

	// Se verifica cada combinación válida y se asigna el valor correspondiente a *byte.
	if (up && !down && !left && !right) {
		*byte = NSGAMEPAD_DPAD_UP;
	} else if (up && !down && !left && right) {
		*byte = NSGAMEPAD_DPAD_UP_RIGHT;
	} else if (!up && !down && !left && right) {
		*byte = NSGAMEPAD_DPAD_RIGHT;
	} else if (!up && down && !left && right) {
		*byte = NSGAMEPAD_DPAD_DOWN_RIGHT;
	} else if (!up && down && !left && !right) {
		*byte = NSGAMEPAD_DPAD_DOWN;
	} else if (!up && down && left && !right) {
		*byte = NSGAMEPAD_DPAD_DOWN_LEFT;
	} else if (!up && !down && left && !right) {
		*byte = NSGAMEPAD_DPAD_LEFT;
	} else if (up && !down && left && !right) {
		*byte = NSGAMEPAD_DPAD_UP_LEFT;
	} else {
		// Si la combinación no es válida, se centra el D-Pad.
		*byte = NSGAMEPAD_DPAD_CENTERED;
	}
}


// Funcion que rellena los campos actionButtons y menuButtos de nsGamepad.
// El primer byte representa el estado de los primeros 8 botones (los de accion)
// del tipo tNSButtons.
// Estos botones ya se definieron en este mismo orden en el tipo enumerado tNSButtons de NSTypes.h:
//  Y B A X L R ZL ZR 
// Cada bit representa si el boton correspondiente esta pulsado (1) o no lo esta (0).
// El peso del bit coincide con la posicion del boton en el enumerado (el boton Y va en el 0, el B en el 1...).
// Ejemplo: Si solo esta pulsado el boton B, es decir, el de indice 1, y el resto no lo estan,
 // la secuenca seria: 00000010
 // El segundo byte, menuButtons, corresponde al estado de los botones:
 // MINUS PLUS LEFT_STICK RIGHT_STICK HOME CAPTURE
 // (seis botones, los dos bits restantes los dejamos a 0)
void NSProtocolReportDataSetButtons(tNSGamepad nsGamepad, tNSGamepadReportData* NSGamepadReportData) {

	// Inicializamos actionButtons a 0
	NSGamepadReportData->actionButtons = 0x00;

	// Asignamos los botones de acción (Y, B, A, X, L, R, ZL, ZR)
	// Iteramos del botón Y hasta ZR (del 0 al 7 en el enumerado)
	for (int i = Y; i <= ZR; i++) {
		NSGamepadReportData->actionButtons |= (uint8_t)(nsGamepad.buttonsPressed[i] << i);
	}

	// Inicializamos menuButtons a 0
	NSGamepadReportData->menuButtons = 0x00;

	// Asignamos los botones de menú (MINUS, PLUS, LEFT_STICK, RIGHT_STICK, HOME, CAPTURE)
	// Iteramos del botón MINUS hasta CAPTURE (del 8 al 13 en el enumerado)
	for (int i = MINUS; i <= CAPTURE; i++) {
		NSGamepadReportData->menuButtons |= (uint8_t)(nsGamepad.buttonsPressed[i] << (i - MINUS));
	}

	// Los dos bits más significativos de menuButtons los dejamos a 0, tal y como se especifica.
}


// Valores por defecto del report que se envia a la Switch (sacado de documentacion "oficial")
void NSProtocolReportDataSetDefaultValues (tNSGamepadReportData*  NSGamepadReportData) {

  NSGamepadReportData->actionButtons  = 0x00;
  NSGamepadReportData->menuButtons    = 0x00;
  NSGamepadReportData->dPad           = NSGAMEPAD_DPAD_CENTERED;
  NSGamepadReportData->leftXAxis      = 0x80;
  NSGamepadReportData->leftYAxis      = 0x80;
  NSGamepadReportData->rightXAxis     = 0x80; 
  NSGamepadReportData->rightYAxis     = 0x80;
  NSGamepadReportData->filler         = 0x00;

}

void NSProtocolSerializeNSGamepadData(tNSGamepad nsGamepad, uint8_t buffer[NS_GAMEPAD_REPORT_SIZE]) {

	tNSGamepadReportData NSGamepadReportData;

	// Cargamos los valores por defecto del report (esto se puede modificar cuando
	// implementemos la función para valores reales)
	NSProtocolReportDataSetDefaultValues(&NSGamepadReportData);

	// Rellenamos los botones de acción y de menú
	NSProtocolReportDataSetButtons(nsGamepad, &NSGamepadReportData);

	// TO DO: Rellenar el resto de campos de NSGamepadReportData
	// Por ejemplo, aquí podríamos tener el estado de los joysticks (si está implementado)

	// Serializamos los campos manualmente en el buffer

	// Campo de botones de acción (primer byte)
	buffer[0] = NSGamepadReportData.actionButtons;

	// Campo de botones de menú (segundo byte)
	buffer[1] = NSGamepadReportData.menuButtons;

	// Ejes de los joysticks y D-Pad en los siguientes bytes
	buffer[2] = NSGamepadReportData.dPad;
	buffer[3] = NSGamepadReportData.leftXAxis;
	buffer[4] = NSGamepadReportData.leftYAxis;
	buffer[5] = NSGamepadReportData.rightXAxis;
	buffer[6] = NSGamepadReportData.rightYAxis;

	// Filler (octavo byte)
	buffer[7] = NSGamepadReportData.filler;
}

