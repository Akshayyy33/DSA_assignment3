#include <stdio.h>
char stack[100];
int top = -1;
void push(char x) {
    stack[++top] = x;
}
char pop() {
    return stack[top--];
}
int priority(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}
int isOperand(char ch) {
    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= '0' && ch <= '9'))
        return 1;
    return 0;
}
int main() {
    char infix[100], postfix[100];
    int k = 0;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isOperand(infix[i]))
            postfix[k++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop(); 
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(infix[i]))
                postfix[k++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1)
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("Postfix: %s\n", postfix);
    return 0;
}
