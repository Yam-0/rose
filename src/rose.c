#include "include/rose.h"

rose_state state;

int rose_init(char *inputs[ROSE_MAX_BUFFERS], int input_count)
{
	rose_state_init();

	if (input_count == 0)
	{
		rose_load("");
	}
	else {
		for (int i = 0; i < input_count; i++) {
			rose_load(inputs[i]);
		}
	}

	rose_window_init();

	while (state.running)
	{
		rose_input_update();

		rose_window_draw();

		refresh();
	}

	rose_exit();

	return 0;
}

int rose_load(char *str)
{
	// Not implemented
	return 0;
	/*


	// Return if buffer already loeaded
	rose_buffer *exists = rose_find_buffer_str(str);
	if (exists)
	{
		state.process->active_panel->buffer_active = exists;
		return 0;
	}

	// Allocate buffer
	rose_buffer *buffer = malloc(sizeof(rose_buffer));
	rose_panel *panel = state.process->active_panel;
	panel->buffer_active = buffer;

	// Generate new id
	int id = 0;
	while (rose_find_buffer_id(id) != NULL)
		id++;
	buffer->id = id;

	// Buffer start info
	buffer->mode = mode_normal;
	buffer->buffer_type = rose_buffer_editor;
	buffer->cursors[0].active = 1;

	if (state.process->buffer_first == NULL)
	{
		state.process->buffer_first = buffer;
	}
	else
	{
		state.process->buffer_last->next = buffer;
		state.process->buffer_last = buffer;
	}

	// Open file
	FILE *handle;
    handle = fopen(str, "r");
    if (handle == NULL)
	{
		printf("Oopsie woopsie\n");
		printf("File not found uwu\n");
		return 1;
	}

	// Get file name and location
	int file_descriptor = fileno(handle);
	char *filename = malloc(255);
	char *path = malloc(255);

	buffer->file_path = path;
	buffer->file_name = filename;

	// Read chars
	char c;
	while (ROSE_TRUE)
	{
		char *line = NULL;
		c = getc(handle);
		if (c == EOF)
			break;

		putchar(c);
	}

    fclose(handle);
	return 0;
	*/
}

int rose_save(rose_buffer *buffer)
{
	return 0;
}

int rose_close(rose_buffer *buffer)
{
	return 0;
}

int rose_exit()
{
	endwin();

	// Free everything
	rose_state_destroy();

	exit(EXIT_SUCCESS);
}

rose_buffer *rose_find_buffer_id(int id)
{
	rose_buffer *buffer = state.process->buffer_first;
	while (buffer->next != NULL)
	{
		if (id == buffer->id)
			return buffer;

		buffer = buffer->next;
	}

	return NULL;
}

rose_buffer *rose_find_buffer_str(char *str)
{
	rose_buffer *buffer = state.process->buffer_first;
	while (buffer->next != NULL)
	{
		if (strcmp(str, buffer->file_name) == 0)
			return buffer;

		buffer = buffer->next;
	}

	return NULL;
}
