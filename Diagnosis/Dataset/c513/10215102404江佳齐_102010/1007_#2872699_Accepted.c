#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    long long int n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld",&n);
        int a=n%2,b;
        int temp=1,sum=1;
        while(n)
        {
            n=n>>1;
            b=n%2;
            if(a!=b) temp++;
            else
            {
                if(temp>sum) sum=temp;
                temp=1;
            }
            a=b;
        }
        if (temp>sum) sum=--temp;
        printf("case #%d:\n",i);
        printf("%d\n",sum);
    }
    return 0;
}
