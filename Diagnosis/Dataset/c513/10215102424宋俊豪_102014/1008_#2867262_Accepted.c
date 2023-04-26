#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
    int n,a,b,sum;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        sum=0;
        scanf("%d%d",&a,&b);
        while((a>0)||(b>0))
        {
            if((a&1)!=(b&1))
                sum++;
            a=a>>1;
            b=b>>1;

        }
        printf("%d\n",sum);
    }
    return 0;
}

