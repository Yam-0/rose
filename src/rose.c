#include "include/rose.h"

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

	rose_window_init();

	while (state.running)
	{
		if (state.updated)
			erase();

		rose_input_update();

		rose_window_draw();

		refresh();
	}

	endwin();

	// Free everything
	rose_state_destroy();

	return 0;
}

