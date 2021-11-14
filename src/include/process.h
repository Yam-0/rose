#ifndef ROSE_PROCESS_H
#define ROSE_PROCESS_H

#include "util.h"
#include "buffer.h"

enum rose_mode { mode_normal, mode_insert, mode_command, mode_select };

typedef struct {
	int visible;
	rose_point pos;
} rose_cursor;

typedef struct {
	WINDOW *window;

	enum rose_mode mode;
	rose_cursor cursor;
	rose_buffers buffers;
} rose_process;

#endif
