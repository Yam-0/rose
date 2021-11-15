#ifndef ROSE_WINDOW_H
#define ROSE_WINDOW_H

#include <curses.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "util.h"
#include "structs.h"
#include "state.h"

int rose_window_init();
int rose_window_draw();

int rose_window_draw_background();

int rose_window_print(rose_point p, int foreground, int background, char *str);
int rose_window_put(rose_point p, int foreground, int background, char c);

rose_point rose_getsize();

#endif
