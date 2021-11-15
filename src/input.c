#include "include/input.h"

int rose_input_update()
{
	char input = getch();

	if (input != ERR)
		rose_window_draw_background();

	/* if (input == 'l') */
	/* 	state.process->buffers.active_buffer->cursors[0].pos.x++; */
	/* if (input == 'h') */
	/* 	state.process->buffers.active_buffer->cursors[0].pos.x--; */

	return 0;
}
