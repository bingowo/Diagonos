#include <stdio.h>
#include <string.h>

int is_valid(char *input_str) {
    if (strlen(input_str) % 2)
        return 0;
    char stack[101] = {0};
    int stack_top = 0;
    for (int i = 0; input_str[i] != '\0'; ++i) {
        if (input_str[i] == '{') {
            if (stack_top > 0 && stack[stack_top-1] != '(') {
                return 0;
            }
            stack[stack_top++] = input_str[i];
        } else if (input_str[i] == '[') {
            if (stack_top > 0 && stack[stack_top-1] != '{') {
                return 0;
            }
            stack[stack_top++] = input_str[i];
        } else if (input_str[i] == '(') {
            if (stack_top > 0 && stack[stack_top-1] != '[') {
                return 0;
            }
            stack[stack_top++] = input_str[i];
        } else if (input_str[i] == '}') {
            if (stack_top == 0 || stack[stack_top-1] != '{') {
                return 0;
            }
            stack[stack_top--] = 0;
        } else if (input_str[i] == ']') {
            if (stack_top == 0 || stack[stack_top-1] != '[') {
                return 0;
            }
            stack[stack_top--] = 0;
        } else if (input_str[i] == ')') {
            if (stack_top == 0 || stack[stack_top-1] != '(') {
                return 0;
            }
            stack[stack_top--] = 0;
        } else {
            return 0;
        }
        //printf("%s\n", stack);
    }
    return (stack_top == 0);
}

int main(int argc, char **argv) {
    char input[101] = {0};
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s", input);
        int res = is_valid(input);
        printf("%s\n", (res ? "Yes" : "No"));
    }
    return 0;
}