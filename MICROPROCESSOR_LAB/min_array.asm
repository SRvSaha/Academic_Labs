; multi-segment executable file template.

data segment
    ; add your data here!
    arr db 4,2,3,6,1
    size db 5
    min db ?
ends


code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax

    ; add your code here
    
    mov di, 0 ; this is the pointer to the array
    mov al, arr[di] ; first value of array
    mov cl, size ; the size of the array
    mov di, 1
LABEL: cmp al, arr[di]
       jbe PASS ; jump if below or equal
       mov al, arr[di] ; update the min value to accumulator
PASS: inc di
      dec cl
      cmp cl, 0 ; if cx is zero, we have traversed the whole array
      jnz LABEL
      MOV min, al ; Final min value is moved from acc to min    
ends

end start ; set entry point and stop the assembler.
