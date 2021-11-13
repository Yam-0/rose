#include "include/main.h"

int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
		printf("Arg %i: %s\n", i + 1,  argv[i]);
	}

	if (argc > 1)
	{
		printf("Opening %s\n", argv[1]);
		return rose_init(argv[1]);
	}

	return rose_init(NULL);
}
