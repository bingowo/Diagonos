#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_EXPRESSION_LENGTH 100

typedef struct {
    double value;
    bool is_operator;
} Token;

typedef struct StackNode {
    Token token;
    struct StackNode *next;
} StackNode;

StackNode *createStack() {
    return NULL;
}

bool isEmpty(StackNode *stack) {
    return stack == NULL;
}

void push(StackNode **stack, Token token) {
    StackNode *new_node = (StackNode *) malloc(sizeof(StackNode));
    new_node->token = token;
    new_node->next = *stack;
    *stack = new_node;
}

Token pop(StackNode **stack) {
    if (isEmpty(*stack)) {
        Token empty_token = {0, false};
        return empty_token;
    }
    StackNode *top_node = *stack;
    Token top_token = top_node->token;
    *stack = top_node->next;
    free(top_node);
    return top_token;
}

Token peek(StackNode *stack) {
    if (isEmpty(stack)) {
        Token empty_token = {0, false};
        return empty_token;
    }
    return stack->token;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isNumber(char c) {
    return isdigit(c) || c == '.';
}

double evaluateExpression(char *expression) {
    StackNode *stack = createStack();
    int len = strlen(expression);
    for (int i = 0; i < len; i++) {
        if (isOperator(expression[i])) {
            Token token = {0, true};
            push(&stack, token);
            Token operand_2 = pop(&stack);
            Token operand_1 = pop(&stack);
            if (!operand_1.is_operator && !operand_2.is_operator) {
                double result;
                switch (expression[i]) {
                    case '+':
                        result = operand_1.value + operand_2.value;
                        break;
                    case '-':
                        result = operand_1.value - operand_2.value;
                        break;
                    case '*':
                        result = operand_1.value * operand_2.value;
                        break;
                    case '/':
                        result = operand_1.value / operand_2.value;
                        break;
                    default:
                        break;
                }
                Token result_token = {result, false};
                push(&stack, result_token);
            } else {
                Token empty_token = {0, false};
                push(&stack, empty_token);
            }
        } else if (isNumber(expression[i])) {
            char *end;
            double number = strtod(expression + i, &end);
            Token number_token = {number, false};
            push(&stack, number_token);
            i = end - expression - 1;
        }
    }
    Token result_token = pop(&stack);
    return result_token.value;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int case_num = 0; case_num < t; case_num++) {
        char expression[MAX_EXPRESSION_LENGTH];
        scanf(" %[^\n]", expression);
        double result = evaluateExpression(expression);
        printf("case #%d: %.6f\n", case_num, result);
    }
    return 0;
}
