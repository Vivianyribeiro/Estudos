#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
}

bool isStackEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        return '\0'; // Retorna caractere nulo para indicar pilha vazia
    }

    Node* temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

char peek(Stack* stack) {
    if (isStackEmpty(stack)) {
        return '\0'; // Retorna caractere nulo para indicar pilha vazia
    }
    return stack->top->data;
}

bool isBalanced(const char* expression) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];
        if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            char top = peek(&stack);
            if (top == '(') {
                pop(&stack);
            } else {
                return false;
            }
        }
    }

    return isStackEmpty(&stack); // Verifica se a pilha está vazia no final
}

int main() {
    char expression[1001];
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("Correta\n");
    } else {
        printf("Incorreta\n");
    }

    return 0;
}
