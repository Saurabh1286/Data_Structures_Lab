//Program to evaluate Postfix Expression.
//Include header files
#include <stdio.h>
#include <ctype.h>
#define MAX 100
//Global declarations
float st[MAX];
int top = -1;
//Function Declarations
void push(float st[], float val);
float pop(float st[]);
float evaluatePostfixExp(char exp[]);
//Main method to write Menu
int main() {
    float val;
    char exp[100];
    printf("\nEnter any postfix expression : ");
    gets(exp);
    val = evaluatePostfixExp(exp);
    printf("\nValue of Postfix expression = %.2f", val);
    return 0;
}
//Function Definitions
float evaluatePostfixExp(char exp[]) {
    int i = 0;
    float op1, op2, value;
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push (st, (float) (exp[i] - '0'));
        }
        else {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i]) {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '/':
                value = op1 / op2;
                break;
            case '%':
                value = (int)op1 % (int)op2;
                break;
            }
            push(st, value);
        }
        i++;
    }
    return (pop(st));
}
void push (float st[], float val) {
    if (top == MAX - 1) {
        printf("\nSTACK OVERFLOW");
        return;
    }
    top++;
    st[top] = val;
}
float pop (float st[]) {
    if (top == -1) {
        printf("\nSTACK UNDERFLOW");
        return -1;
    }
    float val = st[top];
    top--;
    return val;
}