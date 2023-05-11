#include <stdio.h>
#include <string.h>

#define LOGGER_MAX_MESSAGE_LEN 100

typedef unsigned int uint;

enum logger_category
{
  INFO,
  DEBUG,
  WARNING,
  ERROR,
  COUNT
};

void logger_log(char *message, enum logger_category category);
