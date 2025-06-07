//Merrni nje vektor nga perdorusi e riorganizoni ate duke I zhvendosur elementet x here.
//Zgjidhje me funksion

#include <stdio.h>

int maxSubarraySum(int v[], int n) {
    int max_so_far = v[0], max_ending_here = v[0];
    for (int i = 1; i < n; i++) {
        if (max_ending_here < 0)
            max_ending_here = v[i];
        else
            max_ending_here += v[i];
        if (max_ending_here > max_so_far)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

int main() {
    int n;
    printf("Jepni madhesine e vektorit: ");
    scanf("%d", &n);
    int v[n];
    printf("Jepni elementet e vektorit:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    int max_sum = maxSubarraySum(v, n);
    printf("Shuma maksimale e nje grupimi eshte: %d\n", max_sum);
    return 0;
}



