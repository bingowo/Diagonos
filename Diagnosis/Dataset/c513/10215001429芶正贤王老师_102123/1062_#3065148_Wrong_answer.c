#include<stdio.h>
long long int f(long long int n)
{
    long long int a=1,b=2,c=4,d=8,t;
    for(long long int i=5;i<n+1;i++)
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
        if(n == 1)
            printf("1\n");
        else if(n == 2)
            printf("2\n");
        else if(n == 3)
            printf("4\n");
        else if(n == 4)
            printf("8\n");
        else
            printf("%d\n",f(n));
        
    }
    return 0;
    
}
