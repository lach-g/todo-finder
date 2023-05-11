#include "logger.h"
#include <string.h>


void logger_info(char *message);
void logger_debug(char *message);
void logger_warning(char *message);
void logger_error(char *message);


void logger_log(char *message, enum logger_category category)
{
  switch (category)
  {
    case INFO:
      logger_info(message);
      break;
    case DEBUG:
      logger_debug(message);
      break;
    case WARNING:
      logger_warning(message);
      break;
    case ERROR:
      logger_error(message);
      break;
     default:
       break;
  }
}

void logger_info(char *message)
{
  char final_message[LOGGER_MAX_MESSAGE_LEN];
  char info_prefix[] = "## INFO: ";
  uint total_size = strlen(message) + strlen(info_prefix);
  if (total_size < LOGGER_MAX_MESSAGE_LEN)
  {
    strcat(final_message, info_prefix);
    strcat(final_message, message);
    printf("%s", final_message);
  }
}

void logger_debug(char *message)
{
  char debug_prefix[] = "## DEBUG: ";
}

void logger_warning(char *message)
{
  char warning_prefix[] = "## WARNING: ";
}

void logger_error(char *message)
{
  char error_prefix[] = "## ERROR: ";
}
