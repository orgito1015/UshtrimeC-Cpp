#include <stdio.h>

int main() {
    int N;
    printf("Jep madhesine e tabeles (N): ");
    scanf("%d", &N);

    int T[N][N];
    int shumaDiagonaleKryesore = 0;
    int shumaDiagonaleDytesore = 0;
    printf("Jep elementet e tabeles:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("T[%d][%d]: ", i, j);
            scanf("%d", &T[i][j]);
        }
    }

    // Llogarit shum�n e diagonaleve
    for (int i = 0; i < N; i++) {
        shumaDiagonaleKryesore += T[i][i];        // Elementet e diagonales kryesore
        shumaDiagonaleDytesore += T[i][N - 1 - i]; // Elementet e diagonales dyt�sore
    }

    // Afisho shum�n e diagonaleve
    printf("Shuma e diagonales kryesore: %d\n", shumaDiagonaleKryesore);
    printf("Shuma e diagonales dytesore: %d\n", shumaDiagonaleDytesore);

    // Krahaso shum�n e diagonaleve
    if (shumaDiagonaleKryesore > shumaDiagonaleDytesore) {
        printf("Diagonalja kryesore ka shum�n m� t� madhe.\n");
    } else if (shumaDiagonaleKryesore < shumaDiagonaleDytesore) {
        printf("Diagonalja dytesore ka shum�n m� t� madhe.\n");
    } else {
        printf("T� dyja diagonalet kan� shum�n e nj�jt�.\n");
    }

    return 0;
}

