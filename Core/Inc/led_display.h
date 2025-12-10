/*
 * led_display.h
 *
 *  Created on: Oct 5, 2025
 *      Author: Vinh Le
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"

void set_rgy1(int color);
void set_rgy2(int color);

void toggle_rgy(uint8_t n);

void toggle_red1();
void toggle_yel1();
void toggle_gre1();

void toggle_red2();
void toggle_yel2();
void toggle_gre2();

void toggle_yel_gre();

void manual_red1_gre2();
void manual_red1_yel2();
void manual_gre1_red2();
void manual_yel1_red2();
void manual_all_yel();

#endif /* INC_LED_DISPLAY_H_ */
