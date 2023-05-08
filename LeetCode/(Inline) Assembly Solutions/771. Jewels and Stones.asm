; Nested loops, would have preferred to do it any other way
; but I'm not about to implement a hashmap/dictionary in assembly

__attribute__((naked)) int numJewelsInStones(
    char * jewels,       ; rdi
    char * stones)       ; rsi
{

    __asm__
(
   .intel_syntax noprefix               ;
    xor rax, rax                        ;  clear rax for use as the jewels in stones count
    mov r8, rsi                         ;  store the start of the stones array
                                        ;
    stone_loop_start:                   ;
    mov rsi, r8                         ;  make rsi point to the start of the stones array
                                        ;
    stone_loop:                         ;
    mov dl, BYTE PTR [rsi]              ;  store the char in stones[j]
    add rsi, 1                          ;  increment j
                                        ;
    cmp BYTE PTR [rdi], dl              ;  compare stones[i] to jewels[j]
    jne not_equal                       ;  jump ahead if not equal, skipping the next instruction

    add rax, 1                          ;  increment the jewels in stones count
                                        ; 
    not_equal:                          ;
    cmp dl, 0                           ;  compare stones[j] to 0 / NULL / '\0'
    jne stone_loop                      ;  loop again if they're not equal
    jmp jewel_loop                      ;  or continue on and reach the jump back to the jewel loop

                                        ;  this next part won't have as many comments
                                        ;  try to figure out what it does from the context of
                                        ;  the commented code above, its got everything you need

    jewel_loop:                         ;
    add rdi, 1                          ;
    cmp BYTE PTR [rdi], 0               ;
    jne stone_loop_start                ;

    ret                                 ;  returns rax (default behaviour, I did not make it do this anywhere)
    .att_syntax                         ;
);

}
