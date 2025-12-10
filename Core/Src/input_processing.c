/*
 * input_processing.c
 *
 *  Created on: Oct 2, 2025
 *      Author: Vinh Le
 */


#include "scheduler.h"
#include "main.h"
#include "input_reading.h"
#include "input_processing.h"


enum ButtonState {BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND, BUTTON_WAITING_FOR_SECOND_CLICK};
enum ButtonState buttonState[1] = {BUTTON_RELEASED};

int single_press_button[3] = {0, 0, 0};
int double_press_button[3] = {0, 0, 0};
int immediately_1s_press_button[3] = {0, 0, 0};
int continuously_1s_press_button[3] = {0, 0, 0};



uint8_t flag_just_double_clicked = 0;
int counter = 0;



void button_processing(void){
	for (int i = 0; i < 3; ++i){
		switch(buttonState[i]){

		case BUTTON_RELEASED:
			if(is_button_pressed(i)){
				buttonState[i] = BUTTON_PRESSED;
				
///////////////////immediately_press_handler();
				flag_just_double_clicked = 0;


			}

			break;

		case BUTTON_PRESSED:
			if(!is_button_pressed(i)){
				if(flag_just_double_clicked == 1) {

					buttonState[i] = BUTTON_RELEASED;
					flag_just_double_clicked = 0;
				} else {

					buttonState[i] = BUTTON_WAITING_FOR_SECOND_CLICK;
					counter = 5;
				}
			} else {
				if(is_button_pressed_1s(i)){
					buttonState[i] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
////////////////////// ngay lập tức kích khi 1s nhấn
					immediately_1s_press(i);
				}
			}
			break;

		case BUTTON_WAITING_FOR_SECOND_CLICK:
			if(counter > 0)
				counter--;

			if (is_button_pressed(i)) {
				buttonState[i] = BUTTON_PRESSED;
////////////////double click
				double_press_handler(i);
				flag_just_double_clicked = 1;

			} else if (counter == 0) {
				buttonState[i] = BUTTON_RELEASED;
///////////////// Single Click
				single_press_handler(i);
			}
			break;

		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(i)){
				buttonState[i] = BUTTON_RELEASED;
				flag_just_double_clicked = 0;

////////////////// after_long_press

			}

/////////////////// liên tục kích


			continuously_press_handler(i);


			break;
		}

	}


}


void single_press_handler(int index){
	single_press_button[index] = 1;
}

void double_press_handler(int index){
	double_press_button[index] = 1;
}

void immediately_1s_press(int index){
	immediately_1s_press_button[index] = 1;
}

void continuously_press_handler(int index){
	continuously_1s_press_button[index] = 1;
}


int isSinglePressed(int button_idx){
	if(single_press_button[button_idx] == 1) {
		resetButton(button_idx);
		return 1;
	}
	return 0;
}

int isDoublePressed(int button_idx){
	if(double_press_button[button_idx] == 1) return 1;
	else return 0;
}
int isImmediately1sPressed(int button_idx){
	if(immediately_1s_press_button[button_idx] == 1) return 1;
	else return 0;
}

int isContinuouslyPressed(int button_idx){
	if(continuously_1s_press_button[button_idx] == 1) return 1;
	else return 0;
}

void resetButton(int button_idx){
	single_press_button[button_idx] = 0;
	double_press_button[button_idx] = 0;
	immediately_1s_press_button[button_idx] = 0;
	continuously_1s_press_button[button_idx] = 0;
}





