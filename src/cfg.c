
/* GENERATED BY ./gen_assets.py */

#include "cfg.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void parse_list(const char *_s, char ***arr, size_t *sz)
{
	size_t n;
	char *s;
	char **a;
	char *start;
	ssize_t len, i;

	n = 1;
	s = strdup(_s);
	len = strlen(s);

	for (i = 0; i < len; i++)
		if (s[i] == ' ')
			n++;

	a = malloc(n * sizeof(char *));

	n = 0;
	start = s;

	for (i = 0; i < len; i++)
		if (s[i] == ' ') {
			s[i++] = 0;
			while (s[i] == ' ')
				i++;

			a[n++] = start;
			start = &s[i];
		}

	a[n++] = start;

	*arr = a;
	*sz = n;
}

static int kvp(char *line, char **key, char **val)
{
	*key = NULL;
	*val = NULL;

	for (; *line != '\0'; line++) {
		if (*line != ' ' && !*key)
			*key = line;

		if (*line == ':' && !*val) {
			*line++ = '\0';
			for (; isspace(*line); line++)
				;
			*val = line;
		}
	}

	if (*(line - 1) == '\n')
		*(line - 1) = '\0';

	if (!(*val && *key))
		return -1;

	return 0;
}

struct cfg *parse_cfg(const char *fname)
{
	char *line;
	size_t n, ln;
	struct cfg *cfg = malloc(sizeof(struct cfg));
	FILE *fp = fopen(fname, "r");

	line = NULL;
    ln = 0;

	cfg->hint_activation_key = strdup("A-M-x");
	cfg->grid_activation_key = strdup("A-M-g");
	cfg->screen_activation_key = strdup("A-M-s");
	cfg->activation_key = strdup("A-M-c");
	cfg->hint_oneshot_key = strdup("A-M-l");
	cfg->repeat_interval = atoi("20");
	cfg->speed = atoi("220");
	cfg->max_speed = atoi("800");
	cfg->acceleration = atoi("700");
	parse_list("m , .", &cfg->buttons, &cfg->buttons_sz);
	parse_list("n - /", &cfg->oneshot_buttons, &cfg->oneshot_buttons_sz);
	cfg->oneshot_timeout = atoi("300");
	cfg->grid_exit = strdup("c");
	cfg->exit = strdup("esc");
	cfg->drag = strdup("v");
	cfg->copy_and_exit = strdup("c");
	cfg->hint = strdup("x");
	cfg->grid = strdup("g");
	cfg->screen = strdup("s");
	cfg->left = strdup("h");
	cfg->down = strdup("j");
	cfg->up = strdup("k");
	cfg->right = strdup("l");
	cfg->cursor_color = strdup("#FF4500");
	cfg->cursor_size = atoi("7");
	cfg->top = strdup("H");
	cfg->middle = strdup("M");
	cfg->bottom = strdup("L");
	cfg->start = strdup("0");
	cfg->end = strdup("$");
	cfg->hist_back = strdup("C-o");
	cfg->hist_forward = strdup("C-i");
	cfg->grid_nr = atoi("2");
	cfg->grid_nc = atoi("2");
	cfg->grid_up = strdup("w");
	cfg->grid_left = strdup("a");
	cfg->grid_down = strdup("s");
	cfg->grid_right = strdup("d");
	parse_list("u i j k", &cfg->grid_keys, &cfg->grid_keys_sz);
	cfg->grid_color = strdup("#1c1c1e");
	cfg->grid_size = atoi("4");
	cfg->grid_border_size = atoi("0");
	cfg->grid_border_color = strdup("#ffffff");
	cfg->hint_size = atoi("28");
	cfg->hint_bgcolor = strdup("#1c1c1e");
	cfg->hint_fgcolor = strdup("#a1aba7");
	cfg->hint_border_radius = atoi("3");
	cfg->scroll_down = strdup("e");
	cfg->scroll_up = strdup("r");
	cfg->screen_chars = strdup("jkl;asdfg");
	cfg->hint_chars = strdup("abcdefghijklmnopqrstuvwxyz");
	cfg->hint_font = strdup("Arial");

	if (!fp)
		return cfg; // Return defaults if no config file xists..

