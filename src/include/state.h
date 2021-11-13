#ifndef ROSE_STATE_H
#define ROSE_STATE_H

typedef struct {
	int running;
	int focused;
} rose_state;

extern rose_state state;

#endif
