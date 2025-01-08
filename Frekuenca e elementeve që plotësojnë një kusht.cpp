#include <stdio.h>

int gjejFrekuencenKushti(int vektor[], int n) {
    int frekuenca = 0;
    for (int i = 0; i < n; i++) {
        if (vektor[i] % 2 == 0 && vektor[i] >= 100 && vektor[i] <= 200) {
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

    printf("Frekuenca e elementeve çift në segmentin [100-200]: %d\n", gjejFrekuencenKushti(vektor, n));

    return 0;
}

