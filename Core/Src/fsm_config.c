/*
 * fsm_config.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Vinh Le
 */
#include "global.h"
#include "fsm_config.h"
#include "scheduler.h"
#include "input_processing.h"
#include "led_display.h"
#include "lcd_display.h"
#include "scheduler.h"

#include "i2c-lcd.h"
void init_test(){
//	lcd_clear_display();
//	lcd_goto_XY(1, 1);
//    lcd_send_string("test");
	sys_state = AUTOMATIC_MODE;
//	config_state = SET_RED1;
	auto_state = INIT_AUTO;
//	display_set_config();
	set_rgy1( 0b00 );
	set_rgy2( 0b00 );
	lcd_clear_display();

//	SCH_Add_Task(toggle_red1, 250, 250);

	new_time = 1;
}



void fsm_config(void){
	if(sys_state != CONFIG_MODE) return;

	switch(config_state){
	case SET_RED1:
		set_red1_handler();
		break;

	case SET_YEL1:
		set_yel1_handler();
		break;

	case SET_GRE1:
		set_gre1_handler();
		break;

	case SET_RED2:
		set_red2_handler();
		break;

	case SET_YEL2:
		set_yel2_handler();
		break;

	case SET_GRE2:
		set_gre2_handler();
		break;

	case ERR_SYNC_R2:
		err_syn_r2_handler();
		break;

	case ERR_SYNC_GY2:
		err_syn_gy2_handler();
		break;

	default:
		break;
	}
}

void set_red1_handler(){
	if(isSinglePressed(0)){
		config_state = SET_YEL1;

		new_time = 1;

		int ID = SCH_Get_TaskID(toggle_red1);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(display_set_config);
		if(ID != -1) SCH_Delete_Task(ID);

		display_set_config();
		set_rgy1( 0b00 );
		set_rgy2( 0b00 );

		SCH_Add_Task(toggle_yel1, 250, 250);

		resetButton(0);
		resetButton(1);
		resetButton(2);
	}

	if(isSinglePressed(1)){
		if(increase_time == 1){
			++new_time;
			if(new_time > 99) new_time = 1;
		}else{
			--new_time;
			if(new_time < 1) new_time = 99;
		}
		display_set_config();
		resetButton(1);
	}

	if(isDoublePressed(1)){
		if(increase_time == 1)
			increase_time = 0;
		else
			increase_time = 1;
		display_set_config();
		resetButton(1);
	}

	if(isContinuouslyPressed(1)){
		SCH_Add_Task(change_continuously_newtime, 100, 0);
		resetButton(1);
	}

	if(isSinglePressed(2)){
		new_red1 = new_time;
		display_value_confirmed();
		SCH_Add_Task(display_set_config, 2000, 0);
		resetButton(2);
	}
}

