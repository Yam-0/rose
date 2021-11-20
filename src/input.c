#include "include/input.h"
#include "include/color.h"

int rose_input_init()
{
	state.key_buffer = '\0';

	return 0;
}

int rose_input_update()
{
	char input = getch();
	if (input == ERR)
		return 0;

	rose_window_draw_background();

	if (state.key_buffer == '\0')
	{
		switch (input)
		{
			// Movement
			case 'h':
				break;
			case 'k':
				break;
			case 'l':
				break;
			case 'j':
				break;

			case CTRL('t'):
				state.key_buffer = CTRL('t');
				break;
			case ' ':
				state.key_buffer = ' ';
				break;
		}
	}
	else
	{
		if (state.key_buffer == CTRL('t') && input == 'v') { rose_panel_split(1); }
		if (state.key_buffer == CTRL('t') && input == 'h') { rose_panel_split(0); }
		if (state.key_buffer == CTRL('t') && input == 'q') { rose_panel_close(state.process->active_node); }
		if (state.key_buffer == ' ' && input == 'h') { rose_panel_focus(1, 0, 1); }
		if (state.key_buffer == ' ' && input == 'l') { rose_panel_focus(1, 1, 1); }
		if (state.key_buffer == ' ' && input == 'k') { rose_panel_focus(0, 0, 1); }
		if (state.key_buffer == ' ' && input == 'j') { rose_panel_focus(0, 1, 1); }

		state.key_buffer = '\0';
	}

	return 0;
}
