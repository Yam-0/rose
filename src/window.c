#include "include/window.h"

int rose_window_init()
{
	state.process->window = initscr();

	rose_color_init();

	curs_set(0);
	cbreak();
	noecho();
	nodelay(state.process->window, TRUE);

	erase();

	return 0;
}

int rose_window_draw()
{
	// If size change
	rose_point window_size = rose_getsize();
	if (window_size.x != state.process->window_size.x || window_size.y != state.process->window_size.y)
	{
		state.process->window_size.x = window_size.x;
		state.process->window_size.y = window_size.y;
		rose_window_draw_background();
	}


	// Draw panels
	rose_panel_node *master = state.process->master_node;
	rose_point start_position = { 1, 1 };
	rose_point start_size = { window_size.x - 2, window_size.y - 2 };
	rose_node_draw(master, start_position, start_size);

	return 0;
}

int rose_window_draw_background()
{
	rose_point window_size = state.process->window_size;

	for (int x = 0; x < window_size.x; x++)
	{
		for (int y = 0; y < window_size.y; y++)
		{
			rose_point p = { x, y };
			rose_window_put(p, ROSE_COLOR_DARK_1, ROSE_COLOR_DARK_0, ' ');
		}
	}

	return 0;
}

int rose_window_print(rose_point p, int foreground, int background, char *str)
{
	int pair = background * 8 + foreground;

	attrset(COLOR_PAIR(pair));
	mvaddstr(p.y, p.x, str);
	return 0;
}

int rose_window_put(rose_point p, int foreground, int background, char c)
{
	int pair = background * 8 + foreground;

	attrset(COLOR_PAIR(pair));
	mvaddch(p.y, p.x, c);
	return 0;
}

int rose_window_putxy(int x, int y, int foreground, int background, char c)
{
	rose_point p = { x, y };
	return rose_window_put(p, foreground, background, c);
}

int rose_node_draw(rose_panel_node *node, rose_point position, rose_point size)
{
	if (node == NULL)
		return 0;

	// Is parent split type vertical
	int split_type_vertical = node->parent != NULL ? node->parent->node_type == rose_node_vertical ? 1 : 0 : 0;
	int split_type_horizontal = node->parent != NULL ? node->parent->node_type == rose_node_horizontal ? 1 : 0 : 0;

	rose_point new_position = position;
	rose_point new_size = size;

	int offset;
	int remaining_size;

	if (split_type_vertical)
	{
		new_size.x = size.x;
		offset = size.x;
		remaining_size = size.x;
	}
	if (split_type_horizontal)
	{
		new_size.y = size.y;
		offset = size.y;
		remaining_size = size.y;
	}

	int sibling_count = 1;

	if (node->parent != NULL)
	{
		sibling_count = node->parent->child_count;
		if (sibling_count > 1)
		{
			if (split_type_vertical)
			{
				offset = size.x / sibling_count + node->relative_size.x;
			}
			if (split_type_horizontal)
			{
				offset = size.y / sibling_count + node->relative_size.y;
			}
		}
	}

	// Draw self and siblings then draw children
	rose_panel_node *step_node = node;
	int sibling_index = 0;
	while (step_node != NULL)
	{
		if (split_type_vertical)
			new_size.x = offset;
		if (split_type_horizontal)
			new_size.y = offset;

		// If last
		if (step_node->next_sibling == NULL)
		{
			if (split_type_vertical)
			{
				new_position.x = position.x + size.x - remaining_size;
				new_size.x = remaining_size;
			}
			if (split_type_horizontal)
			{
				new_position.y = position.y + size.y - remaining_size;
				new_size.y = remaining_size;
			}
		}
		else
		{
			if (split_type_vertical)
			{
				new_position.x = position.x + new_size.x * sibling_index;
				remaining_size -= new_size.x;
				new_size.x--;
			}
			if (split_type_horizontal)
			{
				new_position.y = position.y + new_size.y * sibling_index;
				remaining_size -= new_size.y;
				new_size.y--;
			}
		}

		if (step_node->node_type == rose_node_panel)
			rose_panel_draw(step_node, new_position, new_size);

		if (step_node->first_child != NULL)
			rose_node_draw(step_node->first_child, new_position, new_size);

		sibling_index++;
		step_node = step_node->next_sibling;
	}

	return 0;
}

