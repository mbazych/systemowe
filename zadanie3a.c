#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd, i;
    int tab[24];
    char tmp[12] = {0x0};
    fd = open("zapis", O_CREAT | O_WRONLY);
    for (i = 0; i < 10; i++)
    {
        tab[i] = rand();
        printf("%d\n", tab[i]);
        sprintf(tmp, "%11d", tab[i]);
        write(fd, tmp, sizeof(tmp));
    }
    close(fd);

    return 0;
}
