/*
 * SystemTimer.c
 *
 *  Created on: 18 Sep 2024
 *      Author: pham1
 */

#include "SystemTimer.h"

int timer1Flag = 0;
int timer1Counter = 0;

void setTimer1(int duration){
	timer1Counter = duration;
	timer1Flag = 0;
}

void timerRun(){
	if(timer1Counter > 0){
		timer1Counter--;
		if(timer1Counter <= 0){
			timer1Flag = 1;
		}
	}
}

