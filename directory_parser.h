#include <stdint.h>
#include <dirent.h>
#include <linux/limits.h>
#include <pwd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "logger.h"

#define DIRPARSE_MAX_DIR_FILES 10000
#define __USE_MISC 1

typedef unsigned int uint;

uint dirparse_run_finder(char *current_path);
void dirparse_set_entry(uint argc, char *argv[], char *entry_dir);
bool dirparse_has_subdirs(struct dirent *contents[], uint count);
uint dirparse_get_contents(const char *chosen_dir, struct dirent *contents[]);
void dirparse_print_contents(struct dirent *contents[], uint count);
