//Program to implement Circular Queue using Arrays.
//Include header files
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
//Global declarations
int queue[MAX];
int front = -1, rear = -1;
//Function Declarations
void enQueue (int queue[], int val);
int deQueue (int queue[]);
void display (int queue[]);
//Main method to write Menu
int main (int argc, char *argv[]) {
    int val, option;
    do {
        printf("\nCircular Queue Menu : 1. enQueue \t 2. deQueue \t 3. Display \t 4. Exit\n");
        printf("================================================================================\n");
        printf("Enter your option: ");
        scanf("%d",&option);
        switch (option) {
            case 1:
                printf("\nEnter the number to be inserted in queue : ");
                scanf("%d",&val);
                enQueue(queue, val);
                display(queue);
                break;
            case 2:
                val = deQueue (queue);
                if (val != -1) 
                printf("\nThe number deleted is %d\n", val);
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
void enQueue (int queue[], int val) {
    if ((front == 0 && rear == MAX-1) || (rear == front - 1))
        printf("\nOVERFLOW\n");
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = val;
    }
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = val;
    }
}
int deQueue (int queue[]) {
    if (front == -1) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    else {
        int val = queue[front];
        if (front == rear)
            front = rear = -1;
        else {
            front = (front + 1) % MAX;
        }
        return val;
    }
}
void display (int queue[]) {
    if (front == -1) 
        printf("\nQUEUE IS EMPTY\n");
    else {
        printf("\nQueue Elements : ");
        for (int i = front; (i%MAX) != rear; i++) {
            printf("%d ", queue[i%MAX]);
        }
        printf("%d\n", queue[rear]);
    }
}