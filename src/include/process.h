#ifndef ROSE_PROCESS_H
#define ROSE_PROCESS_H

#include "util.h"
#include "buffer.h"
#include "panel.h"

typedef struct {
	WINDOW *window;
	rose_point window_size;

	rose_buffer *buffer_first;
	rose_buffer *buffer_last;
	rose_panel *active_panel;
	rose_panel *panels_first;
} rose_process;

#endif
