#include<stdio.h>
int f(int n)
{
    int a,b;
    a = n/4;
    b = n%4;
    if(n == 1)
        return 1;
    else if(n == 2)
        return f(1)+1;
    else if(n == 3)
        return f(2)+1;
    else if(n == 4)
        return f(3)+1;
    else
        return f(n-1)+f(n-2)+f(n-3)+f(n-4);
    
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
