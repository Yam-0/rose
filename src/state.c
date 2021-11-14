#include "include/state.h"

int rose_state_init()
{
	rose_process *process = malloc(sizeof(rose_process));
	state.process = process;

	state.running = 1;

	return 0;
}

int rose_state_destroy()
{
	free(state.process);
	return 0;
}
