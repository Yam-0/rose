#include "include/rose.h"
#include "include/state.h"

int rose_init(char *input)
{
	printf(" --- ROSE --- \n");

	rose_state_init();

	if (input == NULL)
	{
		printf("No input, opening new buffer\n");
		state.process->process_type = 0;
	}

	while (state.running)
	{
		state.running = 0;
	}

	rose_state_destroy();

	return 0;
}
