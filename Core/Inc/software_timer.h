/*
 * timer.h
 *
 *  Created on: Sep 18, 2025
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

struct TimerStruct{
	int counter;
	int flag ;
};

extern volatile struct TimerStruct timer[3];

void setTimer(int index, int duration);
void timer_run();
int isFlag(int idx);

#endif /* INC_SOFTWARE_TIMER_H_ */
