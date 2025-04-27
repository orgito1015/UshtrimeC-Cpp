#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isValidIpAddress(const char *ip) {
    int num, dots = 0;
    const char *ptr;

    if (ip == NULL) {
        return 0;
    }

    ptr = ip;
    while (*ptr) {
        if (*ptr == '.') {
            dots++;
        } else if (!isdigit(*ptr)) {
            return 0;
        }
        ptr++;
    }

    if (dots != 3) {
        return 0;
    }

    ptr = strtok((char *)ip, ".");
    while (ptr) {
        if (!isdigit(*ptr)) {
            return 0;
        }
        num = atoi(ptr);
        if (num >= 0 && num <= 255) {
            ptr = strtok(NULL, ".");
        } else {
            return 0;
        }
    }
    return 1;
}

void convertToBinary(int num, char *binary) {
    for (int i = 7; i >= 0; i--) {
        binary[7 - i] = (num & (1 << i)) ? '1' : '0';
    }
    binary[8] = '\0';
}

void ipToBinary(const char *ip, char *binaryIp) {
    int octet;
    char binary[9];
    binaryIp[0] = '\0';

    const char *ptr = ip;
    while (*ptr) {
        if (*ptr == '.' || *ptr == '\0') {
            convertToBinary(octet, binary);
            strcat(binaryIp, binary);
            if (*ptr == '.') {
                strcat(binaryIp, ".");
            }
            octet = 0;
        } else {
            octet = octet * 10 + (*ptr - '0');
        }
        ptr++;
    }
    convertToBinary(octet, binary);
    strcat(binaryIp, binary);
}

int main() {
    char ip[16];
    char binaryIp[72];

    printf("Shkruani adresën IP: ");
    scanf("%15s", ip);

    if (!isValidIpAddress(ip)) {
        printf("Adresa IP është e pavlefshme.\n");
        return 1;
    }

    ipToBinary(ip, binaryIp);

    printf("Adresa IP në format binar është: %s\n", binaryIp);

    return 0;
}

