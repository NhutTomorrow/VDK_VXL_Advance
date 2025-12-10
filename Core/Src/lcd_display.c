/*
 * led_display.c
 *
 *  Created on: Oct 5, 2025
 *      Author: Vinh Le
 */
#include "main.h"
#include "global.h"
#include "i2c-lcd.h"
#include <stdio.h>

char str_buff[20];
void display_set_config(){
	lcd_clear_display();

	char *str_mode; 
    if(increase_time == 1){
    	str_mode = "(+)";
    }else{
        str_mode = "(-)"; 
    }


	lcd_goto_XY(1, 1);
	switch(config_state){
    case SET_RED1:
        sprintf(str_buff, " Set R1 Red %s", str_mode);
        break;

    case SET_YEL1:
        sprintf(str_buff, " Set R1 Yel %s", str_mode);
        break;

    case SET_GRE1:
        sprintf(str_buff, " Set R1 Grn %s", str_mode);
        break;

    case SET_RED2:
        sprintf(str_buff, " Set R2 Red %s", str_mode);
        break;

    case SET_YEL2:
        sprintf(str_buff, " Set R2 Yel %s", str_mode);
        break;

    case SET_GRE2:
        sprintf(str_buff, " Set R2 Grn %s", str_mode);
        break;

    default:
        sprintf(str_buff, "0000000000");
        break;
    }
    lcd_send_string(str_buff);

	lcd_goto_XY(2, 1);
	sprintf(str_buff, "Value: %d", new_time);
	lcd_send_string(str_buff);
}

void display_err_config(){
	lcd_clear_display();
	switch(config_state){
	case ERR_SYNC_R2:
		lcd_goto_XY(1, 1);
		sprintf(str_buff, " R Sync Error %ds", countdown--);
		lcd_send_string(str_buff);

		lcd_goto_XY(2, 1);
		sprintf(str_buff, "1: Skip, 2: Fix R2");
		lcd_send_string(str_buff);
		break;

	case ERR_SYNC_GY2:		
		lcd_goto_XY(1, 1);
		sprintf(str_buff, " G/Y Sync Error %ds", countdown--);
		lcd_send_string(str_buff);

		lcd_goto_XY(2, 1);
		sprintf(str_buff, "1: Skip, 2: Fix GY2");
		lcd_send_string(str_buff);
		break;

	default:
		//sprintf(str_buff, "Nothing err");
		lcd_goto_XY(1, 1);
		lcd_send_string("Nothing err");
		lcd_goto_XY(2, 1);
		lcd_send_string("Nothing err");
		break;
	}

}

void display_value_confirmed(){
	lcd_clear_display();

	char *str_mode; 
    if(increase_time == 1){
    	str_mode = "(+)";
    }else{
    	str_mode = "(-)";
    }


	lcd_goto_XY(1, 1);
	switch(config_state){
    case SET_RED1:
        sprintf(str_buff, " Set R1 Red %s", str_mode);
        break;

    case SET_YEL1:
        sprintf(str_buff, " Set R1 Yel %s", str_mode);
        break;

    case SET_GRE1:
        sprintf(str_buff, " Set R1 Grn %s", str_mode);
        break;

    case SET_RED2:
        sprintf(str_buff, " Set R2 Red %s", str_mode);
        break;

    case SET_YEL2:
        sprintf(str_buff, " Set R2 Yel %s", str_mode);
        break;

    case SET_GRE2:
        sprintf(str_buff, " Set R2 Grn %s", str_mode);
        break;

    default:
        sprintf(str_buff, "Nothing");
        break;
    }
    lcd_send_string(str_buff);

	lcd_goto_XY(2, 1);
	lcd_send_string("Value Confirmed");
}

void display_manual_mode(){
	lcd_clear_display();
	lcd_goto_XY(2,1);
	lcd_send_string(" MANUAL_MODE");
}

void display_auto_mode(){
	lcd_clear_display();
	lcd_goto_XY(1,1);
	switch(auto_state){
	case RED1_GRE2_AUTO:

		sprintf(str_buff, " RED1: %d", time_road1);


		break;

	case RED1_YEL2_AUTO:

	        sprintf(str_buff, " RED1: %d  ", time_road1);

	        break;

	    // TRƯỜNG HỢP 3: Lộ 1 XANH - Lộ 2 ĐỎ
	    case GRE1_RED2_AUTO:

	        sprintf(str_buff, " GRE1: %d  ", time_road1);

	        break;

	    // TRƯỜNG HỢP 4: Lộ 1 VÀNG - Lộ 2 ĐỎ (Lộ 1 sắp đỏ)
	    case YEL1_RED2_AUTO:

	        sprintf(str_buff, " YEL1: %d  ", time_road1);

	        break;

	    default:
	        break;

	}
	lcd_send_string(str_buff);
	lcd_goto_XY(2,1);
	switch(auto_state){
	case RED1_GRE2_AUTO:

			sprintf(str_buff, " GRE2: %d", time_road2);


		break;

	case RED1_YEL2_AUTO:

	        sprintf(str_buff, " YEL2: %d  ", time_road2);

	        break;

	    // TRƯỜNG HỢP 3: Lộ 1 XANH - Lộ 2 ĐỎ
	    case GRE1_RED2_AUTO:

	        sprintf(str_buff, " RED2: %d  ", time_road2);

	        break;

	    // TRƯỜNG HỢP 4: Lộ 1 VÀNG - Lộ 2 ĐỎ (Lộ 1 sắp đỏ)
	    case YEL1_RED2_AUTO:

	        sprintf(str_buff, " RED2: %d  ", time_road2);

	        break;

	    default:
	        break;

	}
	lcd_send_string(str_buff);
}
