/*
 * fsm_config.h
 *
 *  Created on: Oct 31, 2025
 *      Author: Vinh Le
 */

#ifndef INC_FSM_CONFIG_H_
#define INC_FSM_CONFIG_H_



void init_test();




void fsm_config(void);

void set_red1_handler();
void set_yel1_handler();
void set_gre1_handler();

void set_red2_handler();
void set_yel2_handler();
void set_gre2_handler();

void err_syn_r2_handler();
void err_syn_gy2_handler();

void change_continuously_newtime();

void ERR_SYN_R2_to_SET_YEL2();
void ERR_SYN_GY2_to_AUTOMATIC_MODE();

#endif /* INC_FSM_CONFIG_H_ */
