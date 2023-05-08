__attribute__((naked)) int sum (
    int num1, 
    int num2)
{
    __asm__
(
    .intel_syntax noprefix     ;  switch to intel syntax
    add esi, edi               ;  add num1 to the return value
    mov eax, esi               ;  add num2 to the return value
    ret                        ;  return
    .att_syntax                ;  switch back to at&t syntax
);

}
