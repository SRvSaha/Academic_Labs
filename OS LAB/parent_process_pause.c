/*
*   @author      : SRvSaha
*   Filename     : parent_process_pause.c
*   Timestamp    : 15:21 22-August-2016 (Monday)
*   Description  : To observer how child and parent processes work in different address space and the effect of changes of global data inside child and parent
*
*/
#include "lib/tlpi_hdr.h"
#include <stdio.h>
static int global_ = 100; // data segment
int main()
{
    int local_ = 50; // stack segment
    pid_t pid;
    pid = fork();
    printf("PID %d",pid);
    switch(pid){
        case -1:
            printf("Error. Could not create child\n");
            break;
        case 0:
            // Changing the value of global var and local var in child still the change in the global variable
            // will not be displayed in parent's global var as both are working on different address space
            global_++;
            local_++;
            printf("I am Child\n");
            break;
        default :
            printf("I am Parent\n");
            printf("Going to Sleep\n");
            sleep(3);
            printf("Back from Child\n");
    }
    printf("PID= %ld %s data_segment= %d stack_segment= %d\n",(long)getpid(),(pid == 0)?"(child)":"(parent)",global_,local_);
    exit(EXIT_SUCCESS); // Handler for the child to Parent by OS
    return 0;
}
