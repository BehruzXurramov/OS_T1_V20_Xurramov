#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

Stack *create_stack(int capacity) {
    if (capacity <= 0) return NULL;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) return NULL;

    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char *)malloc(stack->capacity * sizeof(char));
    if (stack->data == NULL) {
        free(stack);
        return NULL;
    }
    return stack;
}

void push(Stack *stack, char item) {
    if (stack->top < stack->capacity - 1) {
        stack->top++;
        stack->data[stack->top] = item;
    }
}

char pop(Stack *stack) {
    if (stack->top == -1) return '\0';
    char item = stack->data[stack->top];
    stack->top--;
    return item;
}

void free_stack(Stack *stack) {
    if (stack != NULL) {
        free(stack->data);
        free(stack);
    }
}

int is_matching_pair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return 1;
    if (char1 == '[' && char2 == ']') return 1;
    if (char1 == '{' && char2 == '}') return 1;
    return 0;
}

int check_balance(const char *expr) {
    int len = strlen(expr);
    if (len == 0) return 1;

    Stack *stack = create_stack(len);
    if (stack == NULL) {
        printf("Xato: Xotira ajratishda xatolik yuz berdi!\n");
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            push(stack, expr[i]);
        } else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if (stack->top == -1) {
                free_stack(stack);
                return 0;
            }
            char top_char = pop(stack);
            if (!is_matching_pair(top_char, expr[i])) {
                free_stack(stack);
                return 0;
            }
        }
    }

    int is_balanced = (stack->top == -1);
    free_stack(stack);
    return is_balanced;
}

int main() {
    char buffer[256];
    printf("Qavslar balansini tekshirish uchun ifodani kiriting: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';

        if (check_balance(buffer)) {
            printf("Natija: Qavslar balansi to'g'ri (BALANSLANGAN)!\n");
        } else {
            printf("Natija: Qavslar balansi buzilgan (UNBALANCED)!\n");
        }
    }
    return 0;
}
