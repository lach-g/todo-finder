#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

#define DIR_MAX_FILES 10000
#define __USE_MISC 1

void set_entry_dir(int argc, char *argv[], char *entry_dir);
int run_finder(char *current_path);
int get_dir_contents(const char *chosen_dir, struct dirent *contents[]);
bool has_subdirs(struct dirent *contents[], int count);
void print_dir_contents(struct dirent *contents[], int count);
