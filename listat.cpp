#include <stdio.h>
#include <stdlib.h>

// Struktura e nyjes së listës
struct Node {
    int data;               // Vlera që ruan nyja
    struct Node* next;      // Pointeri që tregon te nyja tjetër
};

// Funksion për shtim në fillim të listës
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); // aloko kujtesë
    newNode->data = value;         // cakto vlerën
    newNode->next = *head;         // lidhe nyjen e re me pjesën tjetër të listës
    *head = newNode;               // bëje këtë nyje si të parën (head)
}

// Funksion për shtim në fund të listës
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;   // nëse lista është bosh, nyja e parë është kjo
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;  // shko te fundi i listës
    }
    temp->next = newNode;   // lidhe nyjen e fundit me të renë
}

// Funksion për fshirjen e nyjes së parë
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("Lista është bosh. S'ka asgjë për të fshirë.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;  // lëvize head te nyja e dytë
    free(temp);             // çliro kujtesën e nyjes së parë
}

// Funksion për printimin e listës
void printList(struct Node* head) {
    printf("Lista: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Funksion për numërimin e elementëve të listës
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Funksioni kryesor
int main() {
    struct Node* head = NULL;  // krijo një listë bosh

    // Shto disa elementë
    insertAtBeginning(&head, 10);  // Lista: 10
    insertAtBeginning(&head, 5);   // Lista: 5 -> 10
    insertAtEnd(&head, 20);        // Lista: 5 -> 10 -> 20
    insertAtEnd(&head, 30);        // Lista: 5 -> 10 -> 20 -> 30

    // Printo listën
    printList(head);               // Output: Lista: 5 -> 10 -> 20 -> 30 -> NULL

    // Fshi nyjen e parë
    deleteFirst(&head);           // Fshi 5

    // Printo përsëri listën
    printList(head);              // Output: 10 -> 20 -> 30 -> NULL

    // Numëro elementët
    int total = countNodes(head);
    printf("Numri i elementëve në listë: %d\n", total); // Output: 3

    return 0;
}

