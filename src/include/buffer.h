#ifndef ROSE_BUFFER_H
#define ROSE_BUFFER_H

#include "util.h"

typedef struct {
	int active;
	rose_point pos;
} rose_cursor;

enum rose_mode { mode_normal, mode_insert, mode_command, mode_select };
enum rose_buffer_type { rose_buffer_editor, rose_buffer_terminal, rose_buffer_programa };

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
	enum rose_buffer_type buffer_type;
	int id;
	char *file_name;
	char *file_path;

	struct rose_buffer_item *prev;
	struct rose_buffer_item *next;
} rose_buffer;

#endif
