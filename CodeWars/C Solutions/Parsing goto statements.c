#include <stddef.h>
#include <stdbool.h>


static bool ch_isdigit(const char ch) {
  return (ch >= '0' && ch <= '9');
}


static char *get_goto_label(const char *source, char *buf) {
  char *p = buf;
  
  while (!ch_isdigit(*source))
    ++source;
  
  while (ch_isdigit(*source))
    *p++ = *source++;

  *p++ = ' ';
  return buf;
}


char *parse(const char *source) {
  char *expected = calloc(strlen(source), 1);
  char *p = expected;
  
  while (*source) {
    if (ch_isdigit(*source)) {
      while (ch_isdigit(*source))
        ++source;
      
      ++source;

      while (*source != '\n')
        *p++ = *source++;
    
      if (*(source + 1))
        *p++ = ' ';

    } else {
      char target[64] = {0};
      source = strstr(source, get_goto_label(source, target));
      continue;
    }

    ++source;
  }

  return expected;
}
