#include "include/main.h"

int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
		printf("Arg: %s\n", argv[i]);
	}

	if (argc > 1)
	{
		printf("Opening %s\n", argv[1]);
	}

	rose_init();

	return 0;
}
