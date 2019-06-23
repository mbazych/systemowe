#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd;
    fd = open("zapis", O_RDONLY);

    int tab[24];
    char tmp[12] = {0x0};
    int i;
    for (i = 0; i < 10; i++)
    {
        read(fd, tmp, sizeof(tmp));
        sprintf(tmp, "%11d", tab[i]);
        printf("%d\n", tmp[i] * 3);
    }
    close(fd);
    return 0;
}
