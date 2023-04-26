#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,k,temp;
    long long a;
    int r;
    long long sum;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
         char b[100];
        printf("case #%d:\n",i);
        scanf("%lld%d",&a,&r);
        sum=0;
        while(a)
        {
            sum+=a%r;
            a/=r;
        }

        for(k=0;sum;k++)
        {
         temp=sum%r;
         sum/=r;
         if(temp>=10) b[k]='A'+temp-10;
         else b[k]='0'+temp;
        }
        for(k--;k>=0;k--)
        printf("%c",b[k]);
        printf("\n");

    }

}