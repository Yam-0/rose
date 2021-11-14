#ifndef ROSE_H
#define ROSE_H

#include "util.h"
#include "buffer.h"
#include "window.h"
#include "state.h"
#include "input.h"

int rose_init(char *inputs[ROSE_MAX_BUFFERS], int input_count);
int rose_load(char *str);
int rose_save(rose_buffer *buffer);
int rose_close(rose_buffer *buffer);
int rose_exit();

#endif
