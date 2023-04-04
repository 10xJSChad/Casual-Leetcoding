extern int sum = 0;
extern int i = 0;

int n_sum(int a, int b, int c, int d, int e, int f){
  i = a-5; sum = 0;
  
  if(a >= 1) sum += b;
  if(a >= 2) sum += c;
  if(a >= 3) sum += d;
  if(a >= 4) sum += e;
  if(a >= 5) sum += f;  
  
  while(i > 0){
    __asm__("movl 16(%rbp), %eax"); 
    __asm__("addq $8, %rbp"); 
    __asm__("addl %eax, sum");
    i--;
  };

  __asm__("mov sum, %eax");
  __asm__("popq %rbp");
  __asm__("retq");
}
