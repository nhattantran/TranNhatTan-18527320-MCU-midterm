/*
 * global.c
 *
 *  Created on: Nov 4, 2022
 *      Author: DELL
 */


#include "global.h"

uint16_t led7SegComAnode[10] = {
		0x1,	//0
		0x4F,	//1
		0x12,	//2
		0x6,	//3
		0x4C,	//4
		0x24,	//5
		0x20,	//6
		0xF,	//7
		0x0,	//8
		0x4,	//9
};

uint16_t led7SegComCathode[10] = {
		0x7E,	//0
		0x30,	//1
		0x6D,	//2
		0x79,	//3
		0x33,	//4
		0x5B,	//5
		0x5F,	//6
		0x70,	//7
		0x7F,	//8
		0x7B,	//9
};

void display7SegComAnode(int number) {
	uint16_t num = led7SegComAnode[number];
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin, (num>>6)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG1_Pin, (num>>5)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG2_Pin, (num>>4)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG3_Pin, (num>>3)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG4_Pin, (num>>2)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG5_Pin, (num>>1)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG6_Pin, (num>>0)&0x01);
}

void display7SegComCathode(int number) {
	uint16_t num = led7SegComCathode[number];
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin, (num>>6)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG1_Pin, (num>>5)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG2_Pin, (num>>4)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG3_Pin, (num>>3)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG4_Pin, (num>>2)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG5_Pin, (num>>1)&0x01);
	HAL_GPIO_WritePin(GPIOB, SEG6_Pin, (num>>0)&0x01);
}

void reset7SegComAnode() {
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 1);
}
