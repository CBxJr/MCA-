#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
void insertFront(int val);
void insertAtPosition(int val, int pos);
void deleteFront();
void deleteAtPosition(int pos);
void updateNode(int pos, int newVal);
void display();

int main() {
    int choice, subChoice, val, pos, newVal;

    while (1) {
        printf("\n=============================\n");
        printf("    DOUBLY LINKED LIST MENU  \n");
        printf("=============================\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Update\n");
        printf("4. Display\n");
        printf("5. Count Nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("\n--- Insert Options ---\n");
                printf("1. Insert at Front\n");
                printf("2. Insert at Any Point (Position)\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);
                
                printf("Enter value to insert: ");
                scanf("%d", &val);

                if (subChoice == 1) {
                    insertFront(val);
                } else if (subChoice == 2) {
                    printf("Enter position (1-based index): ");
                    scanf("%d", &pos);
                    insertAtPosition(val, pos);
                } else {
                    printf("Invalid insert option!\n");
                }
                break;

            case 2:
                if (head == NULL) {
                    printf("\nList is empty! Nothing to delete.\n");
                    break;
                }
                printf("\n--- Delete Options ---\n");
                printf("1. Delete from Front\n");
                printf("2. Delete from Any Point (Position)\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                if (subChoice == 1) {
                    deleteFront();
                } else if (subChoice == 2) {
                    printf("Enter position to delete: ");
                    scanf("%d", &pos);
                    deleteAtPosition(pos);
                } else {
                    printf("Invalid delete option!\n");
                }
                break;

            case 3: 
                if (head == NULL) {
                    printf("\nList is empty!\n");
                    break;
                }
                printf("Enter position of node to update: ");
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &newVal);
                updateNode(pos, newVal);
                break;

            case 4:
                display();
                break;

            case 5: 
                {
                    int count = 0;
                    struct Node* temp = head;
                    while (temp != NULL) {
                        count++;
                        temp = temp->next;
                    }
                    printf("Total nodes in the list: %d\n", count);
                }
                break;

            case 6: 
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please choose between 1 and 6.\n");
        }
    }

    return 0;
}
void insertFront(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Successfully inserted %d at the front.\n", val);
}
void insertAtPosition(int val, int pos) {
    if (pos <= 1) {
        insertFront(val);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range. Inserting at the end instead.\n");
        temp = head;
        if (temp == NULL) {
            insertFront(val);
            free(newNode);
            return;
        }
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        printf("Successfully inserted %d at position %d.\n", val, pos);
    }
}
void deleteFront() {
    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }
    printf("Deleted %d from the front.\n", temp->data);
    free(temp);
}
void deleteAtPosition(int pos) {
    if (pos == 1) {
        deleteFront();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
}
void updateNode(int pos, int newVal) {
    struct Node* temp = head;
    int i = 1;
    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }
    if (temp != NULL) {
        int oldVal = temp->data;
        temp->data = newVal;
        printf("Updated position %d from %d to %d.\n", pos, oldVal, newVal);
    } else {
        printf("Invalid position!\n");
    }
}
void display() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("\nForward  : NULL <-> ");
    while (temp->next != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("%d <-> NULL\n", temp->data); // prints the last node
    printf("Backward : NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
