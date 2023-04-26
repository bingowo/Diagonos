#include <stdio.h>

int main()
{
    int T,n,sum;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        while(n!=0)
        {
            sum=sum*10+n%2233;
            n/=2233;
        }
        printf("%d",sum);
    }
    return 0;
}
