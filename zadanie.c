#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int signo)
{
    if (signo == SIGINT)
    {
        printf("\n");
    }
    if (signo == SIGTERM)
    {
        printf("\nReceived SIGTERM\n");
        exit(1);
    }
}

int main(int argc, char *argv[])
{

    FILE *stream;
    int suma = 0;
    stream = fopen(argv[1], "w+");
    int i;
    for (i = 10; i > 0; i--)
    {
        sleep(3);
        suma += 3;
        // zamienic x i y na wartosci
        if (fprintf(stream, "Wywolanie nr %d. Program spal juz przez %d sekund\n", i, suma) == EOF)
        {
            printf("Blad!");
            return 1;
        }
    }
    fclose(stream);
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\nCan't catch SIGINT\n");
    else
    {
        pause();
        rewind(stream);
        stream = fopen(argv[1], "w+");
        if (fputs("Received SIGINT", stream) == EOF)
            printf("Blad!");
        fclose(stream);
    }

    return 0;
}
