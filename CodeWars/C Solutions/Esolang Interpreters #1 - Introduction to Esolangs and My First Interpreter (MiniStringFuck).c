char*
my_first_interpreter (
  const char *code)
{
  int i = 0, j = 0, cell = 0;
  char* output = (char*) malloc(20 * sizeof(char));
  
  while (code[i]) {
    switch (code[i]) {
        case '+': ++cell; break;
        case '.': output[j] = (char) cell; ++j;
    }

    i++;
    output[j] = '\0';
  }
  
  return output;
}
