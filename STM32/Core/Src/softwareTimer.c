/*
 * SystemTimer.c
 *
 *  Created on: 18 Sep 2024
 *      Author: pham1
 */
#include "softwareTimer.h"

#define MAX_TIMERS 10

int flag[MAX_TIMERS] = {0};
int timerCounter[MAX_TIMERS] = {0};

int isTimerFlagOn(int index){
	return (flag[index-1] == 1) ? 1 : 0;
}
void setTimer(int timer, int duration){
	flag[timer-1] = 0;
	timerCounter[timer-1] = duration;
}
void timerRun(){
	if (timerCounter[0] > 0){
		timerCounter[0]--;
		if (timerCounter[0] <= 0){
			flag[0] = 1;
		}
	}
	if (timerCounter[1] > 0){
		timerCounter[1]--;
		if (timerCounter[1] <= 0){
			flag[1] = 1;
		}
	}
	if (timerCounter[2] > 0){
		timerCounter[2]--;
		if (timerCounter[2] <= 0){
			flag[2] = 1;
		}
	}
	if (timerCounter[3] > 0){
		timerCounter[3]--;
		if (timerCounter[3] <= 0){
			flag[3] = 1;
		}
	}
	if (timerCounter[4] > 0){
		timerCounter[4]--;
		if (timerCounter[4] <= 0){
			flag[4] = 1;
		}
	}
}
