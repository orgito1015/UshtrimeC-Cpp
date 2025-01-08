#include <stdio.h>

int gjejFrekuencen(int vektor[], int n, int element) {
    int frekuenca = 0;
    for (int i = 0; i < n; i++) {
        if (vektor[i] == element) {
            frekuenca++;
        }
    }
    return frekuenca;
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

    int element;
    printf("Shkruani elementin për të gjetur frekuencën: ");
    scanf("%d", &element);

    printf("Frekuenca e %d: %d\n", element, gjejFrekuencen(vektor, n, element));

    return 0;
}

