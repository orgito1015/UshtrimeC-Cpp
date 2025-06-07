#include <stdio.h>

#define M 3
#define N 4

void lexon_matricen(int A[M][N]) {
    printf("Jepni elementet e matrices (%dx%d):\n", M, N);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
}

void afishon_matricen(int A[M][N]) {
    printf("Matrica:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }
}

void rendit_rreshtin(int A[M][N], int rreshti) {
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (A[rreshti][i] > A[rreshti][j]) {
                int tmp = A[rreshti][i];
                A[rreshti][i] = A[rreshti][j];
                A[rreshti][j] = tmp;
            }
}

int numer_elemente_me_te_medhenj_se(int A[M][N], int nr) {
    int count = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (A[i][j] > nr)
                count++;
    return count;
}

int main() {
    int A[M][N];
    lexon_matricen(A);
    afishon_matricen(A);

    int rreshti;
    printf("Cilin rresht deshironi te renditni ne rend rrites? (0-%d): ", M - 1);
    scanf("%d", &rreshti);
    rendit_rreshtin(A, rreshti);
    afishon_matricen(A);

    int nr;
    printf("Jep nje numer per te gjetur sa elemente jane me te medhenj se ai: ");
    scanf("%d", &nr);
    int rezultati = numer_elemente_me_te_medhenj_se(A, nr);
    printf("Numri i elementeve me te medhenj se %d eshte: %d\n", nr, rezultati);

    return 0;
}

