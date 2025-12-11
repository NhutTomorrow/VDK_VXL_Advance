/*
 * timer.c
 *
 *  Created on: Sep 18, 2025
 *      Author: ASUS
 */
#include <software_timer.h>

#define MAX_TIMER 3
#define TIME_CYCLE 10
volatile struct TimerStruct timer[MAX_TIMER];


void setTimer(int index, int duration){
	timer[index].counter = duration / TIME_CYCLE;
	timer[index].flag = 0;
}

void timer_run(){
	if(timer[0].counter > 0){
		timer[0].counter--;
		if(timer[0].counter <= 0 ){
			timer[0].flag = 1;
		}
	}

	if(timer[1].counter > 0){
		timer[1].counter--;
		if(timer[1].counter <= 0 ){
			timer[1].flag = 1;
		}
	}

	if(timer[2].counter > 0){
		timer[2].counter--;
		if(timer[2].counter <= 0 ){
			timer[2].flag = 1;
		}
	}
}

int isFlag(int idx){
	if(timer[idx].flag){
		return 1;
	}
	return 0;
}

