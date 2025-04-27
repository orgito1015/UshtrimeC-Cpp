#include <stdio.h> 

float convertToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}
void readTemperatures(float temps[], int size) {
    printf("Shkruani %d temperatura ne Celsius:\n", size);
    for (int i = 0; i < size; i++) { 
        printf("Temperatura %d: ", i + 1); 
        scanf("%f", &temps[i]); 
    }
}
void displayConvertedTemperatures(float temps[], int size) {
  
    printf("\nTemperaturat e konvertuara ne Fahrenheit:\n");
    for (int i = 0; i < size; i++) { 
        float fahrenheit = convertToFahrenheit(temps[i]); 
        printf("Celsius: %.2f -> Fahrenheit: %.2f\n", temps[i], fahrenheit); 
    }
}
int main() {
    int n; 
    printf("Sa temperatura do te konvertoni? ");
    scanf("%d", &n); 
    float temperatures[n];
    readTemperatures(temperatures, n);
    displayConvertedTemperatures(temperatures, n);
    return 0; 
}




