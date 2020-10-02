/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/scheduler.h"
using namespace std;

int start = 0;
void Scheduler::add(PCB p) {

	ready_q->push(p);
	sort();
}

PCB Scheduler::getNext() {
	PCB tmp = ready_q->front();
	ready_q->pop();
	sort();
	return tmp;
}

bool Scheduler::isEmpty() {
	return ready_q->empty();
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {

	if (p.remaining_cpu_time == 0 || p.isEmpty()) {
		start = 1;

		return true;
	}

	if (preemptive) {
		if (start == time_slice) {
			start = 1;
			return true;
		}
	}

	start++;
	return false;
}

