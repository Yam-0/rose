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
			rose_load(inputs[i]);
		}
	}

	rose_window_init();

	while (state.running)
	{
		if (state.updated)
			erase();

		rose_input_update();

		rose_window_draw();

		refresh();
	}

	rose_exit();

	return 0;
}

int rose_load(char *str)
{
	rose_buffer *buffer = malloc(sizeof(rose_buffer));

	FILE *handle;
	char c;
    char *line = NULL;

    handle = fopen(str, "r");
    if (handle == NULL)
	{
		printf("Oopsie woopsie\n");
		printf("File not found uwu\n");
		return 1;
	}

	while (ROSE_TRUE)
	{
		c = getc(handle);
		if (c == EOF)
			break;

		putchar(c);
	}

    fclose(handle);

	state.process->buffers.first = buffer;

	printf("\n");
	return 0;
}

int rose_save(rose_buffer *buffer)
{
	return 0;
}

int rose_close(rose_buffer *buffer)
{
	return 0;
}

int rose_exit()
{
	endwin();

	// Free everything
	rose_state_destroy();

	exit(EXIT_SUCCESS);
}
