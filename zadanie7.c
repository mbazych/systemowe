#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

static void sig_usr(int);
int main(void)
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
        printf("Cannot catch signal SIGUSR1\n");
        return 1;
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
    {
        printf("Cannot catch signal SIGUSR2\n");
        return 1;
    }
    while (1)
    {
        pause();
    }
}
static void sig_usr(int signo)
{
    FILE *pidfile;
    pid_t pid;
    int q;
    pid = getpid();
    pidfile = fopen("pid.txt", "w");
    if (signo == SIGUSR1)
    {
        printf("Signal SIGUSR1 received\n");
        printf("%d\n", (int)pid);
        q = fprintf(pidfile, "the PID is %d", (int)pid);
        printf("%d\n", q);
    }
    else if (signo == SIGUSR2)
    {
        printf("Signal SIGUSR2 received\n");
    }
    else
    {
        printf("Other signal -%d", signo);
    }
    fclose(pidfile);
}