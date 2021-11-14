#include "include/window.h"

int rose_window_init()
{
	state.process->window = initscr();


	if (has_colors())
		start_color();

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);

	attrset(COLOR_PAIR(2));

	curs_set(0);
	cbreak();
	noecho();
	nodelay(state.process->window, TRUE);

	return 0;
}

// Only works on linux
rose_point rose_getsize()
{
	rose_point point;

	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	point.x = w.ws_col;
	point.y = w.ws_row;

	return point;
}


