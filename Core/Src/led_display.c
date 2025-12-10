/*
 * led_display.c
 *
 *  Created on: Oct 5, 2025
 *      Author: Vinh Le
 */
#include "main.h"
#include "global.h"

void set_rgy1(int color) {
    switch (color) {
        case 0: // ĐỎ (PCB: 11) -> A=1, B=1
            HAL_GPIO_WritePin(LED_A1_GPIO_Port, LED_A1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED_B1_GPIO_Port, LED_B1_Pin, GPIO_PIN_SET);
            break;

        case 1: // XANH (PCB: 10) -> A=1, B=0
            HAL_GPIO_WritePin(LED_A1_GPIO_Port, LED_A1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED_B1_GPIO_Port, LED_B1_Pin, GPIO_PIN_RESET);
            break;

        case 2: // VÀNG (PCB: 01) -> A=0, B=1
            HAL_GPIO_WritePin(LED_A1_GPIO_Port, LED_A1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_B1_GPIO_Port, LED_B1_Pin, GPIO_PIN_SET);
            break;

        default: // TẮT (PCB: 00)
            HAL_GPIO_WritePin(LED_A1_GPIO_Port, LED_A1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_B1_GPIO_Port, LED_B1_Pin, GPIO_PIN_RESET);
            break;
    }
}


void set_rgy2(int color) {
    switch (color) {
        case 0: // ĐỎ
            HAL_GPIO_WritePin(LED_A2_GPIO_Port, LED_A2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED_B2_GPIO_Port, LED_B2_Pin, GPIO_PIN_SET);
            break;

        case 1: // XANH
            HAL_GPIO_WritePin(LED_A2_GPIO_Port, LED_A2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED_B2_GPIO_Port, LED_B2_Pin, GPIO_PIN_RESET);
            break;

        case 2: // VÀNG
            HAL_GPIO_WritePin(LED_A2_GPIO_Port, LED_A2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_B2_GPIO_Port, LED_B2_Pin, GPIO_PIN_SET);
            break;

        default:
            HAL_GPIO_WritePin(LED_A2_GPIO_Port, LED_A2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_B2_GPIO_Port, LED_B2_Pin, GPIO_PIN_RESET);
            break;
    }
}

void toggle_rgy(uint8_t n){

	if( n == 0b01 ){
		HAL_GPIO_TogglePin ( LED_B1_GPIO_Port , LED_B1_Pin );
		HAL_GPIO_TogglePin ( LED_B2_GPIO_Port , LED_B2_Pin );
	}

	if( n == 0b10 ){
		HAL_GPIO_TogglePin ( LED_A1_GPIO_Port , LED_A1_Pin );
		HAL_GPIO_TogglePin ( LED_A2_GPIO_Port , LED_A2_Pin );
	}

	if( n == 0b11 ){
		HAL_GPIO_TogglePin ( LED_A1_GPIO_Port , LED_A1_Pin );
		HAL_GPIO_TogglePin ( LED_A2_GPIO_Port , LED_A2_Pin );
		HAL_GPIO_TogglePin ( LED_B1_GPIO_Port , LED_B1_Pin );
		HAL_GPIO_TogglePin ( LED_B2_GPIO_Port , LED_B2_Pin );
	}
}

void toggle_red1(){
	HAL_GPIO_TogglePin ( LED_A1_GPIO_Port , LED_A1_Pin );
	HAL_GPIO_TogglePin ( LED_B1_GPIO_Port , LED_B1_Pin );
}
void toggle_yel1(){
	HAL_GPIO_TogglePin ( LED_B1_GPIO_Port , LED_B1_Pin );
}
void toggle_gre1(){
	HAL_GPIO_TogglePin ( LED_A1_GPIO_Port , LED_A1_Pin );
}

void toggle_red2(){
	HAL_GPIO_TogglePin ( LED_A2_GPIO_Port , LED_A2_Pin );
	HAL_GPIO_TogglePin ( LED_B2_GPIO_Port , LED_B2_Pin );
}
void toggle_yel2(){
	HAL_GPIO_TogglePin ( LED_B2_GPIO_Port , LED_B2_Pin );
}
void toggle_gre2(){
	HAL_GPIO_TogglePin ( LED_A2_GPIO_Port , LED_A2_Pin );
}

void toggle_yel_gre(){
	HAL_GPIO_TogglePin ( LED_A1_GPIO_Port , LED_A1_Pin );
	HAL_GPIO_TogglePin ( LED_B1_GPIO_Port , LED_B1_Pin );

	HAL_GPIO_TogglePin ( LED_A2_GPIO_Port , LED_A2_Pin );
	HAL_GPIO_TogglePin ( LED_B2_GPIO_Port , LED_B2_Pin );
}

void manual_red1_gre2(){
    set_rgy1(LED_RED);
    set_rgy2(LED_GREEN);
}

void manual_red1_yel2(){
    set_rgy1(LED_RED);
    set_rgy2(LED_YELLOW);
}

void manual_gre1_red2(){
    set_rgy1(LED_GREEN);
    set_rgy2(LED_RED);
}

void manual_yel1_red2(){
    set_rgy1(LED_YELLOW);
    set_rgy2(LED_RED);
}






