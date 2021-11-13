#include "include/rose.h"
#include "include/state.h"

rose_state state;

int rose_init(char *inputs[ROSE_MAX_BUFFERS])
{
	rose_state_init();

	if (inputs[0] == NULL)
	{
		printf("No input, opening new buffer\n");
	}
	else {
		rose_load(inputs[0]);
	}

	state.running = 1;
	while (state.running)
	{
		state.running = 0;
	}

	rose_state_destroy();

	return 0;
}

int rose_load(char *str)
{
	printf("Opening: %s\n\n", str);

	FILE *handle;
	char character;
    char *line = NULL;

    handle = fopen(str, "r");
    if (handle == NULL)
	{
		printf("Oopsie woopsie\n");
		return 1;
	}

	while (ROSE_TRUE)
	{
		character = getc(handle);
		if (character == EOF)
			break;

		putchar(character);
	}

    fclose(handle);

	printf("\n");
	return 0;
}
