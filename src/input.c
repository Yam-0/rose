#include "include/input.h"

int rose_input_update()
{
	state.updated = ROSE_FALSE;

	char input = getch();

	if (input != ERR)
		state.updated = ROSE_TRUE;

	if (input == 'l')
		state.process->buffers.active_buffer->cursors[0].pos.x++;
	if (input == 'h')
		state.process->buffers.active_buffer->cursors[0].pos.x--;

	return 0;
}
