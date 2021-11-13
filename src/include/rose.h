#ifndef ROSE_H
#define ROSE_H

#include "util.h"

int rose_init(char *inputs[ROSE_MAX_BUFFERS]);
int rose_load(char *str);
int rose_save(char *str);

#endif
