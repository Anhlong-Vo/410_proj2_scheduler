/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/stats.h"
using namespace std;

Stats::Stats(vector<PCB> &finished_vector):vec(&finished_vector), av_wait_time(0),
		av_turnaround_time(0), av_response_time(0) {
	calcStats();
}

void Stats::calcStats() {
	for (PCB process : *vec) {
		av_wait_time += process.finish_time - process.arrival_time - process.required_cpu_time;
		av_response_time += process.start_time - process.arrival_time;
		av_turnaround_time += process.finish_time - process.arrival_time;
	}

	av_wait_time /= vec->size();
	av_response_time /= vec->size();
	av_turnaround_time /= vec->size();

}

void Stats::showAllProcessInfo() {

	for (PCB &process: *vec) {
		printf("Process %d Required CPU time:%d  arrived:%d started:%d finished:%d\n", process.process_number,
				process.required_cpu_time, process.arrival_time,process.start_time,  process.finish_time);
	}

}

float Stats::get_av_response_time() {

	return av_response_time;
}

float Stats::get_av_turnaround_time() {

	return av_turnaround_time;
}

float Stats::get_av_wait_time() {

	return av_wait_time;
}
