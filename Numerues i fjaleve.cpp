#include <stdio.h>
#define GJATESIA_MAX 1000

int numroFjalet(char fjalia[]) {
    int numriFjalve = 0;
    int neFjale = 0;

    for (int i = 0; fjalia[i] != '\0'; i++) {
        if (fjalia[i] == ' ' || fjalia[i] == '\t' || fjalia[i] == '\n') {
            neFjale = 0;
        } else if (neFjale == 0) {
            neFjale = 1;
            numriFjalve++;
        }
    }
    return numriFjalve;
}

void lexFjaline(char fjalia[], int gjatesiaMax) {
    printf("Shkruani nje fjali: ");
    int i = 0;
    char karakter;
    while (i < gjatesiaMax - 1) {
        karakter = getchar();
        if (karakter == '\n') {
            break;
        }
        fjalia[i] = karakter;
        i++;
    }
    fjalia[i] = '\0';
}

int main() {
    char fjalia[GJATESIA_MAX];
    lexFjaline(fjalia, GJATESIA_MAX);
    int numriFjalve = numroFjalet(fjalia);
    printf("Numri i fjaleve ne fjaline tuaj eshte: %d\n", numriFjalve);
    return 0;
}
