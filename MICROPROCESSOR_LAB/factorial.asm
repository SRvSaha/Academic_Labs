; multi-segment executable file template.
.model small
data segment
    ; add your data here!
    var dw 4
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    
    mov cx, var
    mov ax, var
    
    dec cx
HERE:    dec var
        mul var
        dec cx
        jnz HERE                
    call print_ax
    int 21h   
ends

end start ; set entry point and stop the assembler.
