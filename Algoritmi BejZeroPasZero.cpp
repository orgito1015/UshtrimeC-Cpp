#include <stdio.h>

int main() {
    int N, M;

    // Lexo dimensionet e tabelës
    printf("Jep numrin e rreshtave (N): ");
    scanf("%d", &N);
    printf("Jep numrin e shtyllave (M): ");
    scanf("%d", &M);

    int T[N][M];

    // Lexo elementet e tabelës
    printf("Jep elementet e tabeles:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("T[%d][%d]: ", i, j);
            scanf("%d", &T[i][j]);
        }
    }

    // Modifiko tabelën për të bërë 0 çdo element pas një 0 në çdo rresht
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (T[i][j] == 0) {
                for (int k = j + 1; k < M; k++) {
                    T[i][k] = 0;
                }
                break; // Ndalon ciklin e brendshëm kur gjen 0
            }
        }
    }

    // Afisho tabelën pas modifikimit
    printf("\nTabela pas modifikimit:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

    return 0;
}

