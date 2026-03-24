#include <stdio.h>
#include <string.h>
char stack[100];
int top = -1;
void push(char x) {
    stack[++top] = x;
}
char pop() {
    return stack[top--];
}
int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
        push(str[i]);
    printf("Reversed string: ");
    while (top != -1)
        printf("%c", pop());
    return 0;
}
