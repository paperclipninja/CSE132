; dm.S
;
; data manipulation
;
    .extern printRegs
    .extern m
    .extern n
    .extern p

    .global dm
dm:
    push r16    ;save registers so C doesn't get confused
    push r17
    push r28
    push r29

    ;insert your assembly language code below
    ;(you can invoke printRegs() with the asm instruction 'call printRegs')

    ldi r25,hi8(100) ;loads value 100 into r24
    ldi r24, lo8(100) 

    sts (m), r25  ;store r24 into mem loc m
    sts (m+1), r24

    ldi r19, 0
    ldi r18, 0

    add r18, r24
    adc r19, r25
    add r18, r24
    adc r19, r25    
    add r18, r24
    adc r19, r25

    sts (n), r25
    sts (n+1),r24

    ldi r11, hi8(50)
    ldi r10, lo8(50) //loads 50
    lds r19, (n)
    lds r18, (n+1)
    sub r18, r10
    sbc r19, r11
    sts (p), r19
    sts (p), r18

    ldi r26, m-50
    sts(p), (r26)
    printRegs

    pop r29     ;restore registers saved earlier
    pop r28
    pop r17
    pop r16
    ret         ;return
