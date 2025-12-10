/*
 * led_display.c
 *
 *  Created on: Oct 5, 2025
 *      Author: Vinh Le
 */
#include "main.h"

//int led_buffer[4] = {0, 0, 0, 0};
//static const uint8_t SEG_TABLE[15] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10, 0x08, 0x46, 0x06, 0x4E, 0x48};


// Hàm điều khiển cụm đèn số 1
//void set_rgy1(uint8_t n) {
//	HAL_GPIO_WritePin(LED_A1_GPIO_Port, LED_A1_Pin, (n & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(LED_B1_GPIO_Port, LED_B1_Pin, ((n >> 1) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
//}
//void set_rgy2(uint8_t n) {
//	HAL_GPIO_WritePin(LED_A2_GPIO_Port, LED_A2_Pin, (n & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(LED_B2_GPIO_Port, LED_B2_Pin, ((n >> 1) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
//}
void set_rgy1(int color) {
    // color: quy ước đầu vào (tùy bạn chọn), ở đây mình dùng:
    // RED = 0, GREEN = 1, YELLOW = 2 để dễ gọi trong FSM

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

// Hàm set màu cho cụm đèn 2 (Tương tự)
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
	HAL_GPIO_TogglePin ( LED_A2_GPIO_Port , LED_A2_Pin );
}
void toggle_gre2(){
	HAL_GPIO_TogglePin ( LED_B2_GPIO_Port , LED_B2_Pin );
}

void toggle_yel_gre(){
	HAL_GPIO_TogglePin ( LED_A1_GPIO_Port , LED_A1_Pin );
	HAL_GPIO_TogglePin ( LED_B1_GPIO_Port , LED_B1_Pin );

	HAL_GPIO_TogglePin ( LED_A2_GPIO_Port , LED_A2_Pin );
	HAL_GPIO_TogglePin ( LED_B2_GPIO_Port , LED_B2_Pin );
}

// void display7SEG(int num){


//     uint8_t seg = SEG_TABLE[num];

//     HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (seg >> 0) & 1);
//     HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (seg >> 1) & 1);
//     HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (seg >> 2) & 1);
//     HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (seg >> 3) & 1);
//     HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (seg >> 4) & 1);
//     HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (seg >> 5) & 1);
//     HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (seg >> 6) & 1);

// }
// void update7SEG(int index){
// 	switch (index){
// 	case -1:
// 		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
// 		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
// 		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
// 		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
// 		display7SEG(8);
// 		break;
// 	case 0:
// 		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
// 		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
// 		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
// 		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
// 		display7SEG(led_buffer[0]);
// 		break;
// 	case 1:
// 		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
// 		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
// 		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
// 		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
// 		display7SEG(led_buffer[1]);
// 		break;
// 	case 2:
// 		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
// 		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
// 		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
// 		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
// 		display7SEG(led_buffer[2]);
// 		break;
// 	case 3:
// 		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
// 		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
// 		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
// 		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
// 		display7SEG(led_buffer[3]);
// 		break;
// 	default:
// 		break;
// 	}
// }
// void updateLEDBuffer1(int num){
// 	if(num > -1){
// 		led_buffer[0] = num/10;
// 		led_buffer[1] = num%10;
// 		return;
// 	}
// 	if(num == -1){
// 		led_buffer[0] = 10;
// 		led_buffer[1] = 11;
// 		return;
// 	}
// 	if(num == -2){
// 		led_buffer[0] = 12;
// 		led_buffer[1] = 13;
// 		return;
// 	}
// 	if(num == -3){
// 		led_buffer[0] = 14;
// 		led_buffer[1] = 10;
// 		return;
// 	}
// }
// void updateLEDBuffer2(int num){
// 	if(num > -1){
// 		led_buffer[2] = num/10;
// 		led_buffer[3] = num%10;
// 		return;
// 	}

// 	if(num == -1){
// 		led_buffer[2] = 10;
// 		led_buffer[3] = 11;
// 		return;
// 	}
// 	if(num == -2){
// 		led_buffer[2] = 12;
// 		led_buffer[3] = 13;
// 		return;
// 	}
// 	if(num == -3){
// 		led_buffer[2] = 14;
// 		led_buffer[3] = 10;
// 		return;
// 	}

// }





