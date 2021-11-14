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

	WINDOW *w = initscr();
	curs_set(0);

	if (has_colors())
		start_color();

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);

	attrset(COLOR_PAIR(2));

	cbreak();
	noecho();
	nodelay(w, TRUE);

	while (state.running)
	{
		char input = getch();

		/* if (input != ERR) */
		/* 	erase(); */

		if (input == 'l')
			state.process->cursor.pos.x++;
		if (input == 'k')
			state.process->cursor.pos.y--;
		if (input == 'j')
			state.process->cursor.pos.y++;
		if (input == 'h')
			state.process->cursor.pos.x--;

		rose_point pos = state.process->cursor.pos;
		mvaddch(pos.y, pos.x, 'X');
		refresh();
	}

	endwin();

	// Free everything
	rose_state_destroy();

	return 0;
}

