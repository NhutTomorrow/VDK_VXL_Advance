/*
 * global.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Vinh Le
 */
#include "global.h"

SystemState_t sys_state = INIT_MODE;
ManualState_t manual_state = RED1_GRE2_MANU;
AutomaticState_t auto_state = INIT_AUTO;
ConfigState_t config_state = SET_RED1;

// Đếm ngược trong các trạng thái ERR
int countdown = 3;

//Quyết định tăng hay giảm khi nhấn button2 trong config
//if increase_time = 1 -> ++new_time else --new_time
int increase_time = 1;

//Dùng khi tăng giảm trong set
int new_time = 1;

// Dùng để nạp giá trị từ set (trước kiểm tra)
int new_red1 = 0;
int new_yel1 = 0;
int new_gre1 = 0;
int new_red2 = 0;
int new_yel2 = 0;
int new_gre2 = 0;

// Dùng khi nạp vào Auto (sau kiểm tra)
int time_red1 = 5;
int time_yel1 = 3;
int time_gre1 = 3;
int time_red2 = 6;
int time_yel2 = 2;
int time_gre2 = 3;


int time_road1 = 5;
int time_road2 = 3;
