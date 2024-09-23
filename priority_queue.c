//Program to implement Priority Queue using Arrays.
//Include header files
#include <stdio.h>
#include <conio.h>
#define MAX 5
//Global declarations
int queue[MAX][2];
int size = 0;
//Function declarations
void enQueue(int queue[][2],int val, int prio);
int deQueue(int queue[][2]);
void display(int queue[][2]);
//Main method to write Menu
int main (int argc, char *argv[]) {
    int val, option, prio;
    do {
        printf("\nPriority Queue Menu : 1. enQueue \t 2. deQueue \t 3. Display \t 4. Exit\n");
        printf("================================================================================\n");
        printf("Enter your option: ");
        scanf("%d",&option);
        switch (option) {
            case 1:
                printf("\nEnter the number to be inserted in queue : ");
                scanf("%d",&val);
                printf("Enter the priority of the number to be inserted in queue : ");
                scanf("%d",&prio);
                enQueue(queue, val, prio);
                display(queue);
                break;
            case 2:
                val = deQueue (queue);
                if (val != -1) 
                printf("\nThe number with highest priority is %d\n", val);
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
//Function definitions
void enQueue(int queue[][2], int val, int prio) {
    if (size == MAX) {
        printf("\nOVERFLOW\n");
        return;
    }
    int i = size - 1;
    while (i >= 0 && queue[i][1] > prio) {
        queue[i+1][0] = queue[i][0];
        queue[i+1][1] = queue[i][1];
        i--;
    }
    queue[i+1][0] = val;
    queue[i+1][1] = prio;
    size++;
}
int deQueue(int queue[][2]) {
    if (size == 0) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    int val = queue[0][0];
    for (int i = 0; i <size - 1; i++) {
        queue[i][0] = queue[i+1][0];
        queue[i][1] = queue[i+1][1];
    }
    size--;
    return val;
}
void display(int queue[][2]) {
    if (size == 0) {
        printf("\nQueue is Empty.\n");
        return;
    }
    printf("\nQueue Elements are : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[i][0]);
    }
    printf("\n");
    printf("          Priority : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[i][1]);
    }
    printf("\n");
}