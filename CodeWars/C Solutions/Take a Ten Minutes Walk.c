#include <stdbool.h>

bool isValidWalk(const char *walk) {
  int x=0, y=0, i=0;
  
  while(walk[i]){
    switch(walk[i]){
      case('n'): y++; break;
      case('s'): y--; break;
      case('e'): x++; break;
      case('w'): x--; break;
    }
    i++;
  }
  return(x==0 && y==0 && i==10);
}