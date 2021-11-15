#include "include/color.h"

int rose_color_init()
{
	if (has_colors() == FALSE || can_change_color() == FALSE) {
		endwin();
		printf("Terminal does not fully support colors\n");
		exit(1);
	}

	if (start_color() != OK)
	{
		printf("Failed to start colors\n");
		exit(1);
	}

	init_color(ROSE_COLOR_DARK_0, 211, 211, 211);
	init_color(ROSE_COLOR_DARK_1, 267, 267, 267);
	init_color(ROSE_COLOR_DARK_2, 399, 399, 399);
	init_color(ROSE_COLOR_DARK_3, 598, 598, 598);
	init_color(ROSE_COLOR_WHITE, 1000, 1000, 1000);
	init_color(ROSE_COLOR_GREEN, 488, 746, 183);
	init_color(ROSE_COLOR_BLUE, 258, 520, 953);
	init_color(ROSE_COLOR_RED, 914, 262, 207);

	// init color pairs
    for (int bg = 0; bg < 8; bg++) {
        for (int fg = 0; fg < 8; fg++) {
            init_pair(bg * 8 + fg, fg, bg);
        }
    }



	return 0;
}
