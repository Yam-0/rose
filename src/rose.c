#include "include/rose.h"
/* #include "include/state.h" */

rose_state state;

int rose_init(char *inputs[ROSE_MAX_BUFFERS], int input_count)
{
	rose_state_init();

	if (input_count == 0)
	{
		printf("No input, opening new buffer\n");
	}
	else {
		for (int i = 0; i < input_count; i++) {
			rose_buffer_load(inputs[i]);
		}
	}

	state.running = 1;
	while (state.running)
	{
		/* state.running = 0; */
		rose_point point = rose_getsize();
		/* printf("(%i, %i)\n", point.x, point.y); */

		for (int i = 0; i < point.x; i++)
		{
			printf("X");
		}
		printf("\n");
	}

	rose_state_destroy();

	return 0;
}

