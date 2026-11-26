#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue();
void dequeue();
void display();
int main() {
    int choice;
    while (1) {
        printf("\n--- QUEUE OPERATIONS USING ARRAY ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter between 1 and 4.\n");
        }
    }
    return 0;
}
void enqueue() {
    int element;
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert element.\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = element;
    printf("Successfully inserted %d into the queue.\n", element);
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! No elements to delete.\n");
        front = -1;
        rear = -1;
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nQueue elements are:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
