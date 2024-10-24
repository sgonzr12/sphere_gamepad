

//declaration of number of buttons in the gamepad
const int BUTTONSNUMBER = 14; 

//declaration for the touch pins for all buttons
int BUTTON_A = 1;
int BUTTON_B = 2;
int BUTTON_X = 3;
int BUTTON_Y = 4;
int BUTTON_L = 5;
int BUTTON_R = 6;
int BUTTON_ZL = 7;
int BUTTON_ZR = 8;
int BUTTON_HOME = 9;
int BUTTON_CAPTURE = 10;
int DPAD_UP = 11;
int DPAD_DOWN = 12;
int DPAD_LEFT = 13;
int DPAD_RIGHT = 14;

//declaration of the calibration time
int calibrationTime = 2000;

//declaration of the array of threshold values for all buttons
int thresholdValues[BUTTONSNUMBER+1];

#define TOUCHED_THRESHOLD_FACTOR 1.20

//declaration of the touch threshold
//int TOUCH_THRESHOLD = 100000;