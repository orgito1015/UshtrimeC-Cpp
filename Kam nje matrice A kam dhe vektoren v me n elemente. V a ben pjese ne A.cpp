// Kam nje matrice A kam dhe vektoren v me n elemente. V a ben pjese ne A?

#include <stdio.h>
#include <stdbool.h>

bool eshtePjese(int A[][100], int rreshta, int kolona, int v[], int n) {
    // Kontrollojm� n�se vektori ka t� nj�jt�n gjat�si me numrin e kolonave t� matric�s
    if (kolona != n) {
        return false;
    }

    // Kontrollojm� secilin rresht t� matric�s
    for (int i = 0; i < rreshta; i++) {
        bool perputhet = true;

        for (int j = 0; j < kolona; j++) {
            if (A[i][j] != v[j]) {
                perputhet = false;
                break;
            }
        }

        if (perputhet) {
            return true; // Vektori u gjet n� matric�
        }
    }

    return false; // Vektori nuk u gjet
}

int main() {
    int A[100][100];
    int v[100];
    int rreshta, kolona, n;

    // Input p�r matric�n
    printf("Jep numrin e rreshtave dhe kolonave te matrices: ");
    scanf("%d %d", &rreshta, &kolona);

    printf("Jep elementet e matrices:\n");
    for (int i = 0; i < rreshta; i++) {
        for (int j = 0; j < kolona; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input p�r vektorin
    printf("Jep numrin e elementeve te vektorit: ");
    scanf("%d", &n);

    printf("Jep elementet e vektorit:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // Kontrolli n�se vektori �sht� pjes� e matric�s
    if (eshtePjese(A, rreshta, kolona, v, n)) {
        printf("Vektori eshte pjese e matrices.\n");
    } else {
        printf("Vektori nuk eshte pjese e matrices.\n");
    }

    return 0;
}



