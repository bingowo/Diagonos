#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int a,b,n;
        scanf("%d%d%d",&a,&b,&n);
        printf("case #%d:\n",i);
        long long r=1;
        for(int j=0;j<b;j++)
        {
            r=r*a%(int)(pow(10,n));
        }
        int num=0;
        long long int sum=r;
        do
        {
            sum=sum/10;
            num++;
        } while(sum>0);
        if(num!=n)
        {
            for(int p=0;p<n-num;p++)
            {
                printf("%d",0);
            }
        }
        printf("%lld\n",r);
    }
    return 0;
}