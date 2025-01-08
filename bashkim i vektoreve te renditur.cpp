#include <stdio.h>

#define MADHESIA_MAX 100

void nderthurVektoret(int vektor1[], int madhesia1, int vektor2[], int madhesia2, int vektorRezultat[]) {
    int i = 0, j = 0, k = 0;

    while (i < madhesia1 && j < madhesia2) {
        vektorRezultat[k] = vektor1[i];
        k++;
        i++;
        vektorRezultat[k] = vektor2[j];
        k++;
        j++;
    }

    while (i < madhesia1) {
        vektorRezultat[k] = vektor1[i];
        k++;
        i++;
    }

    while (j < madhesia2) {
        vektorRezultat[k] = vektor2[j];
        k++;
        j++;
    }
}

int main() {
    int vektor1[MADHESIA_MAX], vektor2[MADHESIA_MAX], vektorRezultat[2 * MADHESIA_MAX];
    int madhesia1, madhesia2, madhesiaRezultat, i;

    printf("Shkruani madhesine e vektorit te pare (<= %d): ", MADHESIA_MAX);
    scanf("%d", &madhesia1);

    if (madhesia1 > MADHESIA_MAX || madhesia1 <= 0) {
        printf("Madhesia e dhene nuk eshte e vlefshme.\n");
        return 1;
    }

    printf("Shkruani elementet e vektorit te pare:\n");
    for (i = 0; i < madhesia1; i++) {
        scanf("%d", &vektor1[i]);
    }

    printf("Shkruani madhesine e vektorit te dyte (<= %d): ", MADHESIA_MAX);
    scanf("%d", &madhesia2);

    if (madhesia2 > MADHESIA_MAX || madhesia2 <= 0) {
        printf("Madhesia e dhene nuk eshte e vlefshme.\n");
        return 1;
    }

    printf("Shkruani elementet e vektorit te dyte:\n");
    for (i = 0; i < madhesia2; i++) {
        scanf("%d", &vektor2[i]);
    }

    madhesiaRezultat = madhesia1 + madhesia2;
    nderthurVektoret(vektor1, madhesia1, vektor2, madhesia2, vektorRezultat);

    printf("Vektori i nderthurur eshte:\n");
    for (i = 0; i < madhesiaRezultat; i++) {
        printf("%d ", vektorRezultat[i]);
    }
    printf("\n");

    return 0;
}
