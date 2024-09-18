/*
 * SystemTimer.h
 *
 *  Created on: 18 Sep 2024
 *      Author: pham1
 */

#ifndef INC_SYSTEMTIMER_H_
#define INC_SYSTEMTIMER_H_

extern int timer1Flag;
extern int timer2Flag;

void setTimer1(int duration);
void setTimer2(int duration);

void timerRun();

#endif /* INC_SYSTEMTIMER_H_ */
