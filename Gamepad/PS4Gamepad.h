#ifndef PS4GAMEPAD_H_
#define PS4GAMEPAD_H_

#include "PS4Types.h"

void PS4GamepadPressButton (tPS4Buttons buttonIndex , tPS4Gamepad* PS4Gamepad);

void PS4GamepadReleaseButton (tPS$Buttons buttonIndex , tPS4Gamepad* PS4Gamepad);

void PS4GamepadReleaseAllButtons (tPS4Gamepad* PS4Gamepad);

// TO DO: Resto de botones y funcionalidades




#endif // PS4GAMEPAD_H_