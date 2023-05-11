#include "directory_parser.h"
#include <linux/limits.h>
#include <stdlib.h>


void dirparse_set_entry(uint argc, char *argv[], char *entry_dir)
{
  if (argc > 1)
    entry_dir = argv[1];
  else
    if ((entry_dir = getenv("HOME")) == NULL)
      entry_dir = getpwuid(getuid())->pw_dir;
}

uint dirparse_run_finder(char *current_dir)
{
  // Get list of entry dir objects
  struct dirent *dir_contents[DIRPARSE_MAX_DIR_FILES];
  uint num_contents = dirparse_get_contents(current_dir, dir_contents);

  if (dirparse_has_subdirs(dir_contents, num_contents))
    logger_log("TODO (current dir variable) directory is a leaf node.\n", INFO);
  else
      logger_log("TODO (current dir variable) directory has subdirectories.\n", INFO);

  // TODO - Parse each valid file in entry dir for TODOs

  // TODO - Create master list of subdirectories and use as a stack (read
  // learning -> C -> 21st... -> back up to C/glib-notes... )


  /* while (has_subdirs(dir_contents, num_contents)) */
  /* { */
  /*   printf("## INFO: %s directory has subdirectories.\n", current_dir); */

  /*   // TODO Add subdirectories to stack */

  /*   // TODO Call recursive function with directory at top of stack */
  /* } */

  return 0;
}

uint dirparse_get_contents(const char* chosen_dir, struct dirent *contents[])
{
  struct dirent *de;
  uint count = 0;

  DIR *dr = opendir(chosen_dir);

  if (dr == NULL)
  {
    printf("## ERROR: Could not open %s directory, exiting.\n", chosen_dir);
    return 0;
  }

  while ((de = readdir(dr)) != NULL)
  {
    if (count < DIRPARSE_MAX_DIR_FILES)
    {
      contents[count] = de;
    }
    else
      {
        printf("## ERROR: Could not store %s directory contents, max file capacity reached, exiting.\n", chosen_dir);
      }
    count++;
  }

  closedir(dr);
  return count;
}

bool dirparse_has_subdirs(struct dirent *contents[], uint count)
{
  for (uint i = 0; i < count; i++)
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

void dirparse_print_contents(struct dirent *contents[], uint count)
{
  for (uint i = 0; i < count; i++)
  {
    struct dirent *current_content = contents[i];
    printf("%s\n", current_content->d_name);
    printf("%d\n\n", current_content->d_type);
  }
}
