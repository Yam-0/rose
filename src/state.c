#include "include/state.h"

int rose_state_init()
{
	// Init State
	state.running = 1;
	state.focused = 1;
	state.updated = 1;

	// Init Process
	rose_process *process = malloc(sizeof(rose_process));
	state.process = process;

	// Init Panels
	rose_panel *panel = malloc(sizeof(rose_panel));
	state.process->panels_first = panel;
	state.process->active_panel = panel;

	return 0;
}

int rose_state_destroy()
{
	return 0;
}
