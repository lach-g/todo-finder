#include "directory_parser.h"

int main(int argc, char *argv[])
{
  uint arg_count = argc;
  char entry_dir[PATH_MAX];
  dirparse_set_entry(arg_count, argv, entry_dir);

  int complete = dirparse_run_finder(entry_dir);
  if (complete == 0)
  {
    printf("## INFO: Indexing for %s directory complete.\n", entry_dir);
    return 0;
  }
  else
  {
    printf("## ERROR: Failed indexing for %s directory.\n", entry_dir);
  }
  return 1;
}
