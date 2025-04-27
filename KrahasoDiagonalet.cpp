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

    // Llogarit shumën e diagonaleve
    for (int i = 0; i < N; i++) {
        shumaDiagonaleKryesore += T[i][i];        // Elementet e diagonales kryesore
        shumaDiagonaleDytesore += T[i][N - 1 - i]; // Elementet e diagonales dytësore
    }

    // Afisho shumën e diagonaleve
    printf("Shuma e diagonales kryesore: %d\n", shumaDiagonaleKryesore);
    printf("Shuma e diagonales dytesore: %d\n", shumaDiagonaleDytesore);

    // Krahaso shumën e diagonaleve
    if (shumaDiagonaleKryesore > shumaDiagonaleDytesore) {
        printf("Diagonalja kryesore ka shumën më të madhe.\n");
    } else if (shumaDiagonaleKryesore < shumaDiagonaleDytesore) {
        printf("Diagonalja dytesore ka shumën më të madhe.\n");
    } else {
        printf("Të dyja diagonalet kanë shumën e njëjtë.\n");
    }

    return 0;
}

