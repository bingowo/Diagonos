#include <stdlib.h>
#include <stdio.h>

unsigned long long int f(int a,int b)
{
    if(a == b)
        return a;
    else 
        return f(a - 1,b) * a;
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
        unsigned long long int output = f(m,m - n + 1)/f(n,1);
        printf("case #%d:\n%llu\n",i,output);
    }
}