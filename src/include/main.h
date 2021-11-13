#ifndef MAIN_H
#define MAIN_H

#include "rose.h"
#include "util.h"

enum rose_flag_id { id_null, id_help, id_version };
enum rose_run_mode { mode_editor, mode_version, mode_help };

enum rose_flag_id get_flag(char *input);

#endif

