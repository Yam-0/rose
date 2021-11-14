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
	rose_point p1 = {0, 0};
	rose_point p2 = {0, 1};
	rose_window_print(p1, COLOR_WHITE, COLOR_BLACK, "ROSE TEXT EDITOR");
	rose_window_print(p2, COLOR_GREEN, COLOR_BLACK, "ROSE TEXT EDITOR");

	rose_window_draw_cursor();

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

int rose_window_draw_cursor()
{
	rose_point cursor_pos = state.process->cursor.pos;
	unsigned int cell = mvinch(cursor_pos.y, cursor_pos.x);
    const int color = cell & A_COLOR;

	int foreground;
    for (int i = 1; i <= 64; i++) {
		if (color == COLOR_PAIR(i))
		{
			foreground = i % 8;
		}
    }

	attrset(COLOR_PAIR(foreground * 8));
	mvaddch(cursor_pos.y, cursor_pos.x, cell & A_CHARTEXT);
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


