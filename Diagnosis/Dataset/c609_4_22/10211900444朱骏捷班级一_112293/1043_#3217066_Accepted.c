#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#define N 10

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
bool StackEmpty(ST *ps)
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
    int t;
    scanf("%d", &t);
    getchar();
    for (int z = 0; z < t; z++)
    {
        ST s;
        StackInit(&s);
        char str[110];
        gets(str);
        int len = strlen(str);
        int flag = true;

        for (int i = 0; i < len; i++)
        {
            if (StackEmpty(&s))
            {

                StackPush(&s, str[i]);
                continue;
            }

            switch (str[i])
            {
            case '(':
                if (StackTop(&s) == '[')
                {
                    StackPush(&s, str[i]);
                }
                else
                {
                    flag = false;
                    goto FLAG;
                }
                break;

            case ')':
                if (StackTop(&s) == '(')
                {
                    StackPop(&s);
                }
                else
                {
                    flag = false;
                    goto FLAG;
                }
                break;

            case '[':
                if (StackTop(&s) == '{')
                {
                    StackPush(&s, str[i]);
                }
                else
                {
                    flag = false;
                    goto FLAG;
                }
                break;

            case ']':
                if (StackTop(&s) == '[')
                {
                    StackPop(&s);
                }
                else
                {
                    flag = false;
                    goto FLAG;
                }
                break;

            case '{':
                if (StackTop(&s) == '(')
                {
                    StackPush(&s, str[i]);
                }
                else
                {
                    flag = false;
                    goto FLAG;
                }
                break;

            case '}':
                if (StackTop(&s) == '{')
                {
                    StackPop(&s);
                }
                else
                {
                    flag = false;
                    goto FLAG;
                }
                break;
            }
        }

    FLAG:
        if (flag && StackEmpty(&s))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}