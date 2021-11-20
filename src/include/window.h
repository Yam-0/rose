#ifndef ROSE_WINDOW_H
#define ROSE_WINDOW_H

#include <curses.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "util.h"
#include "structs.h"
#include "state.h"
#include "color.h"

int rose_window_init();

int rose_window_draw();
int rose_window_draw_background();

int rose_window_print(rose_point p, int foreground, int background, char *str); int rose_window_put(rose_point p, int foreground, int background, char c);
int rose_window_putxy(int x, int y, int foreground, int background, char c);

int rose_node_draw(rose_panel_node *node, rose_point position, rose_point size);

int rose_panel_split(int vertical);
int rose_panel_focus(int vertical, int direction_forward);
int rose_panel_draw(rose_panel_node *node, rose_point pos, rose_point size);
int rose_panel_draw_cursors(rose_panel_node *node);

rose_point rose_getsize();

#endif
