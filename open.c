#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char buf1[128];
    int fd;
    // Otwieramy plik test, jesli nie istnieje to sie tworzy,
    // otwieramy z mozliwoscia zapisu i odczytu
    fd = open("test", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    // czytamy 128 bajtów z pliku
    int wynik = read(fd, buf1, 128);

    printf("Odczytano %d bajtów.\n", wynik);
    int i;
    for (i = 0; i < strlen(buf1); i++)
    {
        printf("%c", buf1[i]);
    }
    // przesuwamy offset pliku o 10000 bajtów od początku pliku
    lseek(fd, 10000, SEEK_SET);

    int nwrite = write(fd, argv[1], strlen(argv[1]));

    printf("\nZapisano do pliku %d bajtów.", nwrite);

    close(fd);

    return 0;
}