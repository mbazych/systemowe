// Program tworzy nowy katalog o nazwie results.
// W folderze utwórz dwa pliki:
// pierwszy o nazwie etc_dir.out,
// który będzie zawierał wszystkie nazwy
// katalogów(i tylko katalogów, bez innych rodzajów plików)
//  z katalogu / etc.w drugim pliku o nazwie sysconfig.out
// powinny znajdować się wszystkie nazwy plików regularnych,
//  które nie mają nadanych żadnych uprawnień dla innych
// (przykład: -rwxr - x-- -)

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
    mkdir("results", 777);
    FILE *stream;
    FILE *stream2;
    DIR *d;
    struct dirent *dir;
    stream = fopen("./results/etc_dir.out", "w+");
    stream2 = fopen("./results/sysconfig.out", "w+");
    d = opendir("/etc");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            struct stat buf;
            if (dir->d_type == DT_DIR)
            {
                fprintf(stream, "%s\n", dir->d_name);
            }
            if ((dir->d_type == DT_REG) && (buf.st_mode & S_IROTH))
            {
                printf("%s\n", dir->d_name);
            }
        }
    }
    closedir(d);
    fclose(stream);
    fclose(stream2);

    return 0;
}
