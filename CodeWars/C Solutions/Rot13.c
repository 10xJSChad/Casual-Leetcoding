char*
rot13(
  const char *src)
{
  int i = 0;
  short substitution_char;
  char* result = (char*) malloc(sizeof(char));
  
  while (src[i]) {
    substitution_char = src[i] + 13;
    
    if (substitution_char > 122 || (substitution_char > 90 && src[i] < 91))
      substitution_char -= 26;
    
    if ((src[i] > 64 && src[i] < 91) || (src[i] > 96 && src[i] < 123))
      result[i] = substitution_char;
    else
      result[i] = src[i];
    
    i++;
  }
  
  result[i] = '\0';
  return(result);
}
