/*
 * input_processing.h
 *
 *  Created on: Oct 2, 2025
 *      Author: Vinh Le
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

void button_processing(void);

void single_press_handler(int index);
void double_press_handler(int index);
void immediately_1s_press(int index);
void continuously_press_handler(int index);

int isSinglePressed(int button_idx);
int isDoublePressed(int button_idx);
int isImmediately1sPressed(int button_idx);
int isContinuouslyPressed(int button_idx);

void resetButton(int button_idx);

#endif /* INC_INPUT_PROCESSING_H_ */
