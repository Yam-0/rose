#include "include/input.h"

int rose_input_update()
{
	state.updated = ROSE_FALSE;

	char input = getch();

	if (input != ERR)
		state.updated = ROSE_TRUE;

	if (input == 'l')
		state.process->cursor.pos.x++;
	if (input == 'k')
		state.process->cursor.pos.y--;
	if (input == 'j')
		state.process->cursor.pos.y++;
	if (input == 'h')
		state.process->cursor.pos.x--;

	return 0;
}
