#include <stdio.h>
#include <stdlib.h>

char alpha[] = "0123456789ABCDEFGHIJKLMN";

typedef struct {
    int data[1000];
    int top;
} Stack;

void stack_init(Stack *s) {
    s->top = -1;
}

int stack_empty(Stack *s) {
    return s->top == -1;
}

void stack_push(Stack *s, int x) {
    s->top++;
    s->data[s->top] = x;
}

int stack_top(Stack *s) {
    return s->data[s->top];
}

void stack_pop(Stack *s) {
    s->top--;
}

int main()
{
    int num;
    int base;
    Stack store;
    stack_init(&store);
    scanf("%d%d",&num,&base);
    if(!num)
    {
        printf("0\n");
        return 0;
    }
    while(num)
    {
        int temp = num % base;
        num /= base;
        if(temp < 0)
        {
            temp -= base;
            num++;
        }
        stack_push(&store,temp);
    }

    while(!stack_empty(&store))
    {
        int temp = stack_top(&store);
        stack_pop(&store);
        printf("%c",alpha[temp]);
    }
    printf("\n");
    return 0;
}
