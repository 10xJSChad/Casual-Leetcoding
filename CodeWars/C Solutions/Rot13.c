#include <stddef.h>

char *rot13(const char *src){
  int i = 0;
  int new_char;
  char *result = malloc (sizeof (int));
  while(src[i]){
    new_char = (int)src[i] + 13;
    if(new_char > 122 || (new_char > 90 && (int)src[i] < 91))
      new_char -= 26;
    
    if(((int)src[i] > 64 && (int)src[i] < 91) || ((int)src[i] > 96 && (int)src[i] < 123))
      result[i] = new_char;
    else
      result[i] = src[i];
    i++;
  }
  result[i] = '\0';
  return(result);
}
