//Program to implement Stack using Linked List.
//Include header files
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//Global declarations
struct Node {
    int data;
    struct Node* next ;
};
struct Stack {
    struct Node* top;
};
//Function Declarations
struct Node* create_Node (int val);
void push (struct Stack* stk, int val);
int pop (struct Stack* stk);
int peek (struct Stack* stk);
void display (struct Stack* stk);
//Main method to write Menu
int main (int argc, char *argv[]) {
    int opt, val;
    struct Stack* stk = (struct Stack*)malloc(sizeof(struct Stack));
    stk -> top = NULL;
    do
    {
    printf("\nStack Menu : 1. Push \t 2. Pop \t 3. Peep \t 4. Display \t 5. Exit\n");
    printf("================================================================================\n");
    printf("Enter your choice : ");
    scanf("%d", &opt);
        switch(opt) {
         case 1:
            printf("\nEnter the number to be pushed in the stack: ");
            scanf("%d",&val);
            push(stk, val);
            display(stk);
            break;
         case 2:
            val=pop(stk);
            if(val!=-1)
               printf("\nThe value deleted from the stack is: %d\n", val);
               display(stk);
            break;
         case 3:
            val=peek(stk);
            if(val!=-1)
            printf("\nThe value stored at the top of stack is: %d\n", val);
            break;
         case 4 : 
            display(stk);
            break;            
      }
    } while (opt !=5);
    return 0;   
}
//Function Definitions
struct Node* create_Node (int val) {
    struct Node* node = (struct Node*) malloc (sizeof(struct Node));
    node -> data = val;
    node -> next = NULL;
    return node;
}
void push (struct Stack* stk, int val) {
    struct Node* new_Node = create_Node (val);
    new_Node -> next = stk -> top;
    stk -> top = new_Node;
}
int pop (struct Stack* stk) {
    if (stk -> top == NULL) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    int val = stk -> top -> data;
    struct Node* node = stk -> top;
    stk -> top = stk -> top -> next;
    free(node);
    return val;
}
int peek (struct Stack* stk) {
    if (stk -> top == NULL) {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    return stk -> top -> data;
}
void display (struct Stack* stk) {
    if (stk -> top == NULL) {
        printf("\nStack is Empty.\n");
        return;
    }
    printf("\nStack Elements : ");
    struct Node* curr = stk -> top;
    while (curr != NULL) {
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}