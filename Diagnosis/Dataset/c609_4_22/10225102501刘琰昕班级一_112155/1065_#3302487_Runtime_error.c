#include <stdio.h>
#include <stdlib.h>
#define Max 101

typedef struct
{
    char* val[Max];
    int top;
}stack;

void init(stack* s)
{
    s->top=-1;
}
int empty(stack* s)
{
    if(s->top==-1)return 1;
    else return 0;
}
void push(char* a,stack* s)
{
    (s->val)[++(s->top)]=(char *)malloc(strlen(a)*sizeof(char)+1);
    strcpy((s->val)[(s->top)],a);
}
void pop(stack* s)
{
    free((s->val)[(s->top)--]);
}
char* top(stack* s)
{
    return (s->val)[s->top];
}

int main()
{
    int T;scanf("%d",&T);
    char digit[Max];
    for(int i=0;i<T;i++)
    {
        stack s;init(&s);
        double ans=0;
        while(1)
        {
            scanf("%s",digit);
            if(digit[0]=='+'||digit[0]=='-'||digit[0]=='*'||digit[0]=='/')
                push(digit,&s);
            else if(top(&s)[0]=='+'||top(&s)[0]=='-'||top(&s)[0]=='*'||top(&s)[0]=='/')
                push(digit,&s);
            else
            {
                double n1=atof(digit);
                double n2=atof(top(&s));pop(&s);
                char opt=(top(&s))[0];pop(&s);
                if(opt=='+')ans=n2+n1;
                else if(opt=='-')ans=n2-n1;
                else if(opt=='*')ans=n2*n1;
                else if(opt=='/')ans=n2/n1;
                if(empty(&s))break;
                else push(gcvt(ans,101,digit),&s);
            }
        }
        printf("case #%d:\n%lf\n",i,ans);
    }
    return 0;
}
