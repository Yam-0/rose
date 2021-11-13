#include "include/state.h"

int rose_state_init()
{
	rose_state state = { .running = 1, .focused = 1 };

	rose_process *process = malloc(sizeof(rose_process));
	state.process = process;

	return state.running;
}

int rose_state_destroy()
{
	free(state.process);
	return 0;
}
