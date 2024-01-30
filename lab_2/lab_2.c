#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t process_id = fork();

    char *child_cmd_args[] = {"ls", NULL};
    char *parent_cmd_args[] = {"cal", NULL};


    if (process_id == 0)
    {
        printf("I am a child process with id of: %d\n", getpid());
        printf("I will excecute: %s\n", child_cmd_args[0]);
        printf("Results: \n");
        execvp("ls", child_cmd_args);
    }
    else
    {
        waitpid(process_id, NULL, 0);
        printf("I am a parent process with id of: %d\n", getpid());
        printf("I will execute: %s\n", parent_cmd_args[0]);
        printf("Results: \n");
        execvp("cal", parent_cmd_args);
    }

    return 0;
}