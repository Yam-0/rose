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

	rose_panel_node *master_node;
	rose_panel_node *active_node;
} rose_process;

#endif
