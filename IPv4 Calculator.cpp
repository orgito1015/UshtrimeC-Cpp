#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to extract a segment of IPv4
int getSegment(const char* ip, int index) {
    char temp[4];
    int i = 0, j = 0;
    while (ip[i] && index > 0) {
        if (ip[i++] == '.') index--;
    }
    while (ip[i] && ip[i] != '.' && j < 3) {
        temp[j++] = ip[i++];
    }
    temp[j] = '\0';
    return atoi(temp);
}

// Function to convert a segment to binary
void segmentToBinary(int segment, char* binary) {
    for (int i = 7; i >= 0; i--) {
        binary[7 - i] = (segment & (1 << i)) ? '1' : '0';
    }
    binary[8] = '\0';
}

// Function to convert an IPv4 address to binary
void ipv4ToBinary(const char* ip) {
    for (int i = 1; i <= 4; i++) {
        int segment = getSegment(ip, i);
        char binary[9];
        segmentToBinary(segment, binary);
        printf("%s%s", binary, (i < 4) ? "." : "\n");
    }
}

// Function to identify the type of IPv4 address
void identifyIPv4Type(const char* ip) {
    int seg1 = getSegment(ip, 1);
    int seg2 = getSegment(ip, 2);

    if (seg1 == 10) {
        printf("The address is Private (Class A).\n");
    } else if (seg1 == 172 && seg2 >= 16 && seg2 <= 31) {
        printf("The address is Private (Class B).\n");
    } else if (seg1 == 192 && seg2 == 168) {
        printf("The address is Private (Class C).\n");
    } else if (seg1 == 127) {
        printf("The address is Loopback.\n");
    } else if (seg1 == 255 && seg2 == 255) {
        printf("The address is Broadcast.\n");
    } else if (seg1 >= 224 && seg1 <= 239) {
        printf("The address is Multicast.\n");
    } else if (seg1 >= 1 && seg1 <= 126) {
        printf("The address is Public (Class A).\n");
    } else if (seg1 >= 128 && seg1 <= 191) {
        printf("The address is Public (Class B).\n");
    } else if (seg1 >= 192 && seg1 <= 223) {
        printf("The address is Public (Class C).\n");
    } else {
        printf("The address is unknown or invalid.\n");
    }
}

// Main function
int main() {
    int choice;
    char ip[16];

    printf("IPv4 Calculator\n");
    printf("====================\n");
    printf("1. Convert IPv4 to Binary\n");
    printf("2. Identify IPv4 Type\n");
    printf("3. Exit the program\n");
    printf("====================\n");

    while (1) {
        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an IPv4 address (e.g., 192.168.1.1): ");
                scanf("%15s", ip);
                printf("IPv4 in binary: ");
                ipv4ToBinary(ip);
                break;

            case 2:
                printf("Enter an IPv4 address (e.g., 192.168.1.1): ");
                scanf("%15s", ip);
                printf("Network type: ");
                identifyIPv4Type(ip);
                break;

            case 3:
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}