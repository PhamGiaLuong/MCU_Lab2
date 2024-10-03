/*
 * SystemTimer.h
 *
 *  Created on: 18 Sep 2024
 *      Author: pham1
 */
#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

#include <main.h>
#include <stdlib.h>

void initTimer();
int isTimerFlagOn(int index);
void setTimer(int index, int duration);
void timerRun();

#endif /* INC_SOFTWARETIMER_H_ */
