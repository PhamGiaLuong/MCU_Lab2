/*
 * SystemTimer.h
 *
 *  Created on: 18 Sep 2024
 *      Author: pham1
 */

#ifndef INC_SYSTEMTIMER_H_
#define INC_SYSTEMTIMER_H_

void initTimer();
int isTimerFlagOn(int index);
void setTimer(int index, int duration);
void timerRun();

#endif /* INC_SYSTEMTIMER_H_ */
