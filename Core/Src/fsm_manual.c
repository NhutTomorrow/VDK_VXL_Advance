/*
 * fsm_manual.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Vinh Le
 */
#include "global.h"
#include "fsm_manual.h"
#include "led_display.h"

void fsm_manual(void){
	if(sys_state != AUTOMATIC_MODE) return;

//	switch(auto_state){
//	case RED1_GRE2:
//		manual_red1_gre2();
//		break;
//
//	case RED1_YEL2:
//		manual_red1_yel2();
//		break;
//
//	case GRE1_RED2:
//		manual_gre1_red2();
//		break;
//
//	case YEL1_RED2:
//		manual_yel1_red2();
//		break;
//
//	case ALL_YEL:
//		manual_all_yel();
//		break;
//
//	default:
//		break;
//	}
}

void manual_red1_gre2(){

}
void manual_red1_yel2(){

}
void manual_gre1_red2(){

}
void manual_yel1_red2(){

}
void manual_all_yel(){
	
}
