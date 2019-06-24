#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    int status;
    pid_t cpid;

    printf("I'm a parent with pid: %d\n\n", (int)getpid());
    pid = fork();
    if (pid == -1)
    {
        printf("Fork failed\n");
        exit(1);
    }

    if (pid == 0)
    {
        ///child
        printf("I'm a child with pid: %d\n", (int)getpid());
        sleep(15);
        exit(0);
    }
    else if (pid > 0)
    {
        ///parent
        printf("PARENT\n");
        cpid = wait(&status);
        printf("Child finished. CPID: %d\n", (int)cpid);
        if (WIFEXITED(status))
        {
            printf("Normal execution. Exit code: %d\n", WEXITSTATUS(status));
        }
    }

    printf("Fork returned pid: %d\n", (int)pid);
    return 0;
}
