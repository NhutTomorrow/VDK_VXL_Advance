/*
 * fsm_manual.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Vinh Le
 */
#include "global.h"
#include "fsm_manual.h"
#include "led_display.h"
#include "lcd_display.h"
#include "input_processing.h"
#define LED_RED 0
#define LED_GREEN 1
#define LED_YELLOW 2
void fsm_manual(void){
    if(sys_state != MANUAL_MODE) return;

    switch(manual_state){
    case INIT_MANUAL:
        manual_state = RED1_GRE2;
        display_manual_mode();
        break;

    // ====================================================
    // 1. TRẠNG THÁI: ĐỎ 1 - XANH 2 (ĐANG ĐỨNG YÊN)
    // ====================================================
    case RED1_GRE2:
        manual_red1_gre2(); // Đèn sáng cứng

        // NHẤN NÚT 1: Muốn đổi cho Lộ 1 chạy -> Chuyển Lộ 2 sang Vàng
        if(isSinglePressed(1)){
            manual_state = RED1_YEL2; // Chuyển sang bước đệm
            setTimer(4, 2000);        // Đếm 2 giây
            display_manual_mode();
        }

        if(isSinglePressed(2)) manual_state = HANDLE_MANUAL;
        break;

    // ====================================================
    // 2. TRẠNG THÁI ĐỆM: ĐỎ 1 - VÀNG 2
    // ====================================================
    case RED1_YEL2:
        manual_red1_yel2();

        // Hết 2s đèn Vàng -> NHẢY THẲNG SANG XANH 1
        if(isFlag(4)){
            manual_state = GRE1_RED2; // <--- SỬA LỖI TẠI ĐÂY (Về Đích Xanh 1)
            display_manual_mode();
            // Không setTimer nữa, đứng yên tại đích
        }

        if(isSinglePressed(2)) manual_state = HANDLE_MANUAL;
        break;

    // ====================================================
    // 3. TRẠNG THÁI: XANH 1 - ĐỎ 2 (ĐANG ĐỨNG YÊN)
    // ====================================================
    case GRE1_RED2:
        manual_gre1_red2(); // Đèn sáng cứng

        // NHẤN NÚT 1: Muốn đổi cho Lộ 2 chạy -> Chuyển Lộ 1 sang Vàng
        if(isSinglePressed(1)){
            manual_state = YEL1_RED2; // Chuyển sang bước đệm
            setTimer(4, 2000);        // Đếm 2 giây
            display_manual_mode();
        }

        if(isSinglePressed(2)) manual_state = HANDLE_MANUAL;
        break;

    // ====================================================
    // 4. TRẠNG THÁI ĐỆM: VÀNG 1 - ĐỎ 2
    // ====================================================
    case YEL1_RED2:
        manual_yel1_red2();

        // Hết 2s đèn Vàng -> NHẢY THẲNG SANG XANH 2
        if(isFlag(4)){
            manual_state = RED1_GRE2; // <--- Về Đích ban đầu (Xanh 2)
            display_manual_mode();
            // Không setTimer nữa, đứng yên tại đích
        }

        if(isSinglePressed(2)) manual_state = HANDLE_MANUAL;
        break;

    // ====================================================
    // XỬ LÝ THOÁT
    // ====================================================
    case HANDLE_MANUAL:
        sys_state = AUTOMATIC_MODE;
        auto_state = RED1_GRE2_AUTO;
        time_road1 = time_red1;
        time_road2 = time_gre2;
        setTimer(0, time_gre2 * 1000);
        setTimer(1, 1000);
//        lcd_clear_display();
        break;

    default:
        manual_state = RED1_GRE2;
        break;
    }
}
//void manual_red1_gre2(){
//    set_rgy1(0b11); // Đỏ 1
//    set_rgy2(0b10); // Xanh 2
//}
//void manual_red1_yel2(){
//    set_rgy1(0b11); // Đỏ 1
//    set_rgy2(0b01); // Vàng 2
//}
//void manual_gre1_red2(){
//    set_rgy1(0b10); // Xanh 1
//    set_rgy2(0b11); // Đỏ 2
//}
//void manual_yel1_red2(){
//    set_rgy1(0b01); // Vàng 1
//    set_rgy2(0b11); // Đỏ 2
//}
//void manual_all_yel(){
////	set_rgy1(0b00);
////		set_rgy2(0b00);
//	set_rgy1(0b01);
//	set_rgy2(0b01);
//}


void manual_red1_gre2(){
    set_rgy1(LED_RED);   // Đỏ 1
    set_rgy2(LED_GREEN); // Xanh 2
}

void manual_red1_yel2(){
    set_rgy1(LED_RED);    // Đỏ 1
    set_rgy2(LED_YELLOW); // Vàng 2
}

void manual_gre1_red2(){
    set_rgy1(LED_GREEN); // Xanh 1
    set_rgy2(LED_RED);   // Đỏ 2
}

void manual_yel1_red2(){
    set_rgy1(LED_YELLOW); // Vàng 1
    set_rgy2(LED_RED);    // Đỏ 2
}
