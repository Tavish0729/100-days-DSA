#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Structure for a stack node using linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory Error\n");
        return;
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! (Check if expression is valid)\n");
        return 0;
    }
    struct Node* temp = *top;
    int poppedVal = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedVal;
}

// Function to evaluate the postfix expression
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i]; ++i) {
        // Skip spaces and newline characters
        if (exp[i] == ' ' || exp[i] == '\n') continue;

        // If the character is an operand (digit)
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--; 
            push(&stack, num);
        }
        // If the character is an operator
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);

            switch (exp[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': 
                    if(val1 == 0) { printf("Error: Division by zero\n"); return 0; }
                    push(&stack, val2 / val1); 
                    break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char exp[100]; // Buffer to store user input

    printf("Enter a postfix expression (e.g., 2 3 1 * + 9 -): \n");
    
    // fgets reads the whole line including spaces
    if (fgets(exp, sizeof(exp), stdin)) {
        int result = evaluatePostfix(exp);
        printf("Output: %d\n", result);
    }

    return 0;
}
