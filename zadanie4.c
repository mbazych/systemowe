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
    mkdir("results", "w+");
    FILE *stream;
    DIR *dirent;
    stream = fopen("./results/etc_dir.out", "w+");



    return 0;
}
