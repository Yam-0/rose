#include "include/state.h"

int rose_state_init()
{
	// Init State
	state.running = 1;
	state.focused = 1;

	// Init process
	rose_process *process = malloc(sizeof(rose_process));
	state.process = process;

	// Init panel node tree
	rose_panel_node *master = malloc(sizeof(rose_panel_node));
	state.process->master_node = master;
	master->node_type = rose_node_vertical;

	// Master node
	rose_panel_node *main = malloc(sizeof(rose_panel_node));
	main->node_type = rose_node_panel;
	main->parent = master;
	state.process->active_node = main;
	master->first_child = main;
	master->child_count = 1;

	return 0;
}

int rose_state_destroy()
{
	return 0;
}
