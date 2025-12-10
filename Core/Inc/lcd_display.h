/*
 * led_display.h
 *
 *  Created on: Oct 5, 2025
 *      Author: Vinh Le
 */

#ifndef INC_LCD_DISPLAY_H_
#define INC_LCD_DISPLAY_H_

#include "main.h"

void display_init_mode();

void display_auto_mode();
void display_manual_mode();

void display_set_config();
void display_err_config();
void display_value_confirmed();
#endif /* INC_LCD_DISPLAY_H_ */
