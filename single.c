#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add/insert a node at the beginning
struct Node* insertBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to add/insert a node at the end
void insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to add/insert node at a particular position/location
void insertAtPosition(struct Node* head, int position, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node from the beginning
struct Node* deleteBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* newHead = head->next;
    free(head);
    return newHead;
}

// Function to delete a node from the end
void deleteEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node from a particular position
void deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    if (position == 0) {
        head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    struct Node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
}

// Function to reverse the list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nOptions:\n");
        printf("1: create a list containing 08 values/nodes\n");
        printf("2: display the list\n");
        printf("3: add/insert a node at the beginning\n");
        printf("4: add/insert a node at the end\n");
        printf("5: add/insert node at a particular position/location\n");
        printf("6: delete a node from the beginning\n");
        printf("7: delete a node from the end\n");
        printf("8: delete a node from a particular position\n");
        printf("9: Reverse the list\n");
        printf("10: Take user input based on the given choices\n");
        printf("0: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 1; i <= 8; i++) {
                    head = insertBeginning(head, i);
                }
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertBeginning(head, data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertEnd(head, data);
                break;
            case 5:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtPosition(head, position, data);
                break;
            case 6:
                head = deleteBeginning(head);
                break;
            case 7:
                deleteEnd(head);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(head, position);
                break;
            case 9:
                head = reverseList(head);
                break;
            case 10:
                printf("1: create a list containing 08 values/nodes\n");
                printf("2: display the list\n");
                printf("3: add/insert a node at the beginning\n");
                printf("4: add/insert a node at the end\n");
                printf("5: add/insert node at a particular position/location\n");
                printf("6: delete a node from the beginning\n");
                printf("7: delete a node from the end\n");
                printf("8: delete a node from a particular position\n");
                printf("9: Reverse the list\n");
                printf("0: Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    // Free allocated memory before exiting
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
