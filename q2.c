#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push() {
    int x;
    printf("Enter element: ");
    scanf("%d", &x);

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop() {
    if (top == NULL)
        printf("Stack Underflow\n");
    else {
        struct node* temp = top;
        printf("Popped: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display() {
    struct node* temp = top;
    if (temp == NULL) {
        printf("Stack empty\n");
        return;
    }
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
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
        }   }
}
