#ifndef ROSE_PROCESS_H
#define ROSE_PROCESS_H

#include "util.h"
#include "buffer.h"

typedef struct {
	WINDOW *window;

	rose_point window_size;
	rose_buffers buffers;
} rose_process;

#endif
