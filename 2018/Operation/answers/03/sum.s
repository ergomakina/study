/*
        sum(m, n) = m + (m+1) +  ... + n
 */
        
        .text
        .globl  sum
sum:
        push    %rbp
        mov     %rsp, %rbp
        sub     $0, %rsp        /* can be omitted */

        mov     $0, %eax
        
.loop:
        cmp     %esi, %edi
        jg     .end            /* jump if greater */

        add     %edi, %eax
        add     $1, %edi
        jmp     .loop
.end:
        leave
        ret


        
