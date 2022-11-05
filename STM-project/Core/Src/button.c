/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: DELL
 */


#include "button.h"
#include "global.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int buttonTimeOut = 3000;
int TimeOutForKeyRSPress =  3000/TICK;
int buttonRS_flag = 0;

int isButtonRSPressed() {
	if (buttonRS_flag == 1) {
		buttonRS_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyRSProcess() {
	buttonRS_flag = 1;
}

void getKeyRSInput() {
	KeyReg2 = KeyReg1;
	KeyReg1 = KeyReg0;
	KeyReg0 = HAL_GPIO_ReadPin(GPIOA, BUTTON_RESET_Pin);
	if (KeyReg0 == KeyReg1 && KeyReg1 == KeyReg2) {
		if (KeyReg2 != KeyReg3) { 				//Single button pressed
			KeyReg3 = KeyReg2;

			if (KeyReg3 == PRESSED_STATED) {
				TimeOutForKeyRSPress = buttonTimeOut/TICK;
				subKeyRSProcess();
			}
			else {
				TimeOutForKeyRSPress--;
				if (TimeOutForKeyRSPress == 0) {
					KeyReg3 = NORMAL_STATE;
				}
			}
		}
//		else if (KeyReg3 == PRESSED_STATED){ 	//Long button pressed
//			TimeOutForKeyRSPress--;
//			if (TimeOutForKeyRSPress == 0) {
//				subKeyRSProcess();
//				TimeOutForKeyRSPress = 500/TICK;
//			}
//		}
	}
}


int KeyINCReg0 = NORMAL_STATE;
int KeyINCReg1 = NORMAL_STATE;
int KeyINCReg2 = NORMAL_STATE;
int KeyINCReg3 = NORMAL_STATE;


int TimeOutForKeyINCPress =  50/TICK;
int buttonINC_flag = 0;

int isButtonINCPressed() {
	if (buttonINC_flag == 1) {
		buttonINC_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyINCProcess() {
	buttonINC_flag = 1;
}

void getKeyINCInput() {
	KeyINCReg2 = KeyINCReg1;
	KeyINCReg1 = KeyINCReg0;
	KeyINCReg0 = HAL_GPIO_ReadPin(GPIOA, BUTTON_Pin);
	if (KeyINCReg0 == KeyINCReg1 && KeyINCReg1 == KeyINCReg2) {
		if (KeyINCReg2 != KeyINCReg3) { 				//Single button pressed
			KeyINCReg3 = KeyINCReg2;

			if (KeyINCReg3 == PRESSED_STATED) {
				TimeOutForKeyINCPress = buttonTimeOut/TICK;
				subKeyINCProcess();
			} else {
				TimeOutForKeyINCPress--;
				if (TimeOutForKeyINCPress == 0) {
					//subKeyProcess();
					KeyINCReg3 = NORMAL_STATE;
				}
			}
		}
		else if (KeyINCReg3 == PRESSED_STATED){ 	//Long button pressed
			buttonINC_flag = 0;
			TimeOutForKeyINCPress--;
			if (TimeOutForKeyINCPress == 0) {
				subKeyINCProcess();
				TimeOutForKeyINCPress = 1000/TICK;
			}
		}
	}
}


int KeyDCReg0 = NORMAL_STATE;
int KeyDCReg1 = NORMAL_STATE;
int KeyDCReg2 = NORMAL_STATE;
int KeyDCReg3 = NORMAL_STATE;


int TimeOutForKeyDCPress =  50/TICK;
int buttonDC_flag = 0;

int isButtonDCPressed() {
	if (buttonDC_flag == 1) {
		buttonDC_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyDCProcess() {
	buttonDC_flag = 1;
}

void getKeyDCInput() {
	KeyDCReg2 = KeyDCReg1;
	KeyDCReg1 = KeyDCReg0;
	KeyDCReg0 = HAL_GPIO_ReadPin(GPIOA, BUTTON_DEC_Pin);
	if (KeyDCReg0 == KeyDCReg1 && KeyDCReg1 == KeyDCReg2) {
		if (KeyDCReg2 != KeyDCReg3) { 				//Single button pressed
			KeyDCReg3 = KeyDCReg2;

			if (KeyDCReg3 == PRESSED_STATED) {
				TimeOutForKeyDCPress = buttonTimeOut/TICK;
				subKeyDCProcess();
			} else {
				TimeOutForKeyDCPress--;
				if (TimeOutForKeyDCPress == 0) {
					//subKeyProcess();
					KeyDCReg3 = NORMAL_STATE;
				}
			}
		}
		else if (KeyDCReg3 == PRESSED_STATED){ 	//Long button pressed
			buttonDC_flag = 0;
			TimeOutForKeyDCPress--;
			if (TimeOutForKeyDCPress == 0) {
				subKeyDCProcess();
				TimeOutForKeyDCPress = 1000/TICK;
			}
		}
	}
}
