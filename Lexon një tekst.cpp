#include <stdio.h>

int main() {
    char fjalia[100];
    FILE *fp = fopen("teksti.txt", "r");

    if (fp == NULL) {
        printf("Skedari nuk ekziston!\n");
        return 1;
    }

    while (fgets(fjalia, sizeof(fjalia), fp)) {
        printf("%s", fjalia);
    }

    fclose(fp);
    return 0;
}

