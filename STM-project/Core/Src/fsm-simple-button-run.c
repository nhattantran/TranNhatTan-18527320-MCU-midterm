/*
 * fsm-simple-button-run.c
 *
 *  Created on: Nov 5, 2022
 *      Author: DELL
 */


#include "fsm-simple-button-run.h"

int state;
int numToDisplay;

int setTimer = 1000;

int timerFree = 3000;

void fsm_simple_button_run() {
	switch (state) {
	case RS:
		numToDisplay = 0;
		display7SegComAnode(numToDisplay);
		if (isButtonDCPressed() == 1) {
			state = DC;
			setTimer2(timerFree);
			if (numToDisplay > 0) {
				numToDisplay--;
				display7SegComAnode(numToDisplay);
				//if (numToDisplay <= 0) numToDisplay = 9;
			} else {
				numToDisplay = 9;
				display7SegComAnode(numToDisplay);
			}
		}
		if (isButtonINCPressed() == 1) {
			state = INC;
			setTimer2(timerFree);
			if (numToDisplay < 9) {
				numToDisplay++;
				display7SegComAnode(numToDisplay);
				//if (numToDisplay >= 9) numToDisplay = 0;
			} else {
				numToDisplay = 0;
				display7SegComAnode(numToDisplay);
				//numToDisplay++;
			}
		}
		break;

		/*------------------------------------------------------------------------------------*/

	case INC:
		if (isButtonDCPressed() == 1) {
			if (numToDisplay > 0) {
				numToDisplay--;
				display7SegComAnode(numToDisplay);
				//if (numToDisplay <= 0) numToDisplay = 9;
			} else {
				numToDisplay = 9;
				display7SegComAnode(numToDisplay);
				//numToDisplay--;
			}
			state = DC;
			setTimer2(timerFree);
			}
		if (timer2_flag == 1) {
			//numToDisplay--;
			state = FREE;
			setTimer1(setTimer);
		}
		if (isButtonINCPressed() == 1) {
			state = INC;
			setTimer2(timerFree);
			if (numToDisplay < 9) {
				numToDisplay++;
				display7SegComAnode(numToDisplay);

				//if (numToDisplay > 9) numToDisplay = 0;
			} else {
				numToDisplay = 0;
				display7SegComAnode(numToDisplay);
				//numToDisplay++;
			}
		}
		if (isButtonRSPressed() == 1) {
			state = RS;
			numToDisplay = 0;
			display7SegComAnode(numToDisplay);
		}

		break;

		/*---------------------------------------------------------------------------*/

	case DC:
		if (isButtonINCPressed() == 1) {
			if (numToDisplay < 9) {
				numToDisplay++;
				display7SegComAnode(numToDisplay);
				//if (numToDisplay >= 9) numToDisplay = 0;
			} else {
				numToDisplay = 0;
				display7SegComAnode(numToDisplay);
				//numToDisplay++;
			}
			state = INC;
			setTimer2(timerFree);
		}
		if (timer2_flag == 1){
			state = FREE;
			setTimer1(setTimer);
		}
		if (isButtonRSPressed() == 1) {
			state = RS;
			numToDisplay = 0;
			display7SegComAnode(numToDisplay);
		}

		if (isButtonDCPressed() == 1) {
			state = DC;
			setTimer2(timerFree);
			if (numToDisplay > 0) {
				numToDisplay--;
				display7SegComAnode(numToDisplay);

				//if (numToDisplay < 0) numToDisplay = 9;
			} else {
				numToDisplay = 9;
				display7SegComAnode(numToDisplay);

			}
		}
		break;

		/*--------------------------------------------------------------------------------*/

	case FREE:
		if (isButtonRSPressed() == 1) {
			state = RS;
			numToDisplay = 0;
			display7SegComAnode(numToDisplay);
		}
		if (numToDisplay != 0) {
			if (timer1_flag == 1) {
				setTimer1(setTimer);
				numToDisplay--;
				display7SegComAnode(numToDisplay);

				if (numToDisplay < 0) numToDisplay = 0;
			}
		} else {
			display7SegComAnode(numToDisplay);
		}
		if (isButtonDCPressed() == 1) {
			state = DC;
			setTimer2(timerFree);
			if (numToDisplay > 0) {
				numToDisplay--;
				display7SegComAnode(numToDisplay);
				//if (numToDisplay <= 0) numToDisplay = 9;
			} else {
				numToDisplay = 9;
				display7SegComAnode(numToDisplay);
				//numToDisplay--;
			}
		}
		if (isButtonINCPressed() == 1) {
			state = INC;
			setTimer2(timerFree);
			if (numToDisplay < 9) {
				numToDisplay++;
				display7SegComAnode(numToDisplay);
				//if (numToDisplay >= 9) numToDisplay = 0;
			} else {
				numToDisplay = 0;
				display7SegComAnode(numToDisplay);
				//numToDisplay++;
			}
		}
		break;
	default:
		break;
	}
}
