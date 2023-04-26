#include <stdio.h>
#include <string.h>

long long int A[100]={0,1,1};

long long int F(int x)
{
    if(A[x]!=0)
    {
        return A[x];
    }
    if(x==0)
    {
        return 0;
    }
    else if(x==1)
    {
        return 1;
    }
    else if(x==2)
    {
        return 1;
    }
    else
    {
        return A[x]=F(x-1)+F(x-2)+F(x-3);
    }
}

int main()
{
    int count,count1,x;
    scanf("%d\n",&count);
    count1=count;
    while(count--)
    {
        scanf("%d",&x);
        printf("case #%d:\n",count1-count-1);
        printf("%lld\n",F(x));
    }
}
