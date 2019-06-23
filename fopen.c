#include <stdio.h>
#define LINE_MAX 50
int main(int argc, char *argv[])
{

    char buf[100];
    FILE *stream;
    stream = fopen("test.txt", "r");
    if (!stream)
    {
        printf("Błąd 1!");
        return 2;
    }
    else
    {
        fputs("The ship is made of wood.\n", stream);
        while (fgets(buf, 100, stream))
        {
            printf("%s\n", buf);
        }
    }
    return 0;
}
