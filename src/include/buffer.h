#ifndef ROSE_BUFFER_H
#define ROSE_BUFFER_H

#include "util.h"

typedef struct {
	int visible;
	rose_point pos;
} rose_cursor;

enum rose_mode { mode_normal, mode_insert, mode_command, mode_select };

typedef struct {
	char line[512];
} rose_line;

typedef struct {
	rose_line *prev;
	rose_line *line;
	rose_line *next;
} rose_lines;

typedef struct rose_buffer_item {
	rose_lines lines;
	rose_cursor cursors[64];
	enum rose_mode mode;
	int id;
	char *name;
	char *location;

	struct rose_buffer_item *prev;
	struct rose_buffer_item *next;
} rose_buffer;

typedef struct {
	rose_buffer *first;
	rose_buffer *last;
	rose_buffer *active_buffer;
} rose_buffers;

int rose_buffer_draw(rose_buffer *buffer);
int rose_buffer_draw_cursor(rose_buffer *buffer, rose_cursor cursor);

#endif
