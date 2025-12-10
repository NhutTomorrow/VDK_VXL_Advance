/*
 * traffic_light.c
 *
 *  Created on: Sep 26, 2025
 *      Author: ASUS
 */

#include <fsm_automatic.h>
#include "global.h"
#include "lcd_display.h"
#include "led_display.h"
#include "input_reading.h"
#include "input_processing.h"
#include "fsm_manual.h"

void fsm_automatic(){

	if (sys_state != AUTOMATIC_MODE) return;

	switch (auto_state) {
		case INIT_AUTO:
			time_road1 = time_red1;
			time_road2 = time_gre2;

			set_rgy1(LED_RED);
			set_rgy2(LED_GREEN);

			auto_state = RED1_GRE2_AUTO;

			display_auto_mode();
			setTimer(0, time_gre2 * 1000);
			setTimer(1, 1000);
			break;

		case RED1_GRE2_AUTO:
			set_rgy1(LED_RED);
			set_rgy2(LED_GREEN);

			if (isFlag(1) == 1) {
				display_auto_mode();
				time_road1--;
				time_road2--;

				setTimer(1, 1000);
			}

			if (isFlag(0) == 1) {
				auto_state = RED1_YEL2_AUTO;

				time_road1 = time_yel2;
				time_road2 = time_yel2;

				setTimer(0, time_yel2 * 1000);
				display_auto_mode();
			}
			break;

		case RED1_YEL2_AUTO:
			set_rgy1(LED_RED);
			set_rgy2(LED_YELLOW);

			if (isFlag(1) == 1) {
				display_auto_mode();
				time_road1--;
				time_road2--;

				setTimer(1, 1000);
			}

			if (isFlag(0) == 1) {
				auto_state = GRE1_RED2_AUTO;

				time_road1 = time_gre1;
				time_road2 = time_red2;

				setTimer(0, time_gre1 * 1000);
				display_auto_mode();
			}
			break;

		case GRE1_RED2_AUTO:
			set_rgy1(LED_GREEN);
			set_rgy2(LED_RED);

			if (isFlag(1) == 1) {
				display_auto_mode();
				time_road1--;
				time_road2--;

				setTimer(1, 1000);
			}

			if (isFlag(0) == 1) {
				auto_state = YEL1_RED2_AUTO;
				time_road1 = time_yel1;
				time_road2 = time_yel1;

				setTimer(0, time_yel1 * 1000);
				display_auto_mode();
			}
			break;

		case YEL1_RED2_AUTO:
			set_rgy1(LED_YELLOW);
			set_rgy2(LED_RED);

			if (isFlag(1) == 1) {
				display_auto_mode();
				time_road1--;
				time_road2--;

				setTimer(1, 1000);
			}

			if (isFlag(0) == 1) {
				auto_state = RED1_GRE2_AUTO;

				time_road1 = time_red1;
				time_road2 = time_gre2;

				setTimer(0, time_gre2 * 1000);
				display_auto_mode();
			}
			break;

		default:
			auto_state = RED1_GRE2_AUTO;
			break;
	}
}







