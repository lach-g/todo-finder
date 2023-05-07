#include "todo_finder.h"
#include <stdlib.h>

/**

================================================================================
============================ Expected behaviour ================================
================================================================================

Input:
- Nothing
Output:
- Recursively read all files in /home/<current_user> dir for TODO phrase
- For each match record file name, line number, and TODO line in
/home/<current_user>/TODOs/todos.<md | org>

Input:
- '/some/file/path' [-md | -org]
Output:
- Recursively read all files in ./<current_dir> for TODO phrase
- For each match record file name, line number, and TODO line in
./<current_dir>/.todos.<md | org>
Notes:
- File paths check for relative or absolute
- Use two different todo_writers with common interface, default is md

 */
int main(int argc, char *argv[])
{
  char* entry_dir;
  set_entry_dir(argc, argv, entry_dir);

  int complete = run_finder(entry_dir);
  if (complete)
    printf("## INFO: Indexing for %s directory complete.\n", entry_dir);
  else
    printf("## ERROR: Failed indexing for %s directory.\n", entry_dir);

}

void set_entry_dir(int argc, char *argv[], char *entry_dir)
{
  if (argc > 1)
    entry_dir = argv[1];
  else
    if ((entry_dir = getenv("HOME")) == NULL)
      entry_dir = getpwuid(getuid())->pw_dir;
}

int run_finder(char *current_dir)
{
  // Get list of entry dir objects
  struct dirent *dir_contents[DIR_MAX_FILES];
  int num_contents = get_dir_contents(current_dir, dir_contents);

  // TODO - Parse each valid file in entry dir for TODOs

  // TODO - Create master list of subdirectories and use as a stack (read
  // learning -> C -> 21st... -> back up to C/glib-notes... )

  while (has_subdirs(dir_contents, num_contents)) {
    printf("## Info: %s directory has subdirectories.\n", current_dir);

    // TODO Add subdirectories to stack

    // TODO Call recursive function with directory at top of stack
  }
  printf("## Info: %s directory is a leaf node.\n", current_dir);

  return 0;
}

int get_dir_contents(const char* chosen_dir, struct dirent *contents[])
{
  struct dirent *de;
  int count = 0;

  DIR *dr = opendir(chosen_dir);

  if (dr == NULL)
  {
    printf("## Error: Could not open %s directory, exiting.\n", chosen_dir);
    return 0;
  }

  while ((de = readdir(dr)) != NULL)
  {
    if (count < DIR_MAX_FILES)
    {
      contents[count] = de;
    }
    else
      {
        printf("## Error: Could not store %s directory contents, max file capacity reached, exiting.\n", chosen_dir);
      }
    count++;
  }

  closedir(dr);
  return count;
}

bool has_subdirs(struct dirent *contents[], int count)
{
  for (int i = 0; i < count; i++)
  {
    struct dirent *current_content = contents[i];

    if (strcmp(current_content->d_name, "..") == 0 ||
        strcmp(current_content->d_name, ".") == 0)
      continue;

    // TODO - reference the enum and not the actual number from dirent.h
    if (current_content->d_type == 4) {
      return true;
    }
  }
  return false;
}

void print_dir_contents(struct dirent *contents[], int count)
{
  for (int i = 0; i < count; i++)
  {
    struct dirent *current_content = contents[i];
    printf("%s\n", current_content->d_name);
    printf("%d\n\n", current_content->d_type);
  }
}
