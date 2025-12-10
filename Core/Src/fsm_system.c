/*
 * fsm_manual.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Vinh Le
 */
#include "global.h"

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
    	break;

    default:
    	break;
    }
}

void init_handler(){
	set_rgy1( LED_OFF );
	set_rgy2( LED_OFF );
	display_init_mode();

	if(isSinglePressed(0)){
		sys_state = AUTOMATIC_MODE;
		auto_state = INIT_AUTO;
		resetButton(0);
	}
}

void auto_handler(){
	if(isSinglePressed(0)){
		sys_state = CONFIG_MODE;
		config_state = SET_RED1;

		new_time = 1;

		display_set_config();
		set_rgy1( LED_OFF );
		set_rgy2( LED_OFF );

		SCH_Add_Task(toggle_red1, 250, 250);

		resetButton(0);
	}

	if (isSinglePressed(2)) {
		sys_state = MANUAL_MODE;

		switch (auto_state) {
			case RED1_GRE2_AUTO:
				manual_state = RED1_GRE2_MANU;
				break;

			case RED1_YEL2_AUTO:
				manual_state = RED1_YEL2_MANU;
				setTimer(2, 2000);
				break;

			case GRE1_RED2_AUTO:
				manual_state = GRE1_RED2_MANU;
				break;


			case YEL1_RED2_AUTO:
				manual_state = YEL1_RED2_MANU;
				setTimer(2, 2000);
				break;

			default:
				manual_state = RED1_GRE2_MANU;
				break;
		}
		display_manual_mode();
	}

}

void manual_handler(){

	if(isSinglePressed(0)){
		sys_state = CONFIG_MODE;
		config_state = SET_RED1;

		new_time = 1;

		display_set_config();
		set_rgy1( LED_OFF );
		set_rgy2( LED_OFF );

		SCH_Add_Task(toggle_red1, 250, 250);

		resetButton(0);
	}

	if(isSinglePressed(2)){
        sys_state = AUTOMATIC_MODE;
        auto_state = RED1_GRE2_AUTO;

        time_road1 = time_red1;
        time_road2 = time_gre2;

        setTimer(0, time_gre2 * 1000);
        setTimer(1, 1000);

        resetButton(2);
	}
}
