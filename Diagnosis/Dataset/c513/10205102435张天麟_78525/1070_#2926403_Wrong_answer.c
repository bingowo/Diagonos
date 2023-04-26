#include<stdio.h>
typedef struct
{
    int f1s1;
    int f0s1;
    int f1s0;
    int f0s0;
}s;
int main()
{
    s ans[20];
    int lenth,i,num;
    ans[0].f1s1=1;
    ans[0].f0s1=1;
    ans[0].f1s0=0;
    ans[0].f0s0=0;
    for(i=1;i<20;i++)
    {
        ans[i].f1s1=ans[i-1].f1s1+ans[i-1].f1s0;
        ans[i].f0s1=ans[i-1].f1s1+ans[i-1].f1s0;
        ans[i].f1s0=ans[i-1].f0s0;
        ans[i].f0s0=ans[i-1].f0s1+ans[i-1].f0s0;
    }
    scanf("%d",&lenth);
    while(lenth!=-1)
    {
        num=ans[lenth].f1s1+ans[lenth].f0s1+ans[lenth].f1s0+ans[lenth].f0s0;
        printf("%d\n",num);
        scanf("%d",&lenth);
    }
    return 0;
}