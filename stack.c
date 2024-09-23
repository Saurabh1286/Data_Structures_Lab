//Program to implement Stack using Arrays.
//Include header files
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
//Global declarations
int st[MAX];
int top=-1;
//Function Declarations
void push(int st[],int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
//Main method to write Menu
int main(int argc, char*argv[])
{
   int val,option;
   do
   {
      printf("\nStack Menu : 1. Push \t 2. Pop \t 3. Peek \t 4. Display \t 5. Exit\n");
      printf("================================================================================\n");
      printf("Enter your option: ");
      scanf("%d",&option);
      switch(option)
      {
         case 1:
            printf("\nEnter the number to be pushed in the stack: ");
            scanf("%d",&val);
            push(st, val);
            display(st);
            break;
         case 2:
            val=pop(st);
            if(val!=-1)
               printf("\nThe value deleted from the stack is: %d\n", val);
            display(st);
            break;
         case 3:
            val=peek(st);
            if(val!=-1)
               printf("\nThe value stored at the top of stack is: %d\n", val);
            break;
         case 4 : 
            display(st);
            break;
         case 5:
                printf("\nEND OF PROGRAM !!");         
      }
   } while (option !=5);
   return 0;  
}
//Function Definitions
void push(int st[], int val) {
    if(top == MAX-1) {
      printf("\nSTACK OVERFLOW\n");
    }
    else
    {
      top++;
      st[top]=val;
    }
}
int pop(int st[]) {
   int val;
   if(top == -1) {
      printf("\nSTACK UNDERFLOW\n");
      return -1;
   }
   else {
      val = st[top];
      top--;
      return val;
   }
}
void display(int st[]) {
   if (top == -1) {
      printf("\nSTACK IS EMPTY\n");
      return;
   }
   printf("\nStack Elements : ");
   for(int i = top; i >= 0; i--) {
      printf(" %d",st[i]);
   }
   printf("\n");
}
int peek(int st[]) {
   if(top == -1) {
      printf("\nSTACK IS EMPTY\n");
      return -1;   
   }
   return (st[top]);
}