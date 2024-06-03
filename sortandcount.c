#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to swap the data of two nodes
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to sort the linked list using bubble sort
void sortLinkedList(struct Node* head) {
    int swapped;
    struct Node* current;
    struct Node* lastSorted = NULL;

    // Check for empty list
    if (head == NULL)
        return;

    do {
        swapped = 0;
        current = head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        lastSorted = current;
    } while (swapped);
}

// Function to reverse the linked list
struct Node* reverseLinkedList(struct Node* head) {
    struct Node *prev, *current, *next;
    prev = NULL;
    current = head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; // new head after reversal
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int data, nodeCount;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 8);
    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 7);

    printf("Original Linked List:\n");
    printList(head);

    // Count the number of nodes
    nodeCount = countNodes(head);
    printf("\nNumber of nodes in the linked list: %d\n", nodeCount);

    // Sort the linked list
    sortLinkedList(head);
    printf("\nLinked List after sorting:\n");
    printList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);
    printf("\nLinked List after reversal:\n");
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
