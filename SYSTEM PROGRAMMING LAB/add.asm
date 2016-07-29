section .data
    prompt1 db 'Enter Number 1: '
    len1 equ $-prompt1
    prompt2 db 'Enter Number 2: '
    len2 equ $-prompt2
    result db 'Result is : '
    len equ $-result
section .bss
    num1 resb 10
    num2 resb 10
    sum resb 10
section .text
    global _start
_start:
    mov eax,4
    mov ebx,1
    mov ecx,prompt1
    mov edx,len1
    int 0x80
    
    mov eax,3
    mov ebx,2
    mov ecx,num1
    mov edx,10
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov ecx,prompt2
    mov edx,len2
    int 0x80
    
    mov eax,3
    mov ebx,2
    mov ecx,num2
    mov edx,10
    int 0x80

    mov ecx,[num1] ; Addition of numbers not strings. All input are taken as Strings
    sub ecx,'0'
    mov edx,[num2]
    sub edx,'0'
    add ecx,edx
    add ecx,'0'
    
    mov [sum],ecx
    
    mov eax,4
    mov ebx,1
    mov ecx,result
    mov edx,len
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov ecx,sum
    mov edx,10
    int 0x80
    
    mov eax,1
    mov ebx,0
    int 0x80
    