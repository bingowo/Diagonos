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
        if(n==1)
        {
            printf("case #%lld:\n%lld\n",i,1);
        }
        n = n/2;
        do
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

        }while(n/2!=0);
        if(Flag==0)sum++;
        if(sum>max)
        {
            max =sum;
        }
        printf("case #%lld:\n%lld\n",i,max);
    }
    return 0;
}