int rose_panel_split(int vertical)
{
	rose_panel_node *node = state.process->active_node;

	if (node->node_type == rose_node_panel)
	{
		rose_panel_node *split_node = malloc(sizeof(rose_panel_node));
		split_node->parent = node->parent;
		split_node->node_type = rose_node_panel;

		if (node->parent->child_count > 1)
		{
			if ((vertical && node->parent->node_type == rose_node_horizontal) ||
				(!vertical && node->parent->node_type == rose_node_vertical))
			{
				rose_panel_node *split_node_sibling = malloc(sizeof(rose_panel_node));

				// Parent
				split_node->parent = node;
				split_node_sibling->parent = node;

				// Node type
				node->node_type = vertical ? rose_node_vertical : rose_node_horizontal;
				split_node->node_type = rose_node_panel;
				split_node_sibling->node_type = rose_node_panel;

				// Children
				node->first_child = split_node;

				// Child count
				node->child_count = 2;

				// Sibling
				node->first_child->next_sibling = split_node_sibling;
				split_node_sibling->prev_sibling = split_node;

				// Active buffer
				split_node->active_buffer = node->active_buffer;
				split_node_sibling->active_buffer = node->active_buffer;
				node->active_buffer = NULL;

				// Active node
				state.process->active_node = split_node;

				return 0;
			}
		}
		else
		{
			node->parent->node_type = vertical ? rose_node_vertical : rose_node_horizontal;
		}

		node->parent->child_count++;

		if (node->next_sibling != NULL)
		{
			node->next_sibling->prev_sibling = split_node;
			split_node->next_sibling = node->next_sibling;
		}
		node->next_sibling = split_node;

		split_node->prev_sibling = node;

		split_node->active_buffer = node->active_buffer;

		state.process->active_node = split_node;
	}

	return 0;
}

int rose_panel_resize(int vertical, int add_offset)
{
	/* rose_panel_node *node = state.process->active_node; */

	/* if (vertical) */
	/* { */
	/* 	node->relative_size.x += add_offset; */
	/* } */
	/* else */
	/* { */

	/* } */

	return 0;
}

int rose_panel_temp_layout()
{
	rose_panel_split(1);
	rose_panel_split(0);
	state.process->active_node = state.process->master_node->first_child;

	return 0;
}

int rose_panel_close(rose_panel_node *node)
{
	rose_panel_destroy(node);

	return 0;
}

int rose_panel_focus(int vertical, int direction_forward, int depth)
{
	rose_panel_node *active_node = state.process->active_node;
	if (active_node->node_type != rose_node_panel)
		return 1;

	rose_panel_node *target = active_node;
	int node_type;
	int search_depth = depth;

	while (1)
	{
		if (target == NULL)
			return 0;
		if (target->parent == NULL)
			return 0;

		node_type = target->parent->node_type == rose_node_vertical ? 1 : 0;
		if (node_type == vertical)
		{
			search_depth--;
			if (search_depth <= 0)
				break;
		}

		target = target->parent;
	}

	// Target is root sibling under first matching parent

	if (direction_forward)
		target = target->next_sibling;
	else
		target = target->prev_sibling;
	if (target == NULL)
	{
		rose_panel_focus(vertical, direction_forward, depth + 1);
		return 0;
	}

	// Target is next matching root parent

	while (1)
	{
		if (target == NULL)
			return 0;

		if (target->node_type == rose_node_panel)
		{
			state.process->active_node = target;
			return 0;
		}

		target = target->first_child;
	}

	return 0;
}

int rose_panel_destroy(rose_panel_node *node)
{
	// Temp
	free(node);
	return 0;
}

int rose_panel_draw(rose_panel_node *node, rose_point pos, rose_point size)
{
	size.x--;
	int border_color = ROSE_COLOR_DARK_3;
	if (node == state.process->active_node)
		border_color = ROSE_COLOR_GREEN;

	// Draw borders
	for (int y = 0; y < size.y; y++)
	{
		rose_window_putxy(pos.x, pos.y + y, ROSE_COLOR_DARK_3, border_color, ' ');
		rose_window_putxy(pos.x + size.x, pos.y + y, ROSE_COLOR_DARK_3, border_color, ' ');
	}

	for (int x = 0; x < size.x - 1; x++)
	{
		rose_window_putxy(pos.x + x + 1, pos.y, ROSE_COLOR_DARK_3, border_color, ' ');
		rose_window_putxy(pos.x + x + 1, pos.y + size.y - 1, ROSE_COLOR_DARK_3, border_color, ' ');
	}

	/* rose_window_putxy(pos.x + size.x, pos.y + size.y - 1, ROSE_COLOR_DARK_3, ROSE_COLOR_RED, ' '); */
	/* rose_window_putxy(pos.x, pos.y, ROSE_COLOR_DARK_3, ROSE_COLOR_RED, ' '); */

	rose_panel_draw_cursors(node);

	return 0;
}

int rose_panel_draw_cursors(rose_panel_node *node)
{
	/* unsigned int cell = mvinch(cursor.pos.y, cursor.pos.x); */
    /* const int color = cell & A_COLOR; */

	/* int foreground; */
    /* for (int i = 1; i <= 64; i++) { */
	/* 	if (color == COLOR_PAIR(i)) */
	/* 	{ */
	/* 		foreground = i % 8; */
	/* 	} */
    /* } */

	/* attrset(COLOR_PAIR(foreground * 8)); */
	/* mvaddch(cursor.pos.y, cursor.pos.x, cell & A_CHARTEXT); */

	return 0;
}

// Only works on linux
rose_point rose_getsize()
{
	rose_point point;

	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	point.x = w.ws_col;
	point.y = w.ws_row;

	return point;
}
