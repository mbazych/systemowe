#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    chmod("test.txt", S_IROTH);

    int fd;
    fd = open("test", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    fchmod(fd, S_IRWXU);
}