/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: DELL
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "software-timer.h"

#define NORMAL_STATE		SET		//NOT PRESSED
#define PRESSED_STATED		RESET	//PRESSED

int isButtonRSPressed();
int isButtonINCPressed();
int isButtonDCPressed();

void getKeyRSInput();
void getKeyINCInput();
void getKeyDCInput();

#endif /* INC_BUTTON_H_ */
