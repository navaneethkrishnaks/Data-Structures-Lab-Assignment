#include <stdio.h>
#include <stdlib.h>

#define n 5

void insert(int queue[], int *rear, int *front);
void delete(int queue[], int *rear, int *front);
void display(int queue[], int rear, int front);

int main() {
    int queue[n], ch = 1, front = 0, rear = 0;

    printf("Queue using Array");
    printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit");
    while (ch) {
        printf("\nEnter the Choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert(queue, &rear, &front);
                break;
            case 2:
                delete(queue, &rear, &front);
                break;
            case 3:
                display(queue, rear, front);
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Choice: please see the options");
        }
    }
    return 0;
}

void insert(int queue[], int *rear, int *front) {
    if (*rear == n) {
        printf("\nQueue is Full");
    } else {
        int value;
        printf("\nEnter value : ");
        scanf("%d", &value);
        queue[*rear] = value;
        (*rear)++;
    }
}

void delete(int queue[], int *rear, int *front) {
    if (*front == *rear) {
        printf("\nQueue is empty");
    } else {
        printf("\nDeleted Element is %d", queue[*front]);
        for (int i = 0; i < *rear - 1; i++) {
            queue[i] = queue[i + 1];
        }
        (*rear)--;
    }
}

void display(int queue[], int rear, int front) {
    if (front == rear) {
        printf("\nQueue is Empty");
    } else {
        printf("\nQueue Elements are:\n");
        for (int i = front; i < rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
