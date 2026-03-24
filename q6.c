#include <stdio.h>
int stack[100], top = -1;
void push(int x) {
    stack[++top] = x;
}
int pop() {
    return stack[top--];
}
int isDigit(char ch) {
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}
int main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isDigit(postfix[i]))
            push(postfix[i] - '0');
        else {
            int val2 = pop();
            int val1 = pop();
            switch (postfix[i]) {
                case '+':
                 push(val1 + val2);
                 break;
                case '-':
                 push(val1 - val2); 
                 break;
                case '*':
                 push(val1 * val2); 
                 break;
                case '/':
                 push(val1 / val2); 
                 break;
            }
        }
    }
    printf("Result = %d\n", pop());
    return 0;
}
