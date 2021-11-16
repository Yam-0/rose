#include "include/state.h"

int rose_state_init()
{
	// Init State
	state.running = 1;
	state.focused = 1;

	// Init Process
	rose_process *process = malloc(sizeof(rose_process));
	state.process = process;

	// Init Panels
	rose_panel_node *master = malloc(sizeof(rose_panel_node));
	state.process->master_node = master;

	return 0;
}

int rose_state_destroy()
{
	return 0;
}
