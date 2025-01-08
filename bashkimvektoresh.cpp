#include <stdio.h>
int main() {
    int a[7] = {3, 1, 4, 2, 7, 6, 4};
    int b[3] = {8, 9, 10};
    int c[10];
    int i, j, k = 0;
    for (i = 0; i < 7; i++) {
        c[k++] = a[i];
    }
    for (j = 0; j < 3; j++) {
        c[k++] = b[j];
    }
    printf("Vektori i bashkuar: ");
    for (k = 0; k < 10; k++) {
        printf("%2d ", c[k]);
    }
    printf("\n");
    return 0;
}