void set_yel1_handler(){
	if(isSinglePressed(0)){
		config_state = SET_GRE1;

		new_time = 1;

		int ID = SCH_Get_TaskID(toggle_yel1);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(display_set_config);
		if(ID != -1) SCH_Delete_Task(ID);

		display_set_config();
		set_rgy1( 0b00 );
		set_rgy2( 0b00 );

		SCH_Add_Task(toggle_gre1, 250, 250);

		resetButton(0);
		resetButton(1);
		resetButton(2);
	}

	if(isSinglePressed(1)){
		if(increase_time == 1){
			++new_time;
			if(new_time > 99) new_time = 1;
		}else{
			--new_time;
			if(new_time < 1) new_time = 99;
		}
		display_set_config();
		resetButton(1);
	}

	if(isDoublePressed(1)){
		if(increase_time == 1)
			increase_time = 0;
		else
			increase_time = 1;
		display_set_config();
		resetButton(1);
	}

	if(isContinuouslyPressed(1)){
		SCH_Add_Task(change_continuously_newtime, 100, 0);
		resetButton(1);
	}
	
	if(isSinglePressed(2)){
		new_yel1 = new_time;
		display_value_confirmed();
		SCH_Add_Task(display_set_config, 2000, 0);
		resetButton(2);
	}
}
void set_gre1_handler(){
	if(isSinglePressed(0)){
		config_state = SET_RED2;

		new_time = 1;

		int ID = SCH_Get_TaskID(toggle_gre1);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(display_set_config);
		if(ID != -1) SCH_Delete_Task(ID);

		display_set_config();
		set_rgy1( 0b00 );
		set_rgy2( 0b00 );

		SCH_Add_Task(toggle_red2, 250, 250);

		resetButton(0);
		resetButton(1);
		resetButton(2);
	}

	if(isSinglePressed(1)){
		if(increase_time == 1){
			++new_time;
			if(new_time > 99) new_time = 1;
		}else{
			--new_time;
			if(new_time < 1) new_time = 99;
		}
		display_set_config();
		resetButton(1);
	}

	if(isDoublePressed(1)){
		if(increase_time == 1)
			increase_time = 0;
		else
			increase_time = 1;
		display_set_config();
		resetButton(1);
	}

	if(isContinuouslyPressed(1)){
		SCH_Add_Task(change_continuously_newtime, 100, 0);
		resetButton(1);
	}
	
	if(isSinglePressed(2)){
		new_gre1 = new_time;
		display_value_confirmed();
		SCH_Add_Task(display_set_config, 2000, 0);
		resetButton(2);
	}
}

