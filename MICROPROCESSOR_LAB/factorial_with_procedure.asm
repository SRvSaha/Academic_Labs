; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    num dw 05h
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax

    ; add your code here
    mov cx, num
    mov ax,01h
    call fact
    int 21h
    
    fact proc near
       
        cmp cx,01H
        je RETR
        mul cx
        dec cx
        call fact  
        RETR: ret
    fact endp
                   
                        
      
ends

end start ; set entry point and stop the assembler.
