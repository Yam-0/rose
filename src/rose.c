#include "include/rose.h"
#include "include/state.h"

int rose_init(char *input)
{
	printf(" --- ROSE --- \n");
	rose_state state = { 0, 0 };
	state.running = 1;

	if (input == NULL)
		printf("No input, opening new buffer\n");

	while (state.running)
	{
		state.running = 0;
	}

	return 0;
}