void set_red2_handler(){
	if(isSinglePressed(0)){
		config_state = SET_YEL2;

		new_time = 1;

		int ID = SCH_Get_TaskID(toggle_red2);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(display_set_config);
		if(ID != -1) SCH_Delete_Task(ID);

		display_set_config();
		set_rgy1( 0b00 );
		set_rgy2( 0b00 );

		SCH_Add_Task(toggle_yel2, 250, 250);

		resetButton(0);
		resetButton(1);
		resetButton(2);
	}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
	if(isDoublePressed(0)){
		int ID = SCH_Get_TaskID(toggle_red2);
		if(ID != -1) SCH_Delete_Task(ID);

		set_rgy1( 0b00 );
		set_rgy2( 0b00 );

		new_time = 1;

		sys_state = AUTOMATIC_MODE;
		resetButton(0);
	}

	if(isSinglePressed(1)){
		if(increase_time == 1){
			++new_time;
			if(new_time > 99) new_time = 1;
		}else{
			--new_time;
			if(new_time < 1) new_time = 99;
		}
		display_set_config();
		resetButton(1);
	}

	if(isDoublePressed(1)){
		if(increase_time == 1)
			increase_time = 0;
		else
			increase_time = 1;
		display_set_config();
		resetButton(1);
	}

	if(isContinuouslyPressed(1)){
		SCH_Add_Task(change_continuously_newtime, 100, 0);
		resetButton(1);
	}
	
	if(isSinglePressed(2)){
		new_red2 = new_time;

		if(new_gre1 && new_yel1 && new_red2 != new_gre1 + new_yel1){
			config_state = ERR_SYNC_R2;

			countdown = 3;

			int ID = SCH_Get_TaskID(toggle_red2);
			if(ID != -1) SCH_Delete_Task(ID);
			ID = SCH_Get_TaskID(display_set_config);
			if(ID != -1) SCH_Delete_Task(ID);

			set_rgy1( 0b00 );
			set_rgy2( 0b00 );

			SCH_Add_Task(display_err_config, 10, 1000);
			SCH_Add_Task(toggle_red1, 250, 250);
			SCH_Add_Task(toggle_red2, 250, 250);
			SCH_Add_Task(ERR_SYN_R2_to_SET_YEL2, 3000, 0);
		}else{
			display_value_confirmed();
			SCH_Add_Task(display_set_config, 2000, 0);
		}
		resetButton(0);
		resetButton(1);
		resetButton(2);
	}
}
void set_yel2_handler(){
	if(isSinglePressed(0)){
		config_state = SET_GRE2;

		new_time = 1;

		int ID = SCH_Get_TaskID(toggle_yel2);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(display_set_config);
		if(ID != -1) SCH_Delete_Task(ID);

		display_set_config();
		set_rgy1( 0b00 );
		set_rgy2( 0b00 );

		SCH_Add_Task(toggle_gre2, 250, 250);

		resetButton(0);
		resetButton(1);
		resetButton(2);
	}

	if(isSinglePressed(1)){
		if(increase_time == 1){
			++new_time;
			if(new_time > 99) new_time = 1;
		}else{
			--new_time;
			if(new_time < 1) new_time = 99;
		}
		display_set_config();
		resetButton(1);
	}

	if(isDoublePressed(1)){
		if(increase_time == 1)
			increase_time = 0;
		else
			increase_time = 1;
		display_set_config();
		resetButton(1);
	}

	if(isContinuouslyPressed(1)){
		SCH_Add_Task(change_continuously_newtime, 100, 0);
		resetButton(1);
	}
	
	if(isSinglePressed(2)){
		new_yel2 = new_time;
		display_value_confirmed();
		SCH_Add_Task(display_set_config, 2000, 0);
		resetButton(2);
	}
}
void set_gre2_handler(){
	//////////////////////////////////////////
	/////////////////////
	/////////////////////////////
		//////////////////////////////////////////
	/////////////////////
	/////////////////////////////
		//////////////////////////////////////////
	/////////////////////
	/////////////////////////////
	if(isSinglePressed(0)){
		config_state = AUTOMATIC_MODE;

		new_time = 1;

		int ID = SCH_Get_TaskID(toggle_gre2);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(display_set_config);
		if(ID != -1) SCH_Delete_Task(ID);

		display_set_config();
		set_rgy1( 0b00 );
		set_rgy2( 0b00 );

		resetButton(0);
		resetButton(1);
		resetButton(2);
	}

	if(isSinglePressed(1)){
		if(increase_time == 1){
			++new_time;
			if(new_time > 99) new_time = 1;
		}else{
			--new_time;
			if(new_time < 1) new_time = 99;
		}
		display_set_config();
		resetButton(1);
	}

	if(isDoublePressed(1)){
		if(increase_time == 1)
			increase_time = 0;
		else
			increase_time = 1;
		display_set_config();
		resetButton(1);
	}

	if(isContinuouslyPressed(1)){
		SCH_Add_Task(change_continuously_newtime, 100, 0);
		resetButton(1);
	}
	
	if(isSinglePressed(2)){
		new_gre2 = new_time;

		if(new_red1 && new_gre2 && new_yel2  && new_red1 != new_gre2 + new_yel2){
			config_state = ERR_SYNC_GY2;

			countdown = 3;

			int ID = SCH_Get_TaskID(toggle_gre2);
			if(ID != -1) SCH_Delete_Task(ID);
			ID = SCH_Get_TaskID(display_set_config);
			if(ID != -1) SCH_Delete_Task(ID);

			set_rgy1( 0b01 );
			set_rgy2( 0b01 );

			SCH_Add_Task(display_err_config, 10, 1000);
			SCH_Add_Task(toggle_yel_gre, 250, 250);
			SCH_Add_Task(ERR_SYN_GY2_to_AUTOMATIC_MODE, 3000, 0);
		}else{
			display_value_confirmed();
			SCH_Add_Task(display_set_config, 2000, 0);
		}
		resetButton(0);
		resetButton(1);
		resetButton(2);
	}
}