	while (getline(&line, &n, fp) != -1) {
		ln++;
		char *key, *val;

		if (line[0] == '\n' || line[0] == '\0')
			continue;

		if (kvp(line, &key, &val)) {
			fprintf(stderr, "Invalid entry in %s at line %lu.\n",
				fname, ln);
			exit(1);
		}

		        if(!strcmp(key, "hint_activation_key"))
            cfg->hint_activation_key = strdup(val);
        else if(!strcmp(key, "grid_activation_key"))
            cfg->grid_activation_key = strdup(val);
        else if(!strcmp(key, "screen_activation_key"))
            cfg->screen_activation_key = strdup(val);
        else if(!strcmp(key, "activation_key"))
            cfg->activation_key = strdup(val);
        else if(!strcmp(key, "hint_oneshot_key"))
            cfg->hint_oneshot_key = strdup(val);
        else if(!strcmp(key, "repeat_interval"))
            cfg->repeat_interval = atoi(val);
        else if(!strcmp(key, "speed"))
            cfg->speed = atoi(val);
        else if(!strcmp(key, "max_speed"))
            cfg->max_speed = atoi(val);
        else if(!strcmp(key, "acceleration"))
            cfg->acceleration = atoi(val);
        else if(!strcmp(key, "buttons"))
            parse_list(val, &cfg->buttons, &cfg->buttons_sz);
        else if(!strcmp(key, "oneshot_buttons"))
            parse_list(val, &cfg->oneshot_buttons, &cfg->oneshot_buttons_sz);
        else if(!strcmp(key, "oneshot_timeout"))
            cfg->oneshot_timeout = atoi(val);
        else if(!strcmp(key, "grid_exit"))
            cfg->grid_exit = strdup(val);
        else if(!strcmp(key, "exit"))
            cfg->exit = strdup(val);
        else if(!strcmp(key, "drag"))
            cfg->drag = strdup(val);
        else if(!strcmp(key, "copy_and_exit"))
            cfg->copy_and_exit = strdup(val);
        else if(!strcmp(key, "hint"))
            cfg->hint = strdup(val);
        else if(!strcmp(key, "grid"))
            cfg->grid = strdup(val);
        else if(!strcmp(key, "screen"))
            cfg->screen = strdup(val);
        else if(!strcmp(key, "left"))
            cfg->left = strdup(val);
        else if(!strcmp(key, "down"))
            cfg->down = strdup(val);
        else if(!strcmp(key, "up"))
            cfg->up = strdup(val);
        else if(!strcmp(key, "right"))
            cfg->right = strdup(val);
        else if(!strcmp(key, "cursor_color"))
            cfg->cursor_color = strdup(val);
        else if(!strcmp(key, "cursor_size"))
            cfg->cursor_size = atoi(val);
        else if(!strcmp(key, "top"))
            cfg->top = strdup(val);
        else if(!strcmp(key, "middle"))
            cfg->middle = strdup(val);
        else if(!strcmp(key, "bottom"))
            cfg->bottom = strdup(val);
        else if(!strcmp(key, "start"))
            cfg->start = strdup(val);
        else if(!strcmp(key, "end"))
            cfg->end = strdup(val);
        else if(!strcmp(key, "hist_back"))
            cfg->hist_back = strdup(val);
        else if(!strcmp(key, "hist_forward"))
            cfg->hist_forward = strdup(val);
        else if(!strcmp(key, "grid_nr"))
            cfg->grid_nr = atoi(val);
        else if(!strcmp(key, "grid_nc"))
            cfg->grid_nc = atoi(val);
        else if(!strcmp(key, "grid_up"))
            cfg->grid_up = strdup(val);
        else if(!strcmp(key, "grid_left"))
            cfg->grid_left = strdup(val);
        else if(!strcmp(key, "grid_down"))
            cfg->grid_down = strdup(val);
        else if(!strcmp(key, "grid_right"))
            cfg->grid_right = strdup(val);
        else if(!strcmp(key, "grid_keys"))
            parse_list(val, &cfg->grid_keys, &cfg->grid_keys_sz);
        else if(!strcmp(key, "grid_color"))
            cfg->grid_color = strdup(val);
        else if(!strcmp(key, "grid_size"))
            cfg->grid_size = atoi(val);
        else if(!strcmp(key, "grid_border_size"))
            cfg->grid_border_size = atoi(val);
        else if(!strcmp(key, "grid_border_color"))
            cfg->grid_border_color = strdup(val);
        else if(!strcmp(key, "hint_size"))
            cfg->hint_size = atoi(val);
        else if(!strcmp(key, "hint_bgcolor"))
            cfg->hint_bgcolor = strdup(val);
        else if(!strcmp(key, "hint_fgcolor"))
            cfg->hint_fgcolor = strdup(val);
        else if(!strcmp(key, "hint_border_radius"))
            cfg->hint_border_radius = atoi(val);
        else if(!strcmp(key, "scroll_down"))
            cfg->scroll_down = strdup(val);
        else if(!strcmp(key, "scroll_up"))
            cfg->scroll_up = strdup(val);
        else if(!strcmp(key, "screen_chars"))
            cfg->screen_chars = strdup(val);
        else if(!strcmp(key, "hint_chars"))
            cfg->hint_chars = strdup(val);
        else if(!strcmp(key, "hint_font"))
            cfg->hint_font = strdup(val);

		free(line);
		line = NULL;
		n = 0;
	}

	return cfg;
}
