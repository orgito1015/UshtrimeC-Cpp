#include <stdio.h>

int gjejMin(int vektor[], int n) {
    int min = vektor[0];
    for (int i = 1; i < n; i++) {
        if (vektor[i] < min) {
            min = vektor[i];
        }
    }
    return min;
}

int gjejMax(int vektor[], int n) {
    int max = vektor[0];
    for (int i = 1; i < n; i++) {
        if (vektor[i] > max) {
            max = vektor[i];
        }
    }
    return max;
}

int main() {
    int n;
    printf("Shkruani madhësinë e vektorit: ");
    scanf("%d", &n);

    int vektor[n];
    printf("Futni elementet e vektorit:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vektor[i]);
    }

    printf("Min: %d\n", gjejMin(vektor, n));
    printf("Max: %d\n", gjejMax(vektor, n));

    return 0;
}

