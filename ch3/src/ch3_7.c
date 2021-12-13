#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

/*
S_IRWXU 00700
S_IRUSR 00400
S_IWUSR 00200
S_IXUSR 00100

S_IRWXG 00070
S_IRGRP 00040
S_IWGRP 00020
S_IXGRP 00010

S_IRWXO 00007
S_IROTH 00004
S_IWOTH 00002
S_IXOTH 00001
*/

int main() {
    struct stat statbuf;

    chmod("linux.txt", S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH);

    stat("linux.txt", &statbuf);
    printf("1.Mode = %o\n", (unsigned int)statbuf.st_mode);

    statbuf.st_mode |= S_IWGRP;
    statbuf.st_mode &= ~(S_IROTH);

    chmod("linux.txt", statbuf.st_mode);

    stat("linux.txt", &statbuf);
    printf("2.Mode = %o\n", (unsigned int)statbuf.st_mode);
}
