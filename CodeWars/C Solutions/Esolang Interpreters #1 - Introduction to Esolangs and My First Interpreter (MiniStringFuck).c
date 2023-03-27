#include <stdlib.h>

char *my_first_interpreter (const char *code){
  int cell = 0;
  int i = 0;
  int j = 0;
  char *output = (char *)malloc(20 * sizeof(char));;
  
  while(code[i]){
    switch(code[i]){
        case '+': cell++; break;
        case '.': output[j] = (char)cell; j++;
    }
    i++;
    output[j] = '\0';
  }
  return(output);
}
