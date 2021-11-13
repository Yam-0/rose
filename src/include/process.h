#ifndef ROSE_PROCESS_H
#define ROSE_PROCESS_H

#include "util.h"
#include "buffer.h"

enum rose_mode { mode_normal, mode_insert, mode_command, mode_select };

typedef struct {
	int visible;
	int px;
	int py;
} rose_cursor;

typedef struct {
	enum rose_mode mode;
	rose_cursor cursor;
	rose_buffers buffers;
} rose_process;

#endif
