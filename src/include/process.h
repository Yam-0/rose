#ifndef ROSE_PROCESS_H
#define ROSE_PROCESS_H

#include "util.h"

typedef struct {
	int process_type;
	FILE *handle;
} rose_process;

#endif
