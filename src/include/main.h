#ifndef MAIN_H
#define MAIN_H

#include "rose.h"
#include "util.h"

enum rose_flag_id { id_null, id_help, id_version };
enum rose_run_mode { mode_editor, mode_ersion, mode_help };

typedef struct {
	enum rose_flag_id id;
	char flag[32];
} rose_flag;

typedef struct {
	rose_flag flag;
	char *value;
} rose_flag_data_pair;

rose_flag help = { id_help, "-h" };
rose_flag version = { id_version, "-v" };

enum rose_flag_id get_flag(char *input);

#endif

