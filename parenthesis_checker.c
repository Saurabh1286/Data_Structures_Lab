//Program for Parenthesis Matching.
//Include header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
//Global declarations
char stk[MAX];
int top=-1;
//Function Declarations
void push(char c);
char pop();
//Main method to write Menu
int main() {
    char exp[MAX], temp;
    int flag = 1;
    printf("\nEnter an expression: ");
    gets(exp);
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[') {
            push(exp[i]);
        }
        if (exp[i]==')' || exp[i]=='}' || exp[i]==']') {
            if (top == -1){
                flag = 0;
            }
            else{
                temp = pop();
                if (exp[i] == ')' && (temp == '{' || temp == '[')) {
                    flag = 0;
                }
                if (exp[i] == '}' && (temp == '(' || temp == '[')) {
                    flag = 0;
                }
                if (exp[i] == ']' && (temp == '(' || temp == '}')) {
                    flag = 0;
                }
            }
        }
    }
    if (top >= 0) {
        flag=0;
    }
    if (flag == 1) {
        printf("\nValid Expression.");
    }
    else {
        printf("\nInvalid Expression.");
    }
    return 0;
}
//Function Definitions
void push(char c) {
    if (top == (MAX-1)) {
        printf("Stack Overflow\n");
        return;
    }
    top = top+1;
    stk[top] = c;
}
char pop() {
    if (top == -1) {
        printf("\nStack Underflow");
        return NULL;
    }
    return (stk[top--]);
}