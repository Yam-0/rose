#include "include/input.h"

int rose_input_update()
{
	char input = getch();
	if (input == ERR)
		return 0;

	rose_window_draw_background();

	enum rose_key_buffer last_key = state.key_buffer;
	state.key_buffer = rose_key_none;

	switch (input)
	{
		case 'v':
			switch (last_key)
			{
				case rose_key_none:
					// Visual mode
					break;

				case rose_key_split: // Vertical split
					rose_panel_split(1);
					break;
			}
			break;

		case 'h':
			switch (last_key)
			{
				case rose_key_none:
					// Move left
					break;

				case rose_key_split: // Horizontal split
					rose_panel_split(0);
					break;
			}
			break;

		case CTRL('t'):
			state.key_buffer = rose_key_split;
			break;
	}

	return 0;
}
