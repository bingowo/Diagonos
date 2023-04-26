#include<stdio.h>

void solve(int a,int n);

int main()
{
    int t;
    int i;
    int a,n;

    scanf("%d",&t);

    for (i=0;i<t;i++)
    {
        scanf("%d %d",&a,&n);
        
        printf("case #%d:\n",i);
        solve(a,n);

    }

    return 0;
}


void solve(int a,int n)
{
    int i=0;
    int num=0;
    int bigint[100]={1,0};
    int r=0,c=0;
    int t=0;

    while (i < n)
    {
        t=c+bigint[num]*a;
        c=t/10;
        r=t%10;

        if (c>0)
        {
            bigint[num++]=r;
        }

        i++;
    }

    for (i=num-1;i>=0;i++)
    {
        printf("%d",bigint[i]);
    }
    putchar('\n');

    return;
}