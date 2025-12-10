/*
 * global.h
 *
 *  Created on: Oct 31, 2025
 *      Author: Vinh Le
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
/// Các trạng thái hệ thống
typedef enum {
    INIT_MODE,
    MANUAL_MODE,
    AUTOMATIC_MODE,
    CONFIG_MODE
} SystemState_t;

// Các trạng thái khi chạy đèn giao thông bằng tay
typedef enum {
	INIT_MANUAL,
	RED1_GRE2,
	RED1_YEL2,
	GRE1_RED2,
	YEL1_RED2,
	HANDLE_MANUAL,
    ALL_YEL
} ManualState_t;

// Các trạng thái khi chạy đèn giao thông tự động
typedef enum{
	INIT_AUTO,
	RED1_GRE2_AUTO,
	RED1_YEL2_AUTO,
	GRE1_RED2_AUTO,
	YEL1_RED2_AUTO
} AutomaticState_t;

// Các trạng thái config
typedef enum{
    SET_RED1,
    SET_YEL1,
    SET_GRE1,

    SET_RED2,
    SET_YEL2,
    SET_GRE2,

    ERR_SYNC_R2,        //khi red2 != gre1 + yel1
    ERR_SYNC_GY2       //khi gre2 + yel2 != red1 
}ConfigState_t;


extern SystemState_t sys_state;
extern ManualState_t manual_state;
extern AutomaticState_t auto_state;
extern ConfigState_t config_state;

// extern int single_1;
// extern int single_2;
// extern int single_3;

// extern int double_1;
// extern int double_2;
// extern int double_3;

// extern int long_1;
// extern int long_2;
// extern int long_3;

// Đếm ngược trong các trạng thái ERR
extern int countdown;

//Quyết định tăng hay giảm khi nhấn button2 trong config
//if increase_time = 1 -> ++new_time else --new_time
extern int increase_time; 

//Dùng khi tăng giảm trong set
extern int new_time;

// Dùng để nạp giá trị từ set (trước kiểm tra)
extern int new_red1;
extern int new_yel1;
extern int new_gre1;
extern int new_red2;
extern int new_yel2;
extern int new_gre2;

// Dùng khi nạp vào Auto (sau kiểm tra)
extern int time_red1;
extern int time_yel1;
extern int time_gre1;
extern int time_red2;
extern int time_yel2;
extern int time_gre2;

extern int time_road1;
extern int time_road2;



#endif /* INC_GLOBAL_H_ */
