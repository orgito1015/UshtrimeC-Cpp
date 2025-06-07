#include <stdio.h>
#include <stdlib.h>

// Struktura e nyjes s� list�s
struct Node {
    int data;               // Vlera q� ruan nyja
    struct Node* next;      // Pointeri q� tregon te nyja tjet�r
};

// Funksion p�r shtim n� fillim t� list�s
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); // aloko kujtes�
    newNode->data = value;         // cakto vler�n
    newNode->next = *head;         // lidhe nyjen e re me pjes�n tjet�r t� list�s
    *head = newNode;               // b�je k�t� nyje si t� par�n (head)
}

// Funksion p�r shtim n� fund t� list�s
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;   // n�se lista �sht� bosh, nyja e par� �sht� kjo
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;  // shko te fundi i list�s
    }
    temp->next = newNode;   // lidhe nyjen e fundit me t� ren�
}

// Funksion p�r fshirjen e nyjes s� par�
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("Lista �sht� bosh. S'ka asgj� p�r t� fshir�.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;  // l�vize head te nyja e dyt�
    free(temp);             // �liro kujtes�n e nyjes s� par�
}

// Funksion p�r printimin e list�s
void printList(struct Node* head) {
    printf("Lista: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Funksion p�r num�rimin e element�ve t� list�s
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
    struct Node* head = NULL;  // krijo nj� list� bosh

    // Shto disa element�
    insertAtBeginning(&head, 10);  // Lista: 10
    insertAtBeginning(&head, 5);   // Lista: 5 -> 10
    insertAtEnd(&head, 20);        // Lista: 5 -> 10 -> 20
    insertAtEnd(&head, 30);        // Lista: 5 -> 10 -> 20 -> 30

    // Printo list�n
    printList(head);               // Output: Lista: 5 -> 10 -> 20 -> 30 -> NULL

    // Fshi nyjen e par�
    deleteFirst(&head);           // Fshi 5

    // Printo p�rs�ri list�n
    printList(head);              // Output: 10 -> 20 -> 30 -> NULL

    // Num�ro element�t
    int total = countNodes(head);
    printf("Numri i element�ve n� list�: %d\n", total); // Output: 3

    return 0;
}

