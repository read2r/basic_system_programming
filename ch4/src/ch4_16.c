#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *rfp, *wfp;
    int id, s1, s2, s3, s4, n;

    if((rfp = fopen("linux.dat", "r")) == NULL) {
        perror("open: linux.dat");
        exit(1);
    }

    if((wfp = fopen("linux.scr", "w")) == NULL) {
        perror("open: linux.scr");
        exit(1);
    }

    fprintf(wfp, "%-7s : %s\n", "SID", "AVG");
    while((n = fscanf(rfp, "%d %d %d %d %d", &id, &s1, &s2, &s3, &s4)) != EOF) {
        fprintf(wfp, "%d : %d\n", id, (s1+s2+s3+s4)/4);
    }

    fclose(rfp);
    fclose(wfp);
}
