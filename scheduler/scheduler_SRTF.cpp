/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content
#include "../includes/scheduler_SRTF.h"
#include <algorithm>
#include <vector>

bool compareRemainingCPUTime(const PCB& b1,  const PCB& b2) {
	return b1.remaining_cpu_time < b2.remaining_cpu_time;
}


bool  Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {

	if (!isEmpty()) {
		sort();
		if (p.process_number != ready_q->front().process_number) {
			return true;
		}
	}
	return Scheduler::time_to_switch_processes(tick_count, p);
}

void Scheduler_SRTF::sort() {

	std::vector<PCB> qvector;
	int size = ready_q->size();
	for (int i = 0; i < size; i++) {
		qvector.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(qvector.begin(), qvector.end(), compareRemainingCPUTime);

	for (std::vector<PCB>::iterator itr = qvector.begin(); itr != qvector.end(); itr++) {
		ready_q->push(*itr);
	}

}
