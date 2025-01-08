#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printoVektor(

int vektor[], int madhesia) {
    printf("[");
    for (int i = 0; i < madhesia; i++) {
        printf("%d", vektor[i]);
        if (i < madhesia - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void shtoElement(int vektor[], int *madhesia, int pozicioni, int elementi) {
    if (pozicioni < 0 || pozicioni > *madhesia) {
        printf("Pozicioni eshte jashte kufijve!\n");
        return;
    }
    for (int i = *madhesia; i > pozicioni; i--) {
        vektor[i] = vektor[i - 1];
    }
    vektor[pozicioni] = elementi;
    (*madhesia)++;
}

void hiqElement(int vektor[], int *madhesia, int pozicioni) {
    if (pozicioni < 0 || pozicioni >= *madhesia) {
        printf("Pozicioni eshte jashte kufijve!\n");
        return;
    }
    for (int i = pozicioni; i < *madhesia - 1; i++) {
        vektor[i] = vektor[i + 1];
    }
    (*madhesia)--;
}
void renditRrites(int vektor[], int madhesia) {
    for (int i = 0; i < madhesia - 1; i++) {
        for (int j = 0; j < madhesia - i - 1; j++) {
            if (vektor[j] > vektor[j + 1]) {
                int temp = vektor[j];
                vektor[j] = vektor[j + 1];
                vektor[j + 1] = temp;
            }
        }
    }
}

void renditZbrites(int vektor[], int madhesia) {
    for (int i = 0; i < madhesia - 1; i++) {
        for (int j = 0; j < madhesia - i - 1; j++) {
            if (vektor[j] < vektor[j + 1]) {
                int temp = vektor[j];
                vektor[j] = vektor[j + 1];
                vektor[j + 1] = temp;
            }
        }
    }
}

void krijoVektorFuqia(int vektor[], int vektorRi[], int madhesia, int fuqia) {
    for (int i = 0; i < madhesia; i++) {
        vektorRi[i] = (int)pow(vektor[i], fuqia);
    }
}

void kerkoElement(int vektor[], int madhesia, int elementi) {
    int gjetur = 0;
    for (int i = 0; i < madhesia; i++) {
        if (vektor[i] == elementi) {
            printf("Elementi %d gjendet ne pozicionin %d.\n", elementi, i);
            gjetur = 1;
        }
    }
    if (gjetur == 0) {
        printf("Elementi %d nuk ekziston ne vektor.\n", elementi);
    }
}

double llogaritMesataren(int vektor[], int madhesia) {
    double shuma = 0;
    for (int i = 0; i < madhesia; i++) {
        shuma += vektor[i];
    }
    return shuma / madhesia;
}

void gjejMaxMin(int vektor[], int madhesia, int *max, int *min) {
    *max = vektor[0];
    *min = vektor[0];
    for (int i = 1; i < madhesia; i++) {
        if (vektor[i] > *max) {
            *max = vektor[i];
        }
        if (vektor[i] < *min) {
            *min = vektor[i];
        }
    }
}

void ndryshoElement(int vektor[], int madhesia, int pozicioni, int vleraRe) {
    if (pozicioni < 0 || pozicioni >= madhesia) {
        printf("Pozicioni eshte jashte kufijve!\n");
        return;
    }
    vektor[pozicioni] = vleraRe;
}

int main() {
    int madhesia, opsioni, pozicioni, elementi, fuqia, max, min;
    double mesatarja;

    printf("Jepni madhesine e vektorit: ");
    scanf("%d", &madhesia);

    int vektor[100], vektorRi[100]; 

    printf("Jepni elementet e vektorit:\n");
    for (int i = 0; i < madhesia; i++) {
        printf("Elementi %d: ", i + 1);
        scanf("%d", &vektor[i]);
    }

    do {
        printf("\nZgjidhni nje opsion:\n");
        printf("1. Shto nje element\n");
        printf("2. Hiq nje element\n");
        printf("3. Rendit ne rend rrites\n");
        printf("4. Rendit ne rend zbrites\n");
        printf("5. Krijo nje vektor te ri me fuqite e elementeve\n");
        printf("6. Kerko nje element\n");
        printf("7. Llogarit mesataren dhe gjej maksimalen/minimalen\n");
        printf("8. Ndrysho nje element\n");
        printf("9. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &opsioni);

        switch (opsioni) {
            case 1:
                printf("Jepni pozicionin ku doni te shtoni elementin (0-%d): ", madhesia);
                scanf("%d", &pozicioni);
                printf("Jepni elementin per te shtuar: ");
                scanf("%d", &elementi);
                shtoElement(vektor, &madhesia, pozicioni, elementi);
                printf("Vektori pas shtimit: ");
                printoVektor(vektor, madhesia);
                break;
            case 2:
                printf("Jepni pozicionin e elementit per te hequr (0-%d): ", madhesia - 1);
                scanf("%d", &pozicioni);
                hiqElement(vektor, &madhesia, pozicioni);
                printf("Vektori pas heqjes: ");
                printoVektor(vektor, madhesia);
                break;
            case 3:
                renditRrites(vektor, madhesia);
                printf("Vektori ne rend rrites: ");
                printoVektor(vektor, madhesia);
                break;
            case 4:
                renditZbrites(vektor, madhesia);
                printf("Vektori ne rend zbrites: ");
                printoVektor(vektor, madhesia);
                break;
            case 5:
                printf("Jepni fuqine: ");
                scanf("%d", &fuqia);
                krijoVektorFuqia(vektor, vektorRi, madhesia, fuqia);
                printf("Vektori i ri me fuqite: ");
                printoVektor(vektorRi, madhesia);
                break;
            case 6:
                printf("Jepni elementin per te kerkuar: ");
                scanf("%d", &elementi);
                kerkoElement(vektor, madhesia, elementi);
                break;
            case 7:
                mesatarja = llogaritMesataren(vektor, madhesia);
                gjejMaxMin(vektor, madhesia, &max, &min);
                printf("Mesatarja: %.2f, Maksimumi: %d, Minimumi: %d\n", mesatarja, max, min);
                break;
            case 8:
                printf("Jepni pozicionin per te ndryshuar (0-%d): ", madhesia - 1);
                scanf("%d", &pozicioni);
                printf("Jepni vleren e re: ");
                scanf("%d", &elementi);
                ndryshoElement(vektor, madhesia, pozicioni, elementi);
                printf("Vektori pas ndryshimit: ");
                printoVektor(vektor, madhesia);
                break;
            case 9:
                printf("Dalje nga programi.\n");
                break;
            default:
                printf("Opsion i pavlefshem!\n");
        }
    } while (opsioni != 9);

    return 0;
}

