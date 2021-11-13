#include "include/rose.h"
#include "include/state.h"

int rose_init()
{
	printf(" --- ROSE --- \n");
	state.running = 1;

	while (state.running)
	{
		printf("Running\n");
	}

	return 0;
}
