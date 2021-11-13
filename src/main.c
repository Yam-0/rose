#include "include/main.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *inputs[ROSE_MAX_BUFFERS];

	// Run normally if no input is given
	if (argc == 1)
	{
		printf("Opening empty\n");
		return rose_init(inputs);
	}

	int input_count = 0;
	enum rose_run_mode mode = mode_editor;
	enum rose_flag_id flag_id;

	for (int i = 0; i < argc - 1; i++)
	{
		char *arg = argv[i+1];
		flag_id = get_flag(arg);
		switch (flag_id)
		{
			case id_null:
				inputs[input_count] = arg;
				input_count++;
				break;

			case id_help:
				mode = mode_help;
				break;

			case id_version:
				mode = mode_version;
				break;
		}
	}

	switch (mode)
	{
		case mode_editor:
			return rose_init(inputs);
			break;

		case mode_help:
			printf("Epic help screen\n");
			exit(0);
			break;

		case mode_version:
			printf("Version: %s\n", ROSE_VERSION);
			printf("Made by Tage Åkerström 2021\n");
			exit(0);
			break;
	}
}

enum rose_flag_id get_flag(char *input)
{
	if (strcmp(input, "-v") == 0 ||
		strcmp(input, "-V") == 0 ||
		strcmp(input, "--version") == 0 )
	{
		return id_version;
	}

	if (strcmp(input, "-h") == 0 ||
		strcmp(input, "-H") == 0 ||
		strcmp(input, "--help") == 0 )
	{
		return id_help;
	}

	return id_null;
}
