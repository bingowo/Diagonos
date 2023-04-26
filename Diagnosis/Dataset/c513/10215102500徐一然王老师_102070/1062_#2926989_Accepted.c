#include <stdio.h>

long long int A[100]={1,2,4,8};

long long int F(int a)
{
    if(A[a-1]!=0)
        return A[a-1];
    if(a==1)
        return 1;
    else if(a==2)
        return 2;
    else if(a==3)
        return 4;
    else if(a==4)
        return 8;
    else
    {
        return A[a-1]=F(a-1)+F(a-2)+F(a-3)+F(a-4);
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
