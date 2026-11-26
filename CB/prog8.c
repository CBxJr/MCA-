#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push();
void pop();
void display();
int main() {
    int choice;
    while (1) {
        printf("\n--- STACK OPERATIONS USING LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
void push() {
    int element;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nStack Overflow! Memory allocation failed.\n");
        return;
    }
    printf("Enter element to push: ");
    scanf("%d", &element);
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d into the stack.\n", element);
}
void pop() {
    if (top == NULL) {
        printf("\nStack Underflow! No elements to pop.\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("\nStack is empty!\n");
        return;
    }

    struct Node* temp = top;
    printf("\nStack elements are:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
