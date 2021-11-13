#ifndef ROSE_STATE_H
#define ROSE_STATE_H

#include "structs.h"
#include "process.h"

typedef struct {
	rose_process *process;

	int running;
	int focused;
} rose_state;

extern rose_state state;

int rose_state_init();
int rose_state_destroy();

#endif
