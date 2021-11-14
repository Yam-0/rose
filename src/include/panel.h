#ifndef ROSE_PANEL_H
#define ROSE_PANEL_H

#include "util.h"
#include "buffer.h"

typedef struct rose_panel_item {
	rose_buffer *buffer_active;
	rose_point size;

	struct rose_panel_item *next;
	int updated = 1;
} rose_panel;

int rose_panel_init();
int rose_panel_destroy();
int rose_panel_draw(rose_panel *panel);
int rose_panel_draw_cursors(rose_panel *panel);

#endif
