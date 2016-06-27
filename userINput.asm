;
;   @author : Saurav Saha, BT14CS002
;             National Institute of Technology Mizoram
;   Description : Take 4 numbers INPUT from the user and print the largest number among them.
;

section .data                              ;Data segment
   userMsg1 db 'Please enter number 1 : ' ;Ask the user to enter  number 1
   lenUserMsg1 equ $-userMsg1
   userMsg2 db 'Please enter number 2 : ';Ask the user to enter  number 2
   lenUserMsg2 equ $-userMsg2
   userMsg3 db 'Please enter number 3 : ';Ask the user to enter  number 3
   lenUserMsg3 equ $-userMsg3
   userMsg4 db 'Please enter number 4 : ';Ask the user to enter  number 4
   lenUserMsg4 equ $-userMsg4



   dispMsg db 'Largest number is :  '; db is used for defining the byte || Defining CONSTANT or const char *
   lenDispMsg equ $-dispMsg

section .bss           ;Uninitialized data
    num1 resb 5        ; Any number of bytes can be reserved but only BUFFER SIZE is used while
    num2 resb 5
    num3 resb 5
    num4 resb 5
    largest resb 5

section .text          ;Code Segment
   global _start

_start:                ;User prompt for 1st Number INPUT
   mov eax, 4           ;eax = 4 : <System call for sys_write> OUTPUT || eax is the main register
   mov ebx, 1           ;ebx = 1 : Invoking stdout for printing || int
   mov ecx, userMsg1    ;ecx : general purpose register for holding the message || const char *
   mov edx, lenUserMsg1 ;edx : Holds the length of the message || size_t
   int 80h

                        ; READ and STORE 1st Number
   mov eax, 3            ; eax = 3 : <System call for sys_write> INPUT
   mov ebx, 2            ; eax = 2 : Invoking stdout for taking input
   mov ecx, num1         ; Value is given as char* ; value for num1 which is inputted
   mov edx, 5            ; 5 bytes <BUFFER for INPUT> || size_t
   int 80h

                        ;User prompt for 2nd Number INPUT
   mov eax, 4            ;  eax = 4 : <System call for sys_write> OUTPUT || eax is the main register
                         ;  all the other registers are used for taking argument against the system arg in eax
   mov ebx, 1            ;  ebx = 1 : Invoking stdout for printing || int
   mov ecx, userMsg2     ;  ecx : general purpose register for holding the message || const char *
   mov edx, lenUserMsg2  ;  edx : Holds the length of the message || size_t
   int 80h               ;  System Interrups here and the above lines are executed

                        ; READ and STORE 2nd Number
   mov eax, 3
   mov ebx, 2
   mov ecx, num2
   mov edx, 5
   int 80h
                    ;;User prompt for 3rd Number INPUT
   mov eax, 4           ;eax = 4 : <System call for sys_write> OUTPUT || eax is the main register
   mov ebx, 1           ;ebx = 1 : Invoking stdout for printing || int
   mov ecx, userMsg3    ;ecx : general purpose register for holding the message || const char *
   mov edx, lenUserMsg3 ;edx : Holds the length of the message || size_t
   int 80h

                        ; READ and STORE 3rd Number
   mov eax, 3            ; eax = 3 : <System call for sys_write> INPUT
   mov ebx, 2            ; eax = 2 : Invoking stdout for taking input
   mov ecx, num3         ; Value is given as char* ; value for num1 which is inputted
   mov edx, 5            ; 5 bytes <BUFFER for INPUT> || size_t
   int 80h

                        ;User prompt for 4th Number INPUT
   mov eax, 4            ;  eax = 4 : <System call for sys_write> OUTPUT || eax is the main register
                         ;  all the other registers are used for taking argument against the system arg in eax
   mov ebx, 1            ;  ebx = 1 : Invoking stdout for printing || int
   mov ecx, userMsg4     ;  ecx : general purpose register for holding the message || const char *
   mov edx, lenUserMsg4  ;  edx : Holds the length of the message || size_t
   int 80h               ;  System Interrups here and the above lines are executed

                        ; READ and STORE 4th Number
   mov eax, 3
   mov ebx, 2
   mov ecx, num4
   mov edx, 5
   int 80h

                            ;ALGO here
    mov   ecx, [num1]       ;move 1st number to ecx
    cmp   ecx, [num2]       ;compare first and second number || if value in ecx > value of num2 || LHS side TRUE
    jg    check_third_num   ;if first number is greater then it jumps to check_third_num
    mov  ecx, [num2]        ; if condition fails then move the second num to ecx
    cmp   ecx, [num3]       ; compare third and second number
    jg   check_fourth_num   ; jump for checking with the 4th number
    mov   ecx, [num3]       ; for condition FALSE i.e, 3rd num > 4th num, move num3 to ecx
    cmp   ecx, [num4]       ; compare 3rd and 4th num
    jg   _exit              ; if true jum to exit condition
    mov   ecx, [num4]       ; When false, put num4's value in ecx
    jg   _exit

check_third_num:

   cmp   ecx, [num3]
   jg    check_fourth_num
   mov   ecx, [num3]
   cmp   ecx, [num4]
   jg    _exit
   mov   ecx, [num4]
   jg   _exit

check_fourth_num:

    cmp ecx, [num4]
    jg  _exit
    mov ecx, [num4]
    jg   _exit

_exit:
   mov   [largest], ecx ; [] is used for the value of the largest variable
   mov   ecx,dispMsg
   mov   edx, lenDispMsg
   mov   ebx,1  ;file descriptor (stdout)
   mov   eax,4  ;system call number (sys_write)
   int   0x80   ;call kernel

   mov   ecx,largest
   mov   edx, 5
   mov   ebx,1  ;file descriptor (stdout)
   mov   eax,4  ;system call number (sys_write)
   int   0x80   ;call kernel


   ; Exit code
   mov eax, 1       ; invoking the sys_exit
   mov ebx, 0       ; like return 0 in C
   int 80h          ; interrupt for linux system
