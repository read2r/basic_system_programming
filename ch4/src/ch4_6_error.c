#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd, n;
    off_t start, cur;
    char buf[256];

    fd = open("linux.txt", O_RDONLY);
    if(fd == -1) {
        perror("Open linux.txt");
        exit(1);
    }

    start = lseek(fd, 0, SEEK_CUR);
    n = read(fd, buf, 255);
    buf[n] = '\0'; 
    printf("Offset start=%d, n=%d, Read Str=%s", (int)start, n, buf);
    cur = lseek(fd, 0, SEEK_CUR);
    printf("Offset cur=%d\n", (int)cur);

    for(int i = 0; i < n; i++) {
        printf("[%2d] %3d: %c\n", i, buf[i], buf[i]);
    }

    close(fd);
}
