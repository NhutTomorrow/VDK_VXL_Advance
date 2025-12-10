/*
 * fsm_manual.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Vinh Le
 */
#include "global.h"
#include "fsm_system.h"
#include "input_processing.h"
#include "led_display.h"
#include "scheduler.h"

void fsm_system(void){
    switch(sys_state){
    case INIT_MODE:
    	init_handler();
    	break;

    case AUTOMATIC_MODE:
		auto_handler();
    	break;

    case MANUAL_MODE:
    	manual_handler();
    	break;

    case CONFIG_MODE:
    	config_handler();
    	break;

    default:
    	break;
    }
}

void init_handler(){
	set_rgy1( 0b000 );
	set_rgy2( 0b000 );
}

void auto_handler(){
	//Tạo môi trường cho config
	if(isSinglePressed(0)){
		set_rgy1( 0b00 );
		set_rgy2( 0b00 );
		SCH_Add_Task(toggle_red1, 250, 250);

		new_time = 1;

		sys_state = CONFIG_MODE;
		config_state = SET_RED1;
		resetButton(0);
	}

}

void manual_handler(){
	//Tạo môi trường cho config
	if(isSinglePressed(0)){
		set_rgy1( 0b00 );
		set_rgy2( 0b00 );
		SCH_Add_Task(toggle_red1, 250, 250);

		new_time = 1;

		sys_state = CONFIG_MODE;
		config_state = SET_RED1;
		resetButton(0);
	}
}

void config_handler(){

}
