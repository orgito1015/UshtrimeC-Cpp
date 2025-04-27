#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int N, M;

    // Hap skedarin për lexim
    file = fopen("C:\\Users\\lekao\\Desktop\\tabela.txt", "r");
    if (file == NULL) {
        printf("Gabim: Nuk mund te hapet skedari!\n");
        return 1;
    }

    // Lexo dimensionet e tabelës
    fscanf(file, "%d %d", &N, &M);

    int T[N][M];

    // Lexo elementet e tabelës nga skedari
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fscanf(file, "%d", &T[i][j]);
        }
    }

    // Mbyll skedarin pasi leximi përfundon
    fclose(file);

    // Gjej dhe afisho minimumin e çdo rreshti
    for (int i = 0; i < N; i++) {
        int minimumi = T[i][0]; // Supozo që elementi i parë është më i vogli
        for (int j = 1; j < M; j++) {
            if (T[i][j] < minimumi) {
                minimumi = T[i][j];
            }
        }
        printf("Minimumi i rreshtit %d: %d\n", i + 1, minimumi);
    }

    return 0;
}

