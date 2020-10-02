/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/dispatcher.h"

PCB Dispatcher::get_from_CPU() {
	is_valid_job_on_cpu = false;
	return cpu->get_process_off_core();
}

void Dispatcher::put_on_CPU(PCB &process) {
	cpu->put_process_on_core(process);
	is_valid_job_on_cpu = true;
}

bool Dispatcher::isValidJobOnCPU() {
	if (!cpu->get_COPY_of_Current_Process().isEmpty()) {
		is_valid_job_on_cpu = true;
	}
	else {
		get_from_CPU();
	}
	return is_valid_job_on_cpu;
}
