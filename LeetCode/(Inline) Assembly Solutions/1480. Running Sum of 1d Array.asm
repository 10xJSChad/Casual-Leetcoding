__attribute__((naked)) int* runningSum (
    int* nums,       rdi
    int numsSize,    rsi
    int* returnSize) rdx
{
    __asm__
(  
    .intel_syntax noprefix    ;  switch to intel syntax
     mov rax, rdi             ;  set the start of the array as the return value
     xor ecx, ecx             ;  int sum = 0;
                              ;     alternatively: sum = 0 if sum == sum.

     loop_start:              ;  declares a label we can jump to later
     add ecx, DWORD PTR [rdi] ;  sum += nums[i]
     mov DWORD PTR [rdi], ecx ;  nums[i] = sum;

     add rdi, 4               ;  i++
     lea r8, [rax + 4 * rsi]  ;  r8 = (the address of the element in) start + numsSize.
     cmp rdi, r8              ;  compare the addresses
     jl loop_start            ;  jump to start of loop if the current element's 
                              ;     address is less than the one of the last element
                                  
     mov DWORD PTR [rdx], esi ;  returnSize = numsSize
     ret                      ;  return
     .att_syntax              ;  switch back to at&t syntax
);
}
