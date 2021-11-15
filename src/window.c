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

int rose_window_draw()
{
	// If size change
	rose_point size = rose_getsize();
	if (size.x != state.process->window_size.x || size.y != state.process->window_size.y)
	{
		state.process->window_size.x = size.x;
		state.process->window_size.y = size.y;
		rose_window_draw_background();
	}

	// Draw panels
	rose_panel *panel = state.process->panels_first;
	while (panel != NULL)
	{
		if (panel->update)
		{
			rose_panel_draw(panel);
			panel->update = 0;
		}

		panel = panel->next;
	}

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

	// TEMP
	rose_panel_draw(NULL);

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
	return 0;
}

int rose_panel_draw(rose_panel *panel)
{
	// Draw panel windows
	rose_point window_size = state.process->window_size;
	rose_point panel_size = { window_size.x - 2, window_size.y - 2};

	// Draw borders
	for (int y = 0; y < panel_size.y; y++)
	{
		rose_window_putxy(1, y + 1, ROSE_COLOR_DARK_3, ROSE_COLOR_DARK_3, ' ');
		rose_window_putxy(window_size.x - 2, y + 1, ROSE_COLOR_DARK_3, ROSE_COLOR_DARK_3, ' ');
	}

	for (int x = 0; x < panel_size.x; x++)
	{
		rose_window_putxy(x + 1, 1, ROSE_COLOR_DARK_3, ROSE_COLOR_DARK_3, ' ');
		rose_window_putxy(x + 1, window_size.y - 2, ROSE_COLOR_DARK_3, ROSE_COLOR_DARK_3, ' ');
	}

	return 0;
}

int rose_buffer_draw_cursors(rose_panel *panel)
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
