#include "include/main.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("Opening empty\n");
		return rose_init(NULL);
	}

	enum rose_run_mode mode;
	mode = mode_editor;

	enum rose_flag_id flag_id = get_flag(argv[1]);

	if (flag_id == id_null)
	{
		printf("Opening %s\n", argv[1]);
		return rose_init(argv[1]);
	}
	else
	{

	}
}

enum rose_flag_id get_flag(char *input)
{
	return id_null;
}
