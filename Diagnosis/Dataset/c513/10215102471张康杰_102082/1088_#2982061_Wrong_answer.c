#include <stdlib.h>
#include <stdio.h>

unsigned long long int f(int a,int b)
{
    if(b == 0)
        return a;
    else if(a == 2*b)
        return f(a - 1,b - 1) * 2;
    else 
        return f(a - 1,b - 1) * a;
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        if(n >= m/2)
            n = m - n;
        if(n == 0)
        {
            printf("case #%d:\n1\n",i);
            continue;           
        }
        unsigned long long int output = f(m,n);
        printf("case #%d:\n%llu\n",i,output);
    }
}