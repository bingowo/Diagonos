#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//对stack的实现
#define STACK_SIZE 100
typedef struct{int top;int data[STACK_SIZE];}Stack;
void init(Stack *s){s->top = -1;}
int is_empty(Stack *s) {return s->top == -1;}
int is_full(Stack *s) {return s->top == STACK_SIZE - 1;}
void push(Stack *s, int value)
{if (is_full(s)) {printf("Stack overflow\n");exit(1);}s->data[++s->top] = value;}
int pop(Stack *s)
{if (is_empty(s)) {printf("Stack underflow\n");exit(1);}return s->data[s->top--];}
int top(Stack *s)
{if (is_empty(s)) {printf("Stack is empty\n");exit(1);}return s->data[s->top];}

int main()
{
    char c;
    Stack stack;
    init(&stack);
    while((c=getchar())!='\n')
    {
        if(c=='(')
           push(&stack,-1);
        else if(c==')')
        {

            if(top(&stack)==-1)
            {
                pop(&stack);
                push(&stack,1);
            }
            else
            {
                int temp=0;
                while(top(&stack)!=-1)
                    temp+=pop(&stack);
                pop(&stack);
                push(&stack,2*temp);
            }
        }
    }
    int ans=0;
    while(!is_empty(&stack))
        ans+=pop(&stack);
    printf("%d",ans);
    return 0;
}
