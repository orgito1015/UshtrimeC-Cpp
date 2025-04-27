#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Funksioni për të gjetur modulo pozitiv
int mod(int a, int b) {
    return (a % b + b) % b;
}

// Funksioni për të gjetur determinantën e matricës
int determinant(int matrix[3][3], int n) {
    if (n == 1) return matrix[0][0];
    int det = 0;
    int temp[3][3];
    int sign = 1;
    for (int f = 0; f < n; f++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == f) continue;
                temp[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        det += sign * matrix[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}

// Funksioni për të gjetur inversin e matricës
void inverseMatrix(int matrix[3][3], int n, int inv[3][3]) {
    int det = determinant(matrix, n);
    det = mod(det, 26);
    int detInv = -1;
    for (int i = 0; i < 26; i++) {
        if (mod(det * i, 26) == 1) {
            detInv = i;
            break;
        }
    }
    if (detInv == -1) {
        printf("Matrica nuk ka invers modular.\n");
        exit(1);
    }

    int temp[3][3];
    int sign = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int subi = 0, subj = 0;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (x == i || y == j) continue;
                    temp[subi][subj++] = matrix[x][y];
                    if (subj == n - 1) {
                        subj = 0;
                        subi++;
                    }
                }
            }
            inv[j][i] = mod(sign * determinant(temp, n - 1), 26);
            sign = -sign;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = mod(inv[i][j] * detInv, 26);
        }
    }
}

// Funksioni për të kriptuar mesazhin
void encrypt(int key[3][3], char message[], int n) {
    int len = strlen(message);
    for (int i = 0; i < len; i += n) {
        int vec[3] = {0};
        for (int j = 0; j < n; j++) {
            vec[j] = message[i + j] - 'A';
        }
        int result[3] = {0};
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[j] += key[j][k] * vec[k];
            }
            result[j] = mod(result[j], 26);
        }
        for (int j = 0; j < n; j++) {
            message[i + j] = result[j] + 'A';
        }
    }
}

// Funksioni për të dekriptuar mesazhin
void decrypt(int key[3][3], char message[], int n) {
    int inv[3][3];
    inverseMatrix(key, n, inv);
    encrypt(inv, message, n);
}

// Funksioni për të plotësuar mesazhin
void padMessage(char message[], int n) {
    int len = strlen(message);
    int padding = n - (len % n);
    if (padding != n) {
        for (int i = 0; i < padding; i++) {
            message[len + i] = 'X'; // Shto 'X' për plotësim
        }
        message[len + padding] = '\0';
    }
}

int main() {
    int n = 3;
    int key[3][3] = {
        {6, 24, 1},
        {13, 16, 10},
        {20, 17, 15}
    };

    char message[100];
    printf("Shkruaj mesazhin për kriptim (vetëm shkronja të mëdha): ");
    scanf("%s", message);

    padMessage(message, n);

    printf("Mesazhi pas plotësimit: %s\n", message);
    encrypt(key, message, n);
    printf("Mesazhi i kriptuar: %s\n", message);
    decrypt(key, message, n);
    printf("Mesazhi i dekriptuar: %s\n", message);

    return 0;
}

