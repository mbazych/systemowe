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

    pid = fork();
    if (pid == -1)
    {
        printf("Fork Failed");
        exit(1);
    }

    if (pid == 0)
    {
        FILE *stream;

        stream = fopen("liczby.txt", "a+");
        int i = 0, j = 0;
        for (i = 9; i <= 99; i++)
        {

            if (i % 3 == 0)
            {
                j++;
                fprintf(stream, "%d liczba: %d\n", j, i);
            }
        }
        fclose(stream);
        exit(0);
    }
    else if (pid > 0)
    {
        cpid = wait(&status);
        printf("Child finished. CPID: %d\n", (int)cpid);
        if (WIFEXITED(status))
        {
            printf("normal execution. exit code: %d\n", WEXITSTATUS(status));
        }
    }

    printf("Fork returned pid: %d\n", (int)pid);

    return 0;
}
