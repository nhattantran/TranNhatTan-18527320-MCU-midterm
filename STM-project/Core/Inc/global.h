/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define RS		1	//RESET STATE
#define INC		2	//INCREASE STATE
#define DC		3	//DECREASE STATE
#define FREE	4	//COUNTDOWN STATE


#define TICK	10

extern int state;
extern int numToDisplay;

extern uint16_t led7SegComAnode[10];
extern uint16_t led7SegComCathode[10];

void display7SegComAnode(int number);
void display7SegComCathode(int number);

void reset7SegComAnode();


#endif /* INC_GLOBAL_H_ */
