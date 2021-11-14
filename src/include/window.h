#ifndef ROSE_WINDOW_H
#define ROSE_WINDOW_H

#include <sys/ioctl.h>
#include <unistd.h>

#include "util.h"
#include "structs.h"
#include "state.h"

int rose_window_init();
rose_point rose_getsize();

#endif
