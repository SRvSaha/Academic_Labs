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
    mov bx,cx    
l1:           
    mov dx,1
    add dx,48
    mov ah,2h
    int 21h
  mov cx,3       
l2:
    mov dx,3
    add dx,48
    mov ah,2h
    int 21h      
loop l2
dec bx
mov cx,bx
loop l1
ends

end start ; set entry point and stop the assembler.
  