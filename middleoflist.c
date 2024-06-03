#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* findMiddle(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    printf("Linked List: ");
    printList(head);

    struct Node* middle = findMiddle(head);
    printf("Middle of the Linked List: %d\n", middle->data);

    return 0;
}
