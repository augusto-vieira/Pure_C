/*
 * scheduler.c
 *
 *  Created on: Mar 21, 2019
 *      Author: cssouza
 */

#include "scheduler.h"

#include <stdlib.h>

#define MAX_TASKS 10

typedef struct sched{
	Task tasks[MAX_TASKS];
	int task_amount;
}Sched;

static Sched sched_ctx = {
		.task_amount = 0
};

void register_task(Task task, int timeout)
{
	if(sched_ctx.task_amount <= MAX_TASKS)
	{
		sched_ctx.tasks[sched_ctx.task_amount] = task;
		sched_ctx.task_amount++;
	}
}

void remove_task(Task task)
{
	if(sched_ctx.task_amount > 0)
	{
		sched_ctx.tasks[sched_ctx.task_amount] = NULL;
		sched_ctx.task_amount--;
	}
}

void scheduler_run()
{
	int i = 0;
	while(1)
	{
		if(i < sched_ctx.task_amount)
		{
			sched_ctx.tasks[i]();
			i++;
		}
		else{
			i = 0;
		}
	}
}
