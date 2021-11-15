#include "include/panel.h"

int rose_panel_init()
{
	return 0;
}

int rose_panel_destroy()
{
	return 0;
}

int rose_panel_draw(rose_panel *panel)
{
	// Draw panel windows
	return 0;
}

int rose_buffer_draw_cursor(rose_buffer *buffer, rose_cursor cursor)
{
	unsigned int cell = mvinch(cursor.pos.y, cursor.pos.x);
    const int color = cell & A_COLOR;

	int foreground;
    for (int i = 1; i <= 64; i++) {
		if (color == COLOR_PAIR(i))
		{
			foreground = i % 8;
		}
    }

	attrset(COLOR_PAIR(foreground * 8));
	mvaddch(cursor.pos.y, cursor.pos.x, cell & A_CHARTEXT);
	return 0;
}
