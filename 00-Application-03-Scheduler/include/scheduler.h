/*
 * scheduler.h
 *
 *  Created on: Mar 21, 2019
 *      Author: cssouza
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

typedef void (*Task)(void);

void register_task(Task task, int timeout);
void remove_task(Task task);


void scheduler_run();

#endif /* SCHEDULER_H_ */
