//poland.c
#include <stdio.h>
#include <string.h>
#define INPUT argv[1]
struct STACK{
    float s[BUFSIZ];
    int sp;
};
typedef struct STACK STACK;
STACK s;
#define push(x) (s.s[s.sp++] = x)
#define pop() (s.s[--s.sp])
float calc(char op){
    float p1 = pop();
    float p2 = pop();
    printf("pop: %f\npop: %f\ncase: %c\n", p1, p2, op);
    switch(op){
        case '+': return p1 + p2; break;
        case '-': return p1 - p2; break;
        case '*': return p1 * p2; break;
        case '/': return p1 / p2; break;
        default: return 0; break;
    }
}
#define isop(x) (x == '+' || x == '-' || x == '*' || x == '/')
int main(int argc, char **argv){
    float num = 0.;
    for(int i = strlen(INPUT) - 1; i >= 0; i--){
        if(INPUT[i] == ' ' || !i){
            if(isop(INPUT[i?i + 1:0])) push(calc(INPUT[i?i + 1:0]));
            else{
                sscanf(INPUT + (i?i + 1:0), "%f", &num);
                printf("push: %f\n", num);
                push(num);
            }
        }
    }
    printf("%f\n", pop());
    return 0;
}