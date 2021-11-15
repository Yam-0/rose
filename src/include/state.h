#ifndef ROSE_STATE_H
#define ROSE_STATE_H

#include "structs.h"
#include "process.h"

enum rose_key_buffer { rose_key_none, rose_key_split };

typedef struct {
	rose_process *process;
	enum rose_key_buffer key_buffer;

	int running;
	int focused;
} rose_state;

extern rose_state state;

int rose_state_init();
int rose_state_destroy();

#endif
