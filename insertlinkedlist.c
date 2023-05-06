#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node with a given value at the beginning of a linked list
void insertAtBeginning(struct Node** head, int value) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Set the value and next pointer of the new node
    newNode->data = value;
    newNode->next = *head;

    // Set the head pointer to the new node
    *head = newNode;
}

int main() {
    // Create an empty linked list
    struct Node* head = NULL;

    // Insert some values at the beginning of the list
    insertAtBeginning(&head, 9);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 18);
    insertAtBeginning(&head, 31);

    // Traverse the linked list and print its values
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}
