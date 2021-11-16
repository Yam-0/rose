#include "include/window.h"

int rose_window_init()
{
	state.process->window = initscr();

	rose_color_init();

	curs_set(0);
	cbreak();
	noecho();
	nodelay(state.process->window, TRUE);

	erase();

	return 0;
}

int rose_node_draw(rose_panel_node *node)
{


	return 0;
}

int rose_window_draw()
{
	// If size change
	rose_point window_size = rose_getsize();
	if (window_size.x != state.process->window_size.x || window_size.y != state.process->window_size.y)
	{
		state.process->window_size.x = window_size.x;
		state.process->window_size.y = window_size.y;
		rose_window_draw_background();
	}

	// Draw panels
	rose_panel_node *master = state.process->master_node;
	rose_node_draw(master);

	// TEMP
	rose_point pos = { 1, 1 };
	rose_point size = { window_size.x - 2, window_size.y - 2 };
	rose_panel_draw(NULL, pos, size);

	return 0;
}

int rose_window_draw_background()
{
	rose_point window_size = state.process->window_size;

	for (int x = 0; x < window_size.x; x++)
	{
		for (int y = 0; y < window_size.y; y++)
		{
			rose_point p = { x, y };
			rose_window_put(p, ROSE_COLOR_DARK_1, ROSE_COLOR_DARK_0, ' ');
		}
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

int rose_window_putxy(int x, int y, int foreground, int background, char c)
{
	rose_point p = { x, y };
	return rose_window_put(p, foreground, background, c);
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

int rose_panel_split(int vertical)
{
	rose_point p = { 0, 0 };
	rose_window_print(p, ROSE_COLOR_BLUE, ROSE_COLOR_DARK_0, "SPLIT\n");

	rose_panel_node *master = state.process->master_node;

	return 0;
}

int rose_panel_draw(rose_panel_node *node, rose_point pos, rose_point size)
{
	// Draw borders
	for (int y = 0; y < size.y; y++)
	{
		rose_window_putxy(pos.x, pos.y + y, ROSE_COLOR_DARK_3, ROSE_COLOR_DARK_3, ' ');
		rose_window_putxy(size.x, pos.y + y, ROSE_COLOR_DARK_3, ROSE_COLOR_DARK_3, ' ');
	}

	for (int x = 0; x < size.x - 2; x++)
	{
		rose_window_putxy(pos.x + x + 1, pos.y, ROSE_COLOR_DARK_3, ROSE_COLOR_DARK_3, ' ');
		rose_window_putxy(pos.x + x + 1, pos.y + size.y - 1, ROSE_COLOR_DARK_3, ROSE_COLOR_DARK_3, ' ');
	}

	return 0;
}

int rose_buffer_draw_cursors(rose_panel_node *node)
{
	/* unsigned int cell = mvinch(cursor.pos.y, cursor.pos.x); */
    /* const int color = cell & A_COLOR; */

	/* int foreground; */
    /* for (int i = 1; i <= 64; i++) { */
	/* 	if (color == COLOR_PAIR(i)) */
	/* 	{ */
	/* 		foreground = i % 8; */
	/* 	} */
    /* } */

	/* attrset(COLOR_PAIR(foreground * 8)); */
	/* mvaddch(cursor.pos.y, cursor.pos.x, cell & A_CHARTEXT); */

	return 0;
}
