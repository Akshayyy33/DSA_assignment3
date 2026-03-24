#include <stdio.h>
#define MAX 5
int stack[MAX], top = -1;
void push() {
    int x;
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else {
        printf("Enter element: ");
        scanf("%d", &x);
        stack[++top] = x;
    }
}
void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped element: %d\n", stack[top--]);
}
void display() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
             push();
             break;
            case 2:
             pop();
             break;
            case 3:
             display();
             break;
            case 4:
             return 0;
            default:
             printf("Invalid choice\n");
        }
    }
}
