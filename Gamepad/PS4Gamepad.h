#ifndef PS4GAMEPAD_H_
#define PS4GAMEPAD_H_

#include "PS4Types.h"

void PS4GamepadPressButton(tPSButtons buttonIndex, tPSGamepad* PSGamepad);

void PS4GamepadReleaseButton(tPSButtons buttonIndex, tPSGamepad* PSGamepad);

void PS4GamepadReleaseAllButtons(tPSGamepad* PSGamepad);

// TO DO: Resto de botones y funcionalidades

#endif // PS4GAMEPAD_H_
