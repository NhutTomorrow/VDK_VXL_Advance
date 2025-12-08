/*
 * fsm_auto.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Vinh Le
 */
#include "global.h"
#include "fsm_automatic.h"
#include "led_display.h"

void fsm_automatic(void){
	if(sys_state != AUTOMATIC_MODE) return;

//	switch(auto_state){
//	case RED1_GRE2:
//		auto_red1_gre2();
//		break;
//
//	case RED1_YEL2:
//		auto_red1_yel2();
//		break;
//
//	case GRE1_RED2:
//		auto_gre1_red2();
//		break;
//
//	case YEL1_RED2:
//		auto_yel1_red2();
//		break;
//
//	case ALL_YEL:
//		auto_all_yel();
//		break;
//
//	default:
//		break;
//	}
//	couter-- //cần thiết thì giảm số ở đây
}

void auto_red1_gre2();
void auto_red1_yel2();
void auto_gre1_red2();
void auto_yel1_red2();
void auto_all_yel();

