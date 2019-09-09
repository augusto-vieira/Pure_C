#include <log.h>
#include <syslog.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void log(const char *module, const char *log_message)
{
  openlog(module, LOG_PID | LOG_CONS, LOG_USER);
  syslog(LOG_INFO, log_message);
  closelog();
  return;
}

void logarg(const char *module, const char *log_message, ...)
{
  char buffer[1024] = {0};
  va_list args;
  va_start(args, log_message);
  vsprintf(buffer, log_message, args);
  va_end(args);

  log(module, buffer);
}