void err_syn_r2_handler(){
	if(isSinglePressed(0)){
		config_state = SET_YEL2;

		new_time = 1;

		int ID = SCH_Get_TaskID(toggle_red1);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(toggle_red2);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(ERR_SYN_R2_to_SET_YEL2);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(display_err_config);
		if(ID != -1) SCH_Delete_Task(ID);

		display_set_config();
		set_rgy1( 0b00 );
		set_rgy2( 0b00 );

		SCH_Add_Task(toggle_yel2, 250, 250);

		resetButton(0);
		resetButton(1);
		resetButton(2);
	}

	if(isSinglePressed(1)){
		config_state = SET_RED2;

		new_time = 1;

		int ID = SCH_Get_TaskID(toggle_red1);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(toggle_red2);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(ERR_SYN_R2_to_SET_YEL2);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(display_err_config);
		if(ID != -1) SCH_Delete_Task(ID);

		display_set_config();
		set_rgy1( 0b00 );
		set_rgy2( 0b00 );

		SCH_Add_Task(toggle_red2, 250, 250);

		resetButton(0);
		resetButton(1);
		resetButton(2);
	}
}

void err_syn_gy2_handler(){
	////////////Chuyển đổi sang AUTO
	if(isSinglePressed(0)){
		set_rgy1( 0b00 );
		set_rgy2( 0b00 );

		int ID = SCH_Get_TaskID(toggle_yel_gre); 
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(ERR_SYN_GY2_to_AUTOMATIC_MODE);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(display_err_config);
		if(ID != -1) SCH_Delete_Task(ID);

		sys_state = AUTOMATIC_MODE;
		resetButton(0);
	}

	if(isSinglePressed(1)){
		config_state = SET_YEL2;

		new_time = 1;

		display_set_config();
		set_rgy1( 0b00 );
		set_rgy2( 0b00 );

		int ID = SCH_Get_TaskID(toggle_yel_gre);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(ERR_SYN_GY2_to_AUTOMATIC_MODE);
		if(ID != -1) SCH_Delete_Task(ID);
		ID = SCH_Get_TaskID(display_err_config);
		if(ID != -1) SCH_Delete_Task(ID);

		SCH_Add_Task(toggle_yel2, 250, 250);

		resetButton(0);
		resetButton(1);
		resetButton(2);
	}
}


void change_continuously_newtime(){
	if(isContinuouslyPressed(1)){
		SCH_Add_Task(change_continuously_newtime, 300, 0);
		resetButton(1);
	}

	if(increase_time == 1){
		++new_time;
		if(new_time > 99) new_time = 1;
	}else{
		--new_time;
		if(new_time < 1) new_time = 99;
	}
	display_set_config();
}

void ERR_SYN_R2_to_SET_YEL2(){
	config_state = SET_YEL2;

	new_time = 1;

	int ID = SCH_Get_TaskID(toggle_red1);
	if(ID != -1) SCH_Delete_Task(ID);
	ID = SCH_Get_TaskID(toggle_red2);
	if(ID != -1) SCH_Delete_Task(ID);
	ID = SCH_Get_TaskID(display_err_config);
	if(ID != -1) SCH_Delete_Task(ID);

	display_set_config();
	set_rgy1( 0b00 );
	set_rgy2( 0b00 );

	SCH_Add_Task(toggle_yel2, 250, 250);

	resetButton(0);
	resetButton(1);
	resetButton(2);
}

// Có chuyển sang AUTO MODE
void ERR_SYN_GY2_to_AUTOMATIC_MODE(){
	int ID = SCH_Get_TaskID(toggle_yel_gre); 
	if(ID != -1) SCH_Delete_Task(ID);
	ID = SCH_Get_TaskID(display_err_config);
	if(ID != -1) SCH_Delete_Task(ID);


	if(new_red1 && new_yel1 && new_gre1 && new_red2 && new_yel2 && new_gre2){
		time_red1 = new_red1;
		time_yel1 = new_yel1;
		time_gre1 = new_gre1;
		time_red2 = new_red2;
		time_yel2 = new_yel2;
		time_gre2 = new_gre2;
	}

	new_red1 = 0;
	new_yel1 = 0;
	new_gre1 = 0;
	new_red2 = 0;
	new_yel2 = 0;
	new_gre2 = 0;



	set_rgy1( 0b00 );
	set_rgy2( 0b00 );

	sys_state = AUTOMATIC_MODE;

	resetButton(0);
	resetButton(1);
	resetButton(2);
}



