#include "include/rose.h"
#include "include/state.h"

rose_state state;

int rose_init(char *inputs[ROSE_MAX_BUFFERS])
{
	rose_state_init();

	if (inputs[0] == NULL)
	{
		printf("No input, opening new buffer\n");
	}
	else {
		rose_buffer_load(inputs[0]);
	}

	state.running = 1;
	while (state.running)
	{
		state.running = 0;
	}

	rose_state_destroy();

	return 0;
}

