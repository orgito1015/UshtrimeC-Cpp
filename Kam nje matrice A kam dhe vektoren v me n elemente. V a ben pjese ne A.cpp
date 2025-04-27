// Kam nje matrice A kam dhe vektoren v me n elemente. V a ben pjese ne A?

#include <stdio.h>
#include <stdbool.h>

bool eshtePjese(int A[][100], int rreshta, int kolona, int v[], int n) {
    // Kontrollojmë nëse vektori ka të njëjtën gjatësi me numrin e kolonave të matricës
    if (kolona != n) {
        return false;
    }

    // Kontrollojmë secilin rresht të matricës
    for (int i = 0; i < rreshta; i++) {
        bool perputhet = true;

        for (int j = 0; j < kolona; j++) {
            if (A[i][j] != v[j]) {
                perputhet = false;
                break;
            }
        }

        if (perputhet) {
            return true; // Vektori u gjet në matricë
        }
    }

    return false; // Vektori nuk u gjet
}

int main() {
    int A[100][100];
    int v[100];
    int rreshta, kolona, n;

    // Input për matricën
    printf("Jep numrin e rreshtave dhe kolonave te matrices: ");
    scanf("%d %d", &rreshta, &kolona);

    printf("Jep elementet e matrices:\n");
    for (int i = 0; i < rreshta; i++) {
        for (int j = 0; j < kolona; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input për vektorin
    printf("Jep numrin e elementeve te vektorit: ");
    scanf("%d", &n);

    printf("Jep elementet e vektorit:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // Kontrolli nëse vektori është pjesë e matricës
    if (eshtePjese(A, rreshta, kolona, v, n)) {
        printf("Vektori eshte pjese e matrices.\n");
    } else {
        printf("Vektori nuk eshte pjese e matrices.\n");
    }

    return 0;
}



