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
        printf("\n--- CIRCULAR QUEUE OPERATIONS ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
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
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
void enqueue() {
    int element;
    if ((rear + 1) % MAX == front) {
        printf("\nQueue Overflow!\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &element);

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = element;
    printf("Inserted %d\n", element);
}
void dequeue() {
    if (front == -1) {
        printf("\nQueue Underflow!\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}
void display() {
    if (front == -1) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nQueue elements are:\n");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
