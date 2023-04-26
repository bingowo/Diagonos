#include<stdio.h>

typedef struct PEOPLE
{
    int acnt;
    int pcnt;
} PEOPLE;

int main()
{
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    PEOPLE now[n],on[n];
    now[1].acnt=1;now[1].pcnt=0;
    now[2].acnt=1;now[2].pcnt=0;
    on[1].acnt=1;on[1].pcnt=0;
    on[2].acnt=0;on[2].pcnt=1;
    for(int i=3;i<n;i++)
    {
        on[i].acnt=on[i-1].acnt+on[i-2].acnt;
        on[i].pcnt=on[i-1].pcnt+on[i-2].pcnt;
        now[i].acnt=now[i-1].acnt+on[i-2].acnt;
        now[i].pcnt=now[i-1].pcnt+on[i-2].pcnt;
    }
    int p=(m-now[n-1].acnt*a)/now[n-1].pcnt;
    printf("%d",now[x].acnt*a+now[x].pcnt*p);
}