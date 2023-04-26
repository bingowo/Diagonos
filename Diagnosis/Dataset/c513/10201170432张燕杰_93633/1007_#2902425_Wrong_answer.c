#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        long long int n;
        scanf("%lld\n",&n);
        long long int Flag=n%2;
        long long int sum=1;
        long long int max=1;
        long long int flag;
        n = n/2;
        while(n/2!=0)
        {
            flag = n%2;
            if(Flag !=flag)
            {
                sum = sum+1;
                Flag = flag;
                n = n/2;
                continue;
            }
            else{
                if(sum>max)
                {
                    max = sum;
                }
                sum = 1;
                n = n/2;
                continue;
            }

        }
        printf("case #%lld:\n%lld\n",i,max);
    }
    return 0;
}
