/*
 * module.c
 *
 *  Created on: Apr 24, 2019
 *      Author: cssouza
 */

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "server.h"

char *module_dir;

struct server_module *module_open(const char *module_name)
{
	char *module_path;
	void *handle;
	void (*module_generate)(int);
	struct server_module *module;

	module_path = (char *) xmalloc(strlen(module_dir) + strlen(module_name) + 2);

	sprintf(module_path, "%s/%s", module_dir, module_name);

	/* Attempt to open MODULE_PATH as a shared library. */
	handle = dlopen(module_path, RTLD_NOW);
}
