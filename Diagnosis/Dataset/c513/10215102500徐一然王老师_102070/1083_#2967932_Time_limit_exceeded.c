#include <stdio.h>

int mult_n(int n)
{
    long long int x=1;
    int j=1,count=0;
    while(n--)
    {
        x=x*j;
        j++;
        while(x%10==0)
        {
            count++;
            x=x/10;
        }
    }
    return count;
}

int main()
{
    int count,count1,n;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        scanf("%d",&n);
        printf("case #%d:\n",count1-count-1);
        printf("%d\n",mult_n(n));
    }
}
