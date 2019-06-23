#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    int fd2;
    if (!argv[1])
    {
        fd = open(argv[1], O_RDWR | O_CREAT);
        fd2 = open(strcat(argv[1], ".red"), O_RDWR | O_CREAT);
    }
    else
    {
        fd = open("test", O_RDWR | O_CREAT);
        fd2 = open("test.red", O_RDWR | O_CREAT);
    }

    int i = 0;
    char c[10];

    while (read(fd, c, 1) != 0)
    {
        i++;
        if (i % 3 == 0)
        {
            write(fd2, c, 1);
        }
    }
    close(fd);
    close(fd2);

    return 0;
}