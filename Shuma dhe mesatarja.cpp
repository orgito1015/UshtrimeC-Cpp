#include <stdio.h>

int llogaritShumen(int vektor[], int n) {
    int shuma = 0;
    for (int i = 0; i < n; i++) {
        shuma += vektor[i];
    }
    return shuma;
}

float llogaritMesataren(int shuma, int n) {
    return (float)shuma / n;
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

    int shuma = llogaritShumen(vektor, n);
    printf("Shuma: %d\n", shuma);
    printf("Mesatarja: %.2f\n", llogaritMesataren(shuma, n));

    return 0;
}

