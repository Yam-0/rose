#include "include/buffer.h"

int rose_buffer_load(char *str)
{
	printf("Opening: %s\n\n", str);

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

	printf("\n");
	return 0;
}

int rose_buffer_save(char *str)
{
	return 0;
}
