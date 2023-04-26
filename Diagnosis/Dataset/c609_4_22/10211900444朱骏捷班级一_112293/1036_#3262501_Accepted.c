#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
    STDataType *data;
    int top;      // 已有的数据个数
    int capacity; // 容量
} ST;

void StackInit(ST *ps)
{
    assert(ps);
    ps->data = NULL;
    ps->capacity = ps->top = 0;
}
void StackDestory(ST *ps)
{
    assert(ps);
    free(ps->data);
    ps->data = NULL;
    ps->capacity = ps->top = 0;
}
void StackPush(ST *ps, STDataType x)
{
    assert(ps);
    if (ps->capacity == ps->top)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;

        STDataType *temp = (STDataType *)realloc(ps->data, newcapacity * sizeof(STDataType));
        if (temp == NULL)
        {
            printf("realloc fail!\n");
            exit(-1);
        }
        ps->data = temp;
        ps->capacity = newcapacity;
    }
    ps->data[ps->top] = x;
    ps->top++;
}
void StackPop(ST *ps)
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}
int StackEmpty(ST *ps)
{
    assert(ps);
    if (ps->top == 0)
    {
        return 1;
    }
    else
        return 0;
}
STDataType StackTop(ST *ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    return ps->data[ps->top - 1];
}
int StackSize(ST *ps)
{
    assert(ps);
    return ps->top;
}

int main()
{
    char S[60];
    gets(S);
    printf("%d\n", scoreOfParentheses(S));
    return 0;
}

int scoreOfParentheses(char *S)
{
    ST s;
    StackInit(&s);
    int len = strlen(S);
    for (int i = 0; i < len; i++)
    {
        if (S[i] == '(')
        {
            StackPush(&s, 0);
        }
        else
        {
            int score = 0;
            while (StackTop(&s) != 0)
            {
                score += StackTop(&s);
                StackPop(&s);
            }
            StackPop(&s);
            int newScore = score == 0 ? 1 : score * 2;
            StackPush(&s, newScore);
        }
    }
    int totalScore = 0;
    while (!StackEmpty(&s))
    {
        totalScore += StackTop(&s);
        StackPop(&s);
    }
    return totalScore;
}