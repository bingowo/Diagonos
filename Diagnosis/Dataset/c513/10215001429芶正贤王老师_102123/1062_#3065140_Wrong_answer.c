#include<stdio.h>
int f(int n)
{
    int a=1,b=2,c=3,d=4,t;
    for(int i=0;i<n+1;i++)
    {
        t=a+b+c+d;
        a=b;
        b=c;
        c=d;
        d=t;
    }
    return t;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%d\n",f(n));
    }
    return 0;
    
}
