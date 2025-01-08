#include <stdio.h>

int main() {
    int i, shuma = 0, numri = 3;

    // Përdorim një cikël për të llogaritur shumen e serisë për 300 termat e parë
    for (i = 1; i <= 300; i++) {
        if (i % 2 != 0) {
            // Kur indeksi është tek (1, 3, 5, ...) (pozitive)
            shuma += numri;
        } else {
            // Kur indeksi është çift (2, 4, 6, ...) (negative)
            shuma -= numri;
        }

        // Përshtat numrin për në termet e ardhshme
        numri += 2;
    }

    // Shfaqim rezultatin e shumes
    printf("Shuma e serise per 300 termat e pare eshte: %d\n", shuma);

    return 0;
}

