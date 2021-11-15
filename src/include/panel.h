#ifndef ROSE_PANEL_H
#define ROSE_PANEL_H

#include "util.h"
#include "buffer.h"

typedef struct rose_panel_item {
	rose_buffer *buffer_active;
	rose_point size_offset;

	struct rose_panel_item *next;
	int update;
} rose_panel;

int rose_panel_destroy();

#endif
