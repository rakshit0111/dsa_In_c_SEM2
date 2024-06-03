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

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to insert a node at a given position in the linked list
struct Node* insertAtPosition(struct Node* head, int newData, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    if (position == 1 || head == NULL) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    for (int i = 1; i < position && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position. Node not inserted.\n");
        free(newNode);
        return head;
    }

    prev->next = newNode;
    newNode->next = current;

    return head;
}

// Function to delete a node with a specific value from the linked list
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* prev = NULL;

    // Find the node to be deleted and keep track of the previous node
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If the key is not found
    if (current == NULL) {
        printf("Node with value %d not found.\n", key);
        return head;
    }

    // If the node to be deleted is the first node
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current); // Free the memory of the deleted node
    printf("Node with value %d deleted.\n", key);

    return head;
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
    int choice, data, position;

    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at the Beginning\n");
        printf("2. Insert at the End\n");
        printf("3. Insert at a Position\n");
        printf("4. Delete a Node\n");
        printf("5. Print the Linked List\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                printf("Enter the data of the node to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 5:
                printf("Linked List:\n");
                printList(head);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
