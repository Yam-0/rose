#ifndef ROSE_BUFFER_H
#define ROSE_BUFFER_H

#include "util.h"

typedef struct {
	char line[512];
} rose_line;

typedef struct {
	rose_line *prev;
	rose_line *line;
	rose_line *next;
} rose_lines;

typedef struct {
	rose_lines lines;
	char *name;
} rose_buffer;

typedef struct {
	rose_buffer *prev;
	rose_buffer *buffer;
	rose_buffer *next;
} rose_buffers;

int rose_buffer_load(char *str);
int rose_buffer_save(char *str);

#endif
