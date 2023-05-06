#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a new node at a specified position in the linked list
void insertNode(Node** head, int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, add the new node as the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // If position is 0, add the new node as the new head
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the linked list to find the position to insert the new node
    Node* current = *head;
    int i;
    for (i = 0; i < position-1; i++) {
        if (current->next == NULL) {
            printf("Invalid position, the linked list is not long enough.\n");
            return;
        }
        current = current->next;
    }

    // Insert the new node at the specified position
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    
    // Insert some nodes into the linked list
    insertNode(&head, 9, 0); // Insert 5 as the head
    insertNode(&head, 4, 1); // Insert 7 at position 1
    insertNode(&head, 18, 2); // Insert 9 at position 2
    
    // Print the linked list
    printList(head);

    return 0;
}
