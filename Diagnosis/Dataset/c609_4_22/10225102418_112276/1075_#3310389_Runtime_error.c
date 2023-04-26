// We will use a stack to simulate the operations.
// We will iterate through each state and compare it with the previous state.
// For each element in the current state, we will check if it is already in the stack.
// If it is, we will pop elements from the stack until we reach the element.
// If it is not, we will push elements onto the stack until we reach the element.
// The number of operations required will be the number of elements popped and pushed.
// We will add up the number of operations for each state transition to get the total number of operations.

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int stack[MAX_N];
    int top = -1;
    int operations = 0;

    for (int i = 0; i < m; i++) {
        int state[MAX_N];
        for (int j = 0; j < n; j++) {
            scanf("%d", &state[j]);
        }

        for (int j = 0; j < n; j++) {
            if (state[j] > stack[top]) {
                for (int k = stack[top] + 1; k <= state[j]; k++) {
                    stack[++top] = k;
                    operations++;
                }
            } else {
                while (stack[top] != state[j]) {
                    top--;
                    operations++;
                }
            }
            top--;
            operations++;
        }
    }

    printf("%d\n", operations);

    return 0;
}