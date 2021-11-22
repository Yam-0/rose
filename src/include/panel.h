#ifndef ROSE_PANEL_H
#define ROSE_PANEL_H

#include "util.h"
#include "buffer.h"

enum rose_node_type {
	rose_node_panel,
	rose_node_vertical,
	rose_node_horizontal,
};

typedef struct rose_panel_node_item {
	struct rose_panel_node_item *parent;
	struct rose_panel_node_item *prev_sibling;
	struct rose_panel_node_item *next_sibling;
	struct rose_panel_node_item *first_child;
	rose_point relative_size;
	enum rose_node_type node_type;
	int child_count;

	rose_buffer *active_buffer;
} rose_panel_node;

int rose_panel_destroy();

#endif
