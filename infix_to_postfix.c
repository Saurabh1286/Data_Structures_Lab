//Program to convert infix expression to postfix expression.
//Include header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
//Global declarations
char st[MAX];
int top = -1;
//Function Declarations
void push(char st[], char val);
char pop(char st[]);
void InfixtoPostfix(char source[], char target[]);
int getPriority(char);
//Main method to write Menu
int main() {
    char infix[MAX], postfix[MAX];
    printf("\nEnter any infix expression : ");
    gets(infix);
    strcpy(postfix, "");
    InfixtoPostfix(infix, postfix);
    printf("\nThe corresponding postfix expression is :");
    puts(postfix);
    return 0;
}
//Function Definitions
void InfixtoPostfix(char source[], char target[]) {
    int i = 0, j = 0;
    char temp;
    strcpy(target,"");
    while(source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(st, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (st[top] != '('))
            {
                target[j] = pop(st);
                j++;
            }
            if (top == -1)
            {
                printf("\nINCORRECT EXPRESSION");
                exit(1);
            }
            temp = pop(st);
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%') {
            while ((top != -1) && (st[top] != '(') && (getPriority(st[top]) > getPriority(source[i]))) {
                target[j] = pop(st);
                j++;
            }
            push(st, source[i]);
            i++;
        }
        else {
            printf("\nINCORRECT ELEMENT IN EXPRESSION");
            exit(1);
        }
    }
    while ((top != -1) && (st[top] != '(')) {
        target[j] = pop(st);
        j++;
    }
    target[j] = '\0';
}
int getPriority (char op) {
    if (op == '/' || op == '*' || op =='%') {
        return 1;
    }
    else if (op == '+' || op == '-') {
        return 0;
    }
}
void push(char st[], char val) {
    if (top == MAX-1) {
        printf("\nSTACK OVERFLOW");
        return;
    }
    top++;
    st[top] = val;
}
char pop(char st[]) {
    if (top == -1) {
        printf("\nSTACK UNDEFLOW");
        return ' ';
    }
    char val = st[top];
    top--;
    return val;
}