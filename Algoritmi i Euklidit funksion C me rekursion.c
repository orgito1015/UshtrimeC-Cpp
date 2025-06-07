#include <stdio.h>

// Recursive function to find GCD using Euclidean Algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    
    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Compute and display the GCD
    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    
    return 0;
}

