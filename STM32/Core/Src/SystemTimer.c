/*
 * SystemTimer.c
 *
 *  Created on: 18 Sep 2024
 *      Author: pham1
 */
#include "SystemTimer.h"

#define MAX_TIMERS 10

int flag[MAX_TIMERS] = {0};
int counter = 10000;

//*************** Start implementation of Priority Queue ***************
typedef struct{
	int timer;
	int priority;
} event;

typedef struct{
	event data[MAX_TIMERS];
	int size;
} priorityQueue;

priorityQueue pq;

void initQueue(priorityQueue *pq){
	pq->size = 0;
}

void swapElements(event *a, event *b){
	event temp = *a;
	*a = *b;
	*b = temp;
}

// Max-heap
void heapifyUp(priorityQueue *pq, int index){
	int parentIndex = (index - 1) / 2;
	if (index > 0 && pq->data[index].priority > pq->data[parentIndex].priority) {
		swapElements(&pq->data[index], &pq->data[parentIndex]);
		heapifyUp(pq, parentIndex);
	}
}

void heapifyDown(priorityQueue *pq, int index) {
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	int largest = index;

	if (leftChild < pq->size && pq->data[leftChild].priority > pq->data[largest].priority) {
		largest = leftChild;
	}
	if (rightChild < pq->size && pq->data[rightChild].priority > pq->data[largest].priority) {
		largest = rightChild;
	}

	if (largest != index) {
		swapElements(&pq->data[index], &pq->data[largest]);
		heapifyDown(pq, largest);
	}
}

void enqueue(priorityQueue *pq, int timer, int priority) {
	if (pq->size < MAX_TIMERS) {
		pq->data[pq->size].timer = timer;
		pq->data[pq->size].priority = priority;
		heapifyUp(pq, pq->size);
		pq->size++;
	}
}

void dequeue(priorityQueue *pq) {
	pq->data[0] = pq->data[pq->size - 1];
	pq->size--;
	heapifyDown(pq, 0);
}

void addTimer(priorityQueue *pq, int timer, int priority) {
	static priorityQueue tmpQueue;
	static int tmpInit = 0;

	if (!tmpInit) {
		initQueue(&tmpQueue);
		tmpInit = 1;
	}

	if (priority > counter) {
		enqueue(&tmpQueue, timer, priority);
	} else {
		enqueue(pq, timer, priority);
	}

	if (pq->size == 0 && tmpQueue.size > 0) {
		*pq = tmpQueue;
		initQueue(&tmpQueue);
		tmpInit = 0;
	}
}
//*************** End implementation of Priority Queue ***************

void initTimer(){
    initQueue(&pq);
}
int isTimerFlagOn(int index){
	return (flag[index] == 1) ? 1 : 0;
}
void setTimer(int index, int duration){
    if (index >= 0 && index < MAX_TIMERS) {
        flag[index] = 0;
        int priority = counter - duration;
        if (priority < 0) priority += 1000;
        addTimer(&pq, index, priority);
    }
}
void timerRun(){
	if (pq.data[0].priority == counter){
		flag[pq.data[0].timer] = 1;
		dequeue(&pq);
	}
	counter--;
	if (counter < 0) counter = 1000;
}

