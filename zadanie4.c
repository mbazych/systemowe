#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
int isDir(struct dirent* target)
{
    struct stat statbuf;
    stat(target, &statbuf);
    return S_ISDIR(statbuf.st_mode);
}
int main(int argc, char const *argv[])
{
    mkdir("results", 777);
    DIR* dirp;
    FILE *stream;
    struct dirent* direntp;
    stream = fopen("results/etc_dir.out", "w+");
    dirp = opendir("/etc");
    for(;;)
    {
        direntp = readdir(dirp);
        if(direntp == NULL) break;
        printf("%d", isDir(direntp));
        if(isDir(direntp) == 0)
            printf("%s\n", direntp->d_name);

    }
    return 0;
}
