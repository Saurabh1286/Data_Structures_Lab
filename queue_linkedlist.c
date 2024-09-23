//Program to implement Queues using Linked List.
//Include header files
#include <stdio.h>
#include <stdlib.h>
//Global declarations
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};
//Function Declarations
void enQueue (struct Queue* que, int val);
int deQueue (struct Queue* que);
void display (struct Queue* que);
//Main method to write Menu
int main (char argc, char *argv []) {
    int val, opt;
    struct Queue* que = (struct Queue*) malloc (sizeof(struct Queue));
    que -> front = que -> rear = NULL;
    do {
        printf("\nQueue Menu : 1. enQueue \t 2. deQueue \t 3. Display \t 4. Exit\n");
        printf("========================================================================\n");
        printf("Enter your option: ");
        scanf("%d",&opt);
        switch (opt) {
            case 1:
                printf("\nEnter the number to be inserted in queue : ");
                scanf("%d",&val);
                enQueue(que, val);
                display(que);
                break;
            case 2:
                val = deQueue (que);
                if (val != -1) 
                printf("\nThe number deleted is %d\n", val);
                display(que);
                break;
            case 3:
                display(que);
                break;
            case 4:
                printf("\nEND OF PROGRAM !!");
        }
    }
    while (opt != 4);
    return 0;
}
//Function Definitions
struct Node* create_Node (int val) {
    struct Node* node = (struct Node*) malloc (sizeof(struct Node));
    node -> data = val;
    node -> next = NULL;
    return node;
}
void enQueue (struct Queue* que, int val) {
    struct Node* new_Node = create_Node (val);
    if (que -> front == NULL) {
        que -> front  = que -> rear = new_Node;
        return;
    }
    que -> rear -> next = new_Node;
    que -> rear = new_Node;
}
int deQueue (struct Queue* que) {
    if (que -> front == NULL) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    int val = que -> front -> data;
    struct Node* node = que -> front;
    if (que -> front == que -> rear) {
        que -> front = que -> rear = NULL;
        free (node);
        return val;
    }
    que -> front = que -> front -> next;
    free (node);
    return val;
}
void display (struct Queue* que) {
    if (que -> front == NULL) {
        printf("\nQueue is Empty\n");
        return;
    }
    struct Node* curr = que -> front;
    printf("\nQueue Elements are : ");
    while (curr != NULL) {
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}