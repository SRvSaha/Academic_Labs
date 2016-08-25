/*
*   @author      : SRvSaha
*   Filename     : create_child_process.c
*   Timestamp    : 14:33 22-August-2016 (Monday)
*   Description  : Creating child process using fork and analyse them
*   Link         :
*
*/


#include <stdio.h>
#include "lib/tlpi_hdr.h"
int main()
{
    pid_t pid; // Create a process with process ID pid for parent
    pid = fork(); // Creating a child
    switch(pid){
        case -1 :
            printf("Could not create child");
            break;
        case 0 :
            printf("Child  Process ID %ld\n",(long)getpid()); // getpid() method is used for getting pid of child
            break;
        default:
            sleep(3);
            printf("Parent Process ID %ld\n",(long)getppid()); // getppid() method is used for getting pid of
    }
    return 0;
}
