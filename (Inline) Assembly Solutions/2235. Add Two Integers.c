__attribute__((naked)) int sum(
    int num1, 
    int num2)
{
    __asm__
(
"   .intel_syntax noprefix              ;\
    mov eax, 0                          ;\
    add eax, edi                        ;\
    add eax, esi                        ;\
    ret                                 ;\
    .att_syntax                         ;\
"   
);

}
