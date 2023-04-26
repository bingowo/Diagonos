#include <stdio.h>
#include <stdlib.h>

long long combination(int m,int n)
{
    long long a=1,b=1,result=1;
    if (n==0) result=0;
    else
    {
         for (int i=0;i<n;i++)
        {
            result=result*(m-i)/(i+1);
        }
    }

    return result;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int m,n;
        scanf("%d %d",&m,&n);
        printf("%lld\n",combination(m,n));
    }
    return 0;
}
