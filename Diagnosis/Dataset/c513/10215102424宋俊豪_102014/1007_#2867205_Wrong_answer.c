#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
    int n,max1,max;
    max=1;max1=1;
    long long a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       max=1;max1=1;
        scanf("%lld",&a);
        while(a>0)
        {
           b=a;
        while(b>1)
        {
            if ((b&1)!=((b>>1)&1))
            {
                max1++;
            }
            else
            {
                  break;
            }
            b=b>>1;
        }
          if (max1>max)
                  max=max1;
          max1=1;
        a=a>>1;
        }
        printf("case #%d\n:",i);
        printf("%d\n",max);
    }
    return 0;
}
