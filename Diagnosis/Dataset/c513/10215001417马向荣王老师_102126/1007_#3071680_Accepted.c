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
        int mod=0,fi=n%2,number=1,count=1;
        while(n!=0)
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
        if(count<number) count=--number;
        printf("%lld\n",count);
    }
    return 0;
}