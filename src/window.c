#include "include/window.h"
#include <ncurses.h>

int rose_window_init()
{
	state.process->window = initscr();

	if (has_colors() == FALSE) {
		endwin();
		printf("Terminal does not support colors\n");
		exit(1);
	}

	start_color();

	// init color pairs
    for (int bg = 0; bg < 8; bg++) {
        for (int fg = 0; fg < 8; fg++) {
            init_pair(bg * 8 + fg, fg, bg);
        }
    }

	curs_set(0);
	cbreak();
	noecho();
	nodelay(state.process->window, TRUE);

	return 0;
}

int rose_window_draw()
{
	state.process->window_size = rose_getsize();

	rose_buffers buffers = state.process->buffers;
	rose_buffer *buffer = buffers.first;

	// Draw buffers
	while (buffer != NULL)
	{
		rose_buffer_draw(buffer);
		buffer = buffer->next;
	}

	return 0;
}

int rose_window_print(rose_point p, int foreground, int background, char *str)
{
	int pair = background * 8 + foreground;

	attrset(COLOR_PAIR(pair));
	mvaddstr(p.y, p.x, str);
	return 0;
}

int rose_window_put(rose_point p, int foreground, int background, char c)
{
	int pair = background * 8 + foreground;

	attrset(COLOR_PAIR(pair));
	mvaddch(p.y, p.x, c);
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


