#include <stdio.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *stream;
    FILE *endstream;
    if (!argv[1])
    {
        stream = fopen(argv[1], "r");
        endstream = fopen(strcat(argv[1], ".red"), "w+");
    }
    else
    {
        stream = fopen("test", "r");
        endstream = fopen("test.red", "w+");
    }

    int c, i = 0;
    while (c != EOF)
    {
        c = fgetc(stream);
        i++;
        if (i % 3 == 0)
        {
            fputc(c, endstream);
        }
    }
    fclose(stream);
    fclose(endstream);

    return 0;
}