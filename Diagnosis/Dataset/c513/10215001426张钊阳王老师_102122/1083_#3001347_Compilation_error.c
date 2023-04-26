】#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        int n;
        int sum=0,cnt22=0,cnt55=0;
        scanf("%d",&n);

        for(int j=1;j<=n;j++)
        {
            cnt22+=cnt2(j);
            cnt55+=cnt5(j);
        }

        sum+=(cnt22>=cnt55)?cnt55:cnt22;

        printf("case #%d:\n",z);

        printf("%d",sum);

        printf("\n");
    }
    return 0;
}


int cnt2(int n)
{
    int sum=0;
        while(n%2==0)
        {
            sum++;
            n/=2;
        }
    return sum;
}


int cnt5(int n)
{
    int sum=0;

        while(n%5==0)
        {
            sum++;
            n/=5;
        }
    return sum;
}
