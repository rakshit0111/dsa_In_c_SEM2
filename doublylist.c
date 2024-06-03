#include <stdio.h>
#include <stdlib.h>

// Define a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to insert a node at a given position in the doubly linked list
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; ++i) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position, insertion failed.\n");
        return head;
    }

    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to delete a node from the beginning of the doubly linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, deletion failed.\n");
        return NULL;
    }

    struct Node* newHead = head->next;
    if (newHead != NULL) {
        newHead->prev = NULL;
    }

    free(head);
    return newHead;
}

// Function to delete a node from the end of the doubly linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, deletion failed.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);

    return head;
}

// Function to delete a node with a given data from the doubly linked list
struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty, deletion failed.\n");
        return NULL;
    }

    if (head->data == data) {
        struct Node* newHead = head->next;
        if (newHead != NULL) {
            newHead->prev = NULL;
        }
        free(head);
        return newHead;
    }

    struct Node* temp = head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found, deletion failed.\n", data);
        return head;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);

    return head;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate doubly linked list operations
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at the Beginning\n");
        printf("2. Insert at the End\n");
        printf("3. Insert at a Position\n");
        printf("4. Delete from the Beginning\n");
        printf("5. Delete from the End\n");
        printf("6. Delete a Node with Given Data\n");
        printf("7. Print List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteFromBeginning(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 7:
                printf("Doubly Linked List: ");
                printList(head);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 8);

    return 0;
}
