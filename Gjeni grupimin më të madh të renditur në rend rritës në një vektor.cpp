#include <stdio.h>

void grupimi_me_i_madh(int v[], int n) {
    int max_len = 1, len = 1, start = 0, max_start = 0;

    for (int i = 1; i < n; i++) {
        if (v[i] > v[i - 1]) {
            len++;
        } else {
            if (len > max_len) {
                max_len = len;
                max_start = start;
            }
            len = 1;
            start = i;
        }
    }

    if (len > max_len) {
        max_len = len;
        max_start = start;
    }

    printf("Grupimi me i madh ne rend rrites:\n");
    for (int i = max_start; i < max_start + max_len; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int v[] = {2, 1, 3, 5, 9, -1, 2};
    int n = sizeof(v) / sizeof(v[0]);

    grupimi_me_i_madh(v, n);

    return 0;
}

