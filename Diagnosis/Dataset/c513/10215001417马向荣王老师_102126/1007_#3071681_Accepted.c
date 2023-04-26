#include<stdio.h>
int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        long long n=0;
        scanf("%lld\n",&n);
        printf("case #%d:\n",i);
        int fi=n%2,mod=0,count=1,number=1;
        while(n)
        {
            n/=2;
            mod=n%2;
            if(fi!=mod) number++;
            else
            {
                if(count<number) count=number;
                number=1;
            }
            fi=mod;
        }
        if(count<number) count=number-1;
        printf("%lld\n",count);
    }
    return 0;
}