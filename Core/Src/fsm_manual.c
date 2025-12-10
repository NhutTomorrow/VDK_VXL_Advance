/*
 * fsm_manual.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Vinh Le
 */
#include "global.h"


void fsm_manual(void){
    if(sys_state != MANUAL_MODE) return;

    switch(manual_state){

    case RED1_GRE2_MANU:
        manual_red1_gre2(); 

        if(isSinglePressed(1)){
            manual_state = RED1_YEL2_MANU;
            setTimer(2, 2000);       
            display_manual_mode();
            resetButton(1);
        }

        break;

    case RED1_YEL2_MANU:
        manual_red1_yel2();

        if(isFlag(2) == 1){
            manual_state = GRE1_RED2_MANU;
            display_manual_mode();
        }

        break;

    case GRE1_RED2_MANU:
        manual_gre1_red2(); 

        if(isSinglePressed(1)){
            manual_state = YEL1_RED2_MANU;
            setTimer(2, 2000);        
            display_manual_mode();
            resetButton(1);
        }

        break;

    case YEL1_RED2_MANU:
        manual_yel1_red2();

        if(isFlag(2) == 1){
            manual_state = RED1_GRE2_MANU;
            display_manual_mode();
        }

        break;

    default:
        manual_state = RED1_GRE2_MANU;
        break;
    }
}


