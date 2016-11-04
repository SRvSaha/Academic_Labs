; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
        
    mov cx,5 
    mov bl,5
    l1:
    mov dl,bl
    add dl,48
    mov ah,2h
    dec bl
    int 21h
    
    loop l1
      
ends

end start ; set entry point and stop the assembler.
