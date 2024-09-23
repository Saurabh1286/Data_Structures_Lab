//Program to implement Queue using Arrays.
//Include header files
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
//Global declarations
int queue[MAX];
int front = -1, rear = -1;
//Function Definitions
void insert (int queue[], int val);
int delete_element (int queue[]);
void display (int queue[]);
//Main method to write Menu
int main (int argc, char *argv[]) {
    int val, option;
    do {
        printf("\nQueue Menu : 1. enQueue \t 2. deQueue \t 3. Display \t 4. Exit\n");
        printf("========================================================================\n");
        printf("Enter your option: ");
        scanf("%d",&option);
        switch (option) {
            case 1:
                printf("\nEnter the number to be pushed in queue : ");
                scanf("%d",&val);
                insert(queue, val);
                display(queue);
                break;
            case 2:
                val = delete_element (queue);
                if (val != -1) {
                    printf("\nDeleted element is %d\n", val);
                }
                display(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("\nEND OF PROGRAM !!");
        }
    }
    while (option != 4);
    return 0;
}
//Function Definitions
void insert (int queue[], int val) {
    if (rear == MAX-1) {
        printf("\nOVERFLOW\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = val;
        return;
    }
    rear++;
    queue[rear] = val;
}
int delete_element (int queue[]) {
    if (front == -1 || front > rear) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    int val = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;
    }
    return val;
}
void display (int queue[]) {
    if (front == -1 || front > rear) {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }
    printf("\nQueue Elements : ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}