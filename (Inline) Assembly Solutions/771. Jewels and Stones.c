// Nested loops, would have preferred to do it any other way
// but I'm not about to implement a hashmap/dictionary in assembly

__attribute__((naked)) int numJewelsInStones(
    char * jewels,      // rdi
    char * stones)      // rsi
{

    __asm__
(
"   .intel_syntax noprefix              ;\
                                        ;\
    /*prepare stack, move args*/        ;\
    push rbx                            ;\
    sub rsp, 0x40                       ;\
    mov QWORD PTR [rsp+8],  rdi         ;\
    mov QWORD PTR [rsp+16], rsi         ;\
    mov QWORD PTR [rsp+24], 0           ;\
    mov BYTE PTR  [rsp+31], 0           ;\
    jmp jewel_loop_start;               ;\
                                        ;\
    stone_loop_start:                   ;\
    mov rsi, QWORD PTR [rsp+16]         ;\
                                        ;\
    stone_loop:                         ;\
    mov dl, BYTE PTR [rsp+31]           ;\
    mov bl, BYTE PTR [rsi]              ;\
                                        ;\
    add rsi, 1                          ;\
                                        ;\
    cmp dl, bl                          ;\
    jne not_equal                       ;\
    add QWORD PTR [rsp+24], 1           ;\
                                        ;\
    not_equal:                          ;\
    test bl, bl                         ;\
    jne stone_loop                      ;\
    jmp return_from_stone_loop          ;\
                                        ;\
    jewel_loop_start:                   ;\
    mov r8, rax                         ;\
    mov rax, QWORD PTR [rsp+8]          ;\
                                        ;\
    jewel_loop:                         ;\
    mov dl, BYTE PTR [rax]              ;\
    mov BYTE PTR [rsp+31], dl           ;\
                                        ;\
    add rax, 1                          ;\
                                        ;\
    test dl, dl                         ;\
    jne stone_loop_start                ;\
    return_from_stone_loop:             ;\
                                        ;\
    test dl, dl                         ;\
    jne jewel_loop                      ;\
                                        ;\
    mov eax, DWORD PTR [rsp+24]         ;\
                                        ;\
    add rsp, 0x40                       ;\
    pop rbx                             ;\
    ret                                 ;\
    .att_syntax                         ;\
"   
);

}